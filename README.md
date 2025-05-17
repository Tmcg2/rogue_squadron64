# Star War Rogue Squadron Decomp(ish)

This is the beginning of a very, very rough attempt at decompiling Star Wars Rogue Squadron for the N64 (USA version 1.0).
In its current state it can't even really be properly called a decomp.
You can only barely rip the ROM apart into its constituent parts, and even then its not really working right.
You also can't recompile the parts back together into a matching ROM.
Even with those short falls I still thinks its best for me to release what I have to the public.
That at least will open the doors for people with newer, fresher eyes than mine to make progress.

In its current state the project contains a few different things:

- Files for Splat so that it can (kind of, sort of) split the ROM up
- A few utilites related to extracting game assets (textures, models, text, etc)
- Several disparate files of notes filled with observations I've made
- A couple files that have been """decompiled""" (passed through M2C) with minor annotations added by me

This file has several purposes, some of which I have probably failed to enumerate here.

1) List acknowldgements
2) Be a map/manifest of the rest of the project
3) Contain explanations (some brief, some not) of a variety of things

---

## Documentation

The bulk of the documentation in the project is found under the [docs folder](/docs).
So if you want to know more about something specific, start there.
In general the documentation is centered around utilities I wrote and what I learned about the game in the course of writing and using them.

---

## Splat

The splitting job leaves a lot to be desired, but ALL issues stemming from this should be treated as user error on my part rather than a problem with Splat itself until proven otherwise.

Follow the installation instructions for splat found at `https://github.com/ethteck/splat`.
Then (legally, of course) obtain a ROM of Star Wars Rogue Squadron (USA v1.0) with sha1sum `ed42eed1ee2db646ff7ef94ba8c5421d164a4f0d`.
Move that ROM to the project root directory and name it `rogue_squadron.z64`.
Run `splat split roguesquadron.yaml` and you'll (kind of) get the ROM broken up into its constituent parts.

At the moment there are several issues with the split.
Its pretty clear that some sections identified as code have data inside them and vice-versa.
Variables or jump labels getting interpreted as functions is a big one.
Jump tables and jump labels don't always get identified properly, requiring manual invervention to fix.
The names I chose for the overlays are pretty bad, and I can't even say with certainty that I identified them correctly.

But, as previously mentioned, all that should be assumed to be user error.

---

## zlib

There is a partial implementation of the `zlib` utility in Rogue Squadron.
By partial I mean only the inflate code is preset, the deflate code is not present.
Which makes sense, the game only ever needs to inflate assets, it never has to re-deflate them.
You can find that code by finding `zlib` in `roguesquadron.yaml` and the resulting `asm/nonmatchings/zlib` folder.

Its not clear to me what version of zlib they're using though, there's bits and pieces of it that suggest contradictory version numbers.

`inflate_trees_free` (aka `func_80029A68`) would suggest that it can't be earlier than `v0.99`.
This can be seen by comparing the `v0.93` and `v0.99` versions of this function in the `zlib` source proper.
In `v0.99` there are 2 while loops, and the assembly for Rogue Squadron looks to have 2 loops.

Contradicting this, `zcalloc` (aka `func_80029CD0`) suggests that it can't be later than `v0.95`.
In `v0.99` that function gains a new `if` statement that is noticeably missing from Rogue Squadron's assembly.

`inflate_blocks_reset` (aka `func_800275F0`) appears to have been aggressively inline'd.
There are some actual calls to this function left floating around but there's way less of them than the `zlib` source code would suggest there should be.

---

## Acknowledgements

This a list of programs, utilities, and resources I have used in the course of making the repository.
They are presented in no particular order.

### [ReRogue Project](https://github.com/dpethes/rerogue)

This has been an invaluable resource for understanding how things like images, models, and text are stored in the game.
ReRogue focuses on the PC version of the game, which means there are minor differences between it and this decomp, but it still more than accurate enough to have been useful.
The spec files found in the `docs` folder of that project are of particular note.

### [Splat](https://github.com/ethteck/splat)

Splat is a ROM disassembler and is used in this project to pick the ROM apart.
I don't know where I would have even started without this tool.

### [M2C](https://github.com/matt-kempster/m2c)

M2C (MIPS to C) is a MIPS decompiler and is used to convert MIPS assembly to C code.
Similar to [Splat](#splat), I don't know where I would have even started without this tool.

### [Project64](https://www.pj64-emu.com/)

Its my understanding that this emulator has something of a bad reputation, although I am ignorant to the reasons why.
Regardless of its reputation, earned or otherwise, I have made extensive use of it and its debugging/memory viewer (I believe Shygoo gets the credit for that?) so I'm going to acknowledge it here.
Without I would have been very, very stuck.

### [pigz](https://zlib.net/pigz/)

A command line utility that allows you to de/compress raw [zlib](#zlib) streams.
This has been crucial for extracting assets from the ROM and will likely be critical to any serious decompilation effort of this game.

### [spng](https://libspng.org/)

A simple PNG file library, used by some of my utilites to aid in converting assets from their in-ROM representation to PNGs.
Very useful and pretty starightforward to use.

Related to this I have referenced the PNG specification itself.
A version of that specification can be found here: `https://www.w3.org/TR/png-3/`

### [ultralib](https://github.com/decompals/ultralib)

A decomped vesrion of Nintendo's `libultra`, crucial in identifying the `libultra` code found in the ROM.
