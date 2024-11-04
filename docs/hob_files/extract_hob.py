#!/usr/bin/env python3

import os
import sys
import struct
from pprint import pformat, pp

be16toh = struct.Struct(">H").unpack
be32toh = struct.Struct(">I").unpack
vertex_unpack = struct.Struct(">hhhh").iter_unpack
indice_unpack = struct.Struct(">HHHH").unpack

extra_verts_bit  = 6
color_bit        = 5
vertex_color_bit = 4
quad_bit         = 3
uv_bit           = 2
extra_verts_bit2 = 1 # wtf is up with this?
unknown_bit0     = 0

extra_verts_mask  = 1 << extra_verts_bit
color_mask        = 1 << color_bit
vertex_color_mask = 1 << vertex_color_bit
quad_mask         = 1 << quad_bit
uv_mask           = 1 << uv_bit
extra_verts_mask2 = 1 << extra_verts_bit2

class face:
	def __init__(self, hob, face_idx):
		self.face_idx = face_idx
		(self.flags, ) = be32toh(hob.read(4))
		# Flags
		# abcd efgh ijkl mnop
		# a-i are unknown, a-h(i?) appear to never be set
		# j: if one there's a secondary set of vertices
		self.has_secondary_vertices = self.flags & (extra_verts_mask | extra_verts_mask2)
		# k: if 1 face has some color associated with it
		self.has_color = self.flags & color_mask
		# l: Only matters if k= 1, if 1 face has vertex colors otherwise has a single face color?
		self.vertex_color = self.flags & vertex_color_mask
		# m: if 1 face is a quad, otherwise its a tri
		self.is_quad = self.flags & quad_mask
		# n: if 1 face has UV coordinates
		self.has_uv = self.flags & uv_mask
		# o unknown, seems to be another indicator of secondary indices? Only used in the player craft hobs?
		# p unknown, never set?
		
		(self.unknown, ) = be32toh(hob.read(4))
		(self.material_index, ) = be16toh(hob.read(2))
		hob.seek(2, os.SEEK_CUR)

		self.primary_vertex_indices = None
		self.secondary_vertex_indices = None
		self.face_color = None
		self.vertex_colors = None
		self.texture_coordinates = None

		if self.is_quad:
			self.primary_vertex_indices = indice_unpack(hob.read(8))
		else:
				# Drop the last index, it should always by zero for tris
			self.primary_vertex_indices = indice_unpack(hob.read(8))[:3]

		if self.has_secondary_vertices:
			if self.is_quad:
				self.secondary_vertex_indices = indice_unpack(hob.read(8))
			else:
				# Drop the last index, it should always by zero for tris
				self.secondary_vertex_indices = indice_unpack(hob.read(8))[:3]

		if self.has_color:
			if self.vertex_color:
				if self.is_quad:
					self.vertex_colors = struct.unpack(">IIII", hob.read(16))
				else:
					self.vertex_colors = struct.unpack(">III", hob.read(12))
			else:
				(self.face_color, ) = be32toh(hob.read(4))

		if self.has_uv:
			if self.is_quad:
				self.texture_coordinates = tuple((x/4096, 1 - y/4096) for (x, y) in struct.iter_unpack(">hh", hob.read(16)))
			else:
				self.texture_coordinates = tuple((x/4096, 1 - y/4096) for (x, y) in struct.iter_unpack(">hh", hob.read(12)))

	def __repr__(self):
		return pformat(vars(self), indent = 2)

class face_group:
	def __init__(self, hob, offset):
		self.offset = offset
		hob.seek(offset)
		hob.seek(8, os.SEEK_CUR)
		(self.face_list_offset, ) = be32toh(hob.read(4))
		(self.face_count, ) = be32toh(hob.read(4))

		hob.seek(self.face_list_offset)
		self.face_list = [ face(hob, face_idx) for face_idx in range(self.face_count) ]

	def __repr__(self):
		return pformat(vars(self), indent = 2)

