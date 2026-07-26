#!/usr/bin/env python3

import sys

with open(sys.argv[1], "r") as f:
    content = f.readlines()

start = None
end = None

for idx, line in enumerate(content):
    if "glabel fake_func" in line:
        start = idx
    if "endlabel fake_func" in line:
        end = idx

if start is None or end is None:
    exit()

for idx in range(start + 1, end):
    words = content[idx].split()
    if len(words) <= 2:
        continue
    content[idx] = f".word 0x{words[3]}\n"

with open(sys.argv[1], "w") as f:
    f.writelines(content)
