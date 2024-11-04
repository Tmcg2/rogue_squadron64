#!/usr/bin/env python3

import struct

# For a detailed explanation of the file structure, consult https://github.com/dpethes/rerogue/blob/master/doc/file_txt_spec.txt

# Front (menus) and game (in-mission) text are unmasked as monolithic blocks
with open("data_block/00fbaf58_front_TXT.raw", "rb") as data:
	parts, entries_per_part, eng_header, ger_header, frn_header, spn_header, jpn_header, eof = struct.unpack(">HHIIIIII", data.read(28))
	# Seek past the english offset list, we won't be needing it
	data.seek(entries_per_part * 2, 1)
	# Read all the string data for the english part, prepending 0xf5 to the start
	all_parts = bytearray(b"\xf5")
	all_parts.extend(data.read(ger_header - data.tell()))
	# Unmask
	# I regret doing this in a one-liner :(
	for thing in enumerate(bytes([prev ^ cur for prev, cur in zip(all_parts[:-1], all_parts[1:])]).split(b"\x00")):
		print(f"{thing[0]:08x}: {thing[1]}")
print("\n")

with open("data_block/00fc94f8_game_TXT.raw", "rb") as data:
	parts, entries_per_part, eng_header, ger_header, frn_header, spn_header, jpn_header, eof = struct.unpack(">HHIIIIII", data.read(28))
	# Seek past the english offset list, we won't be needing it
	data.seek(entries_per_part * 2, 1)
	# Read all the string data for the english part, prepending 0xf5 to the start
	all_parts = bytearray(b"\xf5")
	all_parts.extend(data.read(ger_header - data.tell()))
	# Unmask
	# I regret doing this in a one-liner :(
	for thing in enumerate(bytes([prev ^ cur for prev, cur in zip(all_parts[:-1], all_parts[1:])]).split(b"\x00")):
		print(f"{thing[0]:08x}: {thing[1]}")
print("\n")

# Voice text is unique, you have to unmask each string by itself
# In-game this doesn't matter, but for our purposes here it means we can't consume the masked data all at once
# This is due to some strings having an extraneous byte after they're 0x00 byte.
# That bytes is always (?) 0x2A (42). I have no idea why its there for some strings and not others, nor do I understand what if any purpose it has
# Maybe they're padding odd-length strings to be even length?
with open("data_block/00fcceb0_voice_TXT.raw", "rb") as data:
	parts, entries_per_part, eng_header, ger_header, frn_header, spn_header, jpn_header, eof = struct.unpack(">HHIIIIII", data.read(28))

	# Get the list of offets to the beginning of each string
	offsets = [ part_offset[0] for part_offset in struct.iter_unpack(">h", data.read(2*entries_per_part)) ]
	# Ensure we get the last string, but in a clunky way that causes us to over-read data
	offsets.append(ger_header)
	for start, end in zip(offsets[:-1], offsets[1:]):
		# Read data for this string, prepending 0xf5 to the start
		part = bytearray(b'\xf5')
		part.extend(data.read(end - start))
		last_byte = part[-1]
		# Unmask
		unmasked = bytes([prev ^ cur for prev, cur in zip(part[:-1], part[1:])])
		print(unmasked)
		# Print the extraneous byte, if present
		# if unmasked[-1] != 0x00:
		# 	print(last_byte)