class meshdef1_entry:
	def __init__(self, hob, offset):
		self.offset = offset
		# This puts us past the face_group_end_offset(next_facegroup_offset?) of the meshdef1_entry, but that's fine we don't need it
		hob.seek(offset)
		hob.seek(20, os.SEEK_CUR)
		(self.primary_vertex_count, ) = be32toh(hob.read(4))
		# Sometimes (usually?) 0. We should expect a nonzero vertex_offset2 if this is non-zero
		# See the mempak HOB for an example of a nonzero entry
		(self.secondary_vertex_count, ) = be32toh(hob.read(4))
		hob.seek(4, os.SEEK_CUR)
		(self.face_group_offset, ) = be32toh(hob.read(4))
		(self.primary_vertex_offset, ) = be32toh(hob.read(4))
		# This is sometimes (usually?) 0. Exact use unknown, but relevant when parsing the faces
		# See the mempak HOB for an example of a nonzero entry
		(self.secondary_vertex_offset, ) = be32toh(hob.read(4))

		# 48 bytes of zeros...

		self.face_group = face_group(hob, self.face_group_offset)
		hob.seek(self.primary_vertex_offset)
		self.primary_vertices = list((x/1000, y/1000, z/1000) for (x, y, z, _) in vertex_unpack(hob.read(8 * self.primary_vertex_count)))
		if self.secondary_vertex_offset != 0:
			hob.seek(self.secondary_vertex_offset)
			self.secondary_vertices = list((x/1000, y/1000, z/1000) for (x, y, z, _) in vertex_unpack(hob.read(8 * self.secondary_vertex_count)))
		else:
			self.secondary_vertices = None

	def __repr__(self):
		return pformat(vars(self), indent = 2)

class object_entry:
	def __init__(self, hob, obj_offset):
		self.offset = obj_offset
		hob.seek(obj_offset)
		# ---- Object Entry ---- #
		(self.object_name, ) = struct.unpack(">16s", hob.read(16))
		self.object_name = bytes.decode(self.object_name).rstrip("\x00")
		(self.meshdef0_list_offset1, ) = be32toh(hob.read(4))
		(self.meshdef0_prelude_offset, ) = be32toh(hob.read(4))
		(self.meshdef1_prelude_offset1, ) = be32toh(hob.read(4))
		# Sometimes there's a value here, sometimes not.
		# Its not clear when or why its one way or the other
		# See the probe droid HOB file for an example of this being non-zero
		(self.meshdef1_prelude_offset2, ) = be32toh(hob.read(4))
		# We currently have no need for the rest of the data in the object entry

		# ---- meshdef0 prelude ---- #
		hob.seek(self.meshdef0_prelude_offset)

		(self.meshdef0_count, ) = be16toh(hob.read(2))
		(self.meshdef1_count, ) = be16toh(hob.read(2))
		self.mesdef0_offsets = [ struct.unpack(">II", hob.read(8)) for _ in range(self.meshdef0_count) ]

		# ---- meshdef1 prelude ---- #
		hob.seek(self.meshdef1_prelude_offset1)

		# We collected these values from the meshdef0 prelude, could sanity check here if we felt like it
		hob.seek(4, os.SEEK_CUR)
		# (self.meshdef0_count, ) = be16toh(hob.read(2))
		# (self.meshdef1_count, ) = be16toh(hob.read(2))

		# This is weird because I don't understand how the meshdef1_prelude stuff works
		self.meshdef1_offsets = list()
		offsets_found = 0
		while (offsets_found != self.meshdef1_count):
			(temp, ) = be32toh(hob.read(4))
			if temp != 0:
				self.meshdef1_offsets.append(temp)
				offsets_found += 1

		# There should be names for some (all?) the meshes after the meshdef1_prelude stuff, but I don't care to extract it at this time

		# if (self.meshdef1_prelude_offset2 != 0):
		#     somehow handle this as well

		# ---- meshdef0 entries ---- #
		# We are going to skip these for now as they don't appear to contain any meaningful data
		# Everything we care about is found in the meshdef1_prelude(s)
		# self.meshdef0_entries = [ meshdef0_entry(hob, offset) for offset in self.meshdef0_offsets ]
		
		# ---- meshdef1 entries ---- #
		self.meshdef1_entries = [ meshdef1_entry(hob, offset) for offset in self.meshdef1_offsets ]

	def __repr__(self):
		return pformat(vars(self))

