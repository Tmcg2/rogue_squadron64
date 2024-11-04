#!/usr/bin/env python3

import struct

manifest_address = 0xfeffe8
manifest_size = 0x6c20
manifest_entry_readout = r">IIiHH16s"

data_offset = 0x144380

with \
open(r"rogue_squadron.z64", "rb") as rom, \
open(r"data_subsegments.yaml", "w") as subsegment:
	rom.seek(manifest_address)
	manifest = rom.read(manifest_size)

	for entry in struct.iter_unpack(manifest_entry_readout, manifest):
		offset         = entry[0]
		decompsize     = entry[1]
		compsize       = entry[2]
		flags          = entry[3]
		directory_size = entry[4]
		name           = bytes.decode(entry[5]).rstrip("\x00")

		if flags & 0x8000:
			subsegment.write(f"DIRECTORY {name} {directory_size//32}\n")
			continue

		if compsize == -1:
			extension = "raw"
			asset_size = decompsize
			subsegment.write(f"- [0x{data_offset + offset:08x}, UNKNOWN/NO COMPRESSION, {name}]\n")
		else:
			extension = "zz"
			asset_size = compsize & 0xFFFFFFF7
			subsegment.write(f"- [0x{data_offset + offset:08x}, zz, {name}]\n")

		rom.seek(data_offset + offset)

		with open(rf"data_block/{data_offset + offset:08x}_{name}.{extension}", "wb+") as asset:
			asset.write(bytes(rom.read(asset_size)))