with open(r"path\to\rogue_squad\data_block/00e55bd8_mempak_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/0024f558_destbuild_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/00251360_radardish_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/00e47ca0_helmet_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/00e453a8_medal_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/00ace670_sky_0_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/001e3898_atat_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/002107c8_tiebomber_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/00145670_snowspeeder_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/0018bea0_koelsch_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/002055c8_tankdroid_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/00234448_wrld_dvstr_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/0014de90_xwing_HOB", "rb") as hob:
# with open(r"path\to\rogue_squad\data_block/0024c0e0_pwrgen_HOB", "rb") as hob:
# with open(sys.argv[1], "rb") as hob:
	(object_count, ) = be16toh(hob.read(2))
	# Skipping over the seemingly useless offset after the object count
	# Usually pointing to the first facegroup, but I think it can point to the vertex list as well?
	hob.seek(6, os.SEEK_CUR)

	obj_list = [ object_entry(hob, (0x74 * obj_idx) + 8) for obj_idx in range(object_count) ]

	# print(obj_list)
	# obj = obj_list[0]
	# mesh1 = obj.meshdef1_entries[1]
	# print(mesh1.primary_vertex_count, mesh1.secondary_vertex_count)
	# print(mesh1.face_group)
	# for obj in obj_list:
	# 	for mesh1 in obj.meshdef1_entries:
	# 		if mesh1.secondary_vertices:
	# 			print(mesh1.secondary_vertex_count, mesh1.face_group.offset)
	# 			for idx, face in enumerate(mesh1.face_group.face_list):
	# 				if face.has_secondary_vertices:
	# 					print(idx)
	# 					print(face.secondary_vertex_indices)
	# 		print()



def blender_import(obj_list):
	import bpy
	import bmesh

	mat_map = dict()
	tex_names = [ (0, "mempackfront"), (1, "topsmall"), ]
	#radardish tex_names = [ (0, "post"), (1, "sensor.0"), (2, "dishedge"), (3, "dish2"), (6, "panels"), ]
	#helmet tex_names = [ (0, "reflct_helmtgls"), (1, "hlmt_airvents"), (2, "hlmt_botsides"), (3, "hlmt_midstrp"), (4, "hlmt_pntstrp"), (5, "hlmt_logo") ]
	#medal tex_names = [ (0, "silver_01")]
	#skybox0 tex_names = [
	# 	(0, "sky_c1l1_fourte"), (1, "sky_c1l1_thirte"), (2, "sky_c1l1_fiftee"), (3, "sky_c1l1_sevent"),
	# 	(4, "sky_c1l1_sixtee"), (5, "sky_c1l1_ten"), (6, "sky_c1l1_six"), (7, "sky_c1l1_eleven"),
	# 	(8, "sky_c1l1_three"), (9, "sky_c1l1_two"), (10, "sky_horizon"), (11, "sky_c1l1_twelve"),
	# 	(12, "sky_c1l1_five"), (13, "sky_c1l1_four"), (14, "sky_c1l1_seven"), (15, "sky_c1l1_eight"),
	# 	(16, "sky_c1l1_nine"),
	# ]
	#atat tex_names = [
	# 	(0, "wkhdfrt"), (1, "wkbdtop1"), (2, "wkbodysf"), (3, "wkbodysm"),
	# 	(4, "wkbdtop3"), (5, "wkbodysr"), (6, "wkbdtop2"), (7, "wkaxlet1"),
	# 	(8, "wksptx"), (9, "wkbdbak"), (10, "wkbodfrt"), (13, "wkhdsda"),
	# 	(14, "wkdirt01"), (15, "wkhdtopc"), (16, "wkneck"), (17, "wkulegt"),
	# 	(18, "wklleg03"), (19, "wkfootlod"),
	# ]
	#tiebombmer tex_names = [
	# 	(2, "tiebmb_pit01"), (3, "tiebmb_back01"), (4, "tiebmb_arm"), (5, "tiebmb_toplft"),
	# 	(6, "tiebmb_bmb"), (8, "tiebmb_toprght"), (9, "tiebmb_pit02"), (10, "tiebmb_cntr"),
	# 	(11, "tiebmb_frnt"), (12, "tiebmb_wngtp"), (13, "tiebmb_wngmid"), (15, "tiebmb_cntr"),
	# 	(16, "tiebmb_lod_wng"), (17, "tiebmb_lod_top"),
	# ]
	#snowspeeder tex_names = [
	#     (3, "sky_lv_01"), (4, "sbkgblk3"), (5, "atstdirt"), (7, "pilot_bck"),
	#     (8, "sp_grey"), (9, "sp_c_bck"), (10, "sp_c_top"), (11, "sp_c_sdb"),
	#     (12, "gunbarrel"), (13, "ckpinter"), (14, "s_wngtp2"), (15, "s_wngtp1"),
	#     (16, "sgrillbk"), (17, "bckwng"), (18, "eng_rif"), (19, "s_gn_top"),
	#     (20, "s_gn_mid"), (21, "s_gn_bt"), (22, "s_engbck"), (23, "spmdbttm"),
	#     (24, "spbttm"), (25, "spdrtpbk"), (26, "s_frtctr"), (27, "pilot_sd"),
	#     (28, "pilot_frnt"),
	# ]
	#nsf tex_names = [
	#     (0, "wing"), (2, "chrome_01"), (4, "sky_lv_01"), (7, "xr2hed_tp"),
	#     (8, "xr2hed"), (9, "amaturentop_16g"), (10, "pilot_flat_2_br"), (11, "topmain_a_scndt"),
	#     (12, "huibuh_ckpsd01"), (13, "huibuh_jetsd01"), (14, "additional"), (15, "topmain_b_scndt"),
	# ]
	#tankdroid tex_names = [ (0, "tnkdroid_turr_c"), (1, "tnkdroid_main_c"), (4, "tnkdroid_anim01"), (5, "tnkdroid_fence"), (6, "tnkdroid_twr"), ]
	#wrlddvstr tex_names = [
    #     (2, "wrldev_tile_06"), (3, "worldev03"),
    #     (4, "vacuum"), (5, "wrldev_foot_und"), (6, "wrldev_mrk_c"), (7, "wrldev_tile_11"),
    #     (8, "wrldev_mrk_a"), (9, "wrldev_mrk_d"), (10, "wrldev_mrk_b"), (11, "wrldev_tile_05a"),
    #     (12, "wrldev_twr_01"), (14, "wrldevmegun_mai"), (15, "wrldevmegun_mai"),
    #     (16, "wrldevmegun_dru"), (17, "i_gtu_hi_barrel"), (19, "missl_frnt"),
    #     (20, "missl_sd"), (21, "side_f"), (22, "top_f"), (23, "front_f"),
    #     (24, "i_gtu_hi_unibod"), (25, "i_gtu_hi_bbase"), (26, "i_gtu_hi_barrel"), (27, "i_gtu_hi_unifro"),
    #     (30, "wrldevgun_main"), (31, "wrldevgun_main_"),
    #     (32, "i_gtu_hi_unibod"), (33, "wrldevgun_det"), (34, "side_above_tex"), (35, "side_top_tex"),
    #     (36, "new_tex"), (37, "top_tex"), (38, "wrldev_tile_08_"), (39, "wrldev_tile_04_"),
	# ]
	#xwing tex_names = [
    #     (2, "xnose"), (3, "xthrust"),
    #     (4, "xwinginn"), (5, "xwingtop"), (7, "xengside"),
    #     (8, "xengfrnt"), (9, "xbckside"), (10, "xfrntsd4"), (11, "xengilight"),
    #     (12, "xlaserbod"), (13, "xtopbdydet"), (14, "xbkplate"), (15, "newx_glw_15"),
    #     (18, "sky_lv_01"), (19, "pilot_frnt"),
    #     (20, "pilot_sd"), (21, "xckpit"), (22, "xr2hed"), (23, "xr2hed_tp"),
    #     (24, "xfrntop"), (25, "xfrntsd1"), (26, "xfrntsd3"), (27, "xfrntsd2"),
	# ]

	for idx, name in tex_names:
		newtex = bpy.data.materials.new(name=f"{name}")
		newtex.use_nodes = True
		bsdf          = newtex.node_tree.nodes["Principled BSDF"]
		img_tex       = newtex.node_tree.nodes.new('ShaderNodeTexImage')
		img_tex.image = bpy.data.images.load(f"C:/Users/Tyler McGavran/Desktop/rogue_squad/output_pngs/{name}.png")
		newtex.node_tree.links.new(bsdf.inputs['Base Color'], img_tex.outputs['Color'])
		mat_map[idx] = newtex

	for obj in obj_list:
		hob_to_obj_mat_idx = dict()
		for mesh_idx, mesh1 in enumerate(obj.meshdef1_entries):
			mesh = bpy.data.meshes.new(f"{obj.object_name}_primary_mesh_{mesh_idx}")
			bobj = bpy.data.objects.new(f"{obj.object_name}_primary_object_{mesh_idx}", mesh)

			mesh.from_pydata(mesh1.primary_vertices, [], [face.primary_vertex_indices for face in mesh1.face_group.face_list])
			mesh.update(calc_edges=True)

			bm = bmesh.new()
			bm.from_mesh(mesh)

			uv_layer = bm.loops.layers.uv.verify()
			color_layer = bm.loops.layers.color.verify()
			for mesh_face, hob_face in zip(bm.faces, mesh1.face_group.face_list):
				if (hob_face.has_uv):
					try:
						mesh_face.material_index = hob_to_obj_mat_idx[hob_face.material_index]
					except KeyError:
						bobj.data.materials.append(mat_map[hob_face.material_index])
						hob_to_obj_mat_idx[hob_face.material_index] = len(bobj.data.materials) - 1
						mesh_face.material_index = hob_to_obj_mat_idx[hob_face.material_index]

					for loop, hob_uv in zip(mesh_face.loops, hob_face.texture_coordinates):
						loop[uv_layer].uv = (hob_uv[0], hob_uv[1])

				if (hob_face.has_color):
					if (hob_face.vertex_color):
						for loop, hob_color in zip(mesh_face.loops, hob_face.vertex_colors):
							loop[color_layer] = ((hob_color & 0xFF000000) / 255, (hob_color & 0x00FF0000) / 255, (hob_color & 0x0000FF00) / 255, (hob_color & 0x000000FF) / 255)


			bm.to_mesh(mesh)
			bm.free()
			bpy.context.collection.objects.link(bobj)

			if mesh1.secondary_vertices:
				mesh = bpy.data.meshes.new(f"{obj.object_name}_secondary_mesh_{mesh_idx}")
				bobj = bpy.data.objects.new(f"{obj.object_name}_secondary_object_{mesh_idx}", mesh)
				mesh.from_pydata(mesh1.secondary_vertices, [], [face.secondary_vertex_indices for face in mesh1.face_group.face_list if face.has_secondary_vertices])
				mesh.update(calc_edges=True)
				bpy.context.collection.objects.link(bobj)


blender_import(obj_list)
