# Subtitles

There are 16 subtitle "slots".
Each slot is a 12 byte struct, and they are stored in the array `subtitleSlots`.
The array operates similar to a queue, although `head` and `tail` index numbers rather than pointers.

```cpp
struct subtitle_context {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ u16 voiceId;
    /* 0x06 */ u16 flags;
    /* 0x08 */ u8  unk08;
    // 3 bytes of padding here
}; // size = 0x0C

u32 D_80139B80[8];
u8  D_80139BA0[8];
// RAM addresses 0x80139C70 - 0x80139C73
u8  subtitleSlotHead;
u8  subtitleSlotTail;
u8  subtitleSlotsAvailable;
u8  D_80139C73;
// RAM address 0x80139BB0
struct subtitle_context subtitleSlots[16];

// RAM address 0x80154670
u32   numSpeechSamples;
// RAM address 0x8015467C
u32  *speechSampleOffsets;
// RAM address 0x80154684
void *speechFile;

// RAM address 0x8009FFE0
u16 voiceIdtoTextIdMap[0x2F4];
// RAM address 0x800A5120
u8 speechSampleOffsetsLoaded;
// RAM address 0x800A5121
u8 speechFileLoaded;
```

## Speech File

I have some understanding of the [speech file](../../data_blob/data/speech.raw) found in the [Data Blob](../data_blob/data_blob.md).

The first word in the file is the number of speech samples(?) found in the file.
In the game's code this is saved to `numSpeechSamples`.

The next `numSpeechSamples` words are the file relative offsets to each of the samples.
In the game's code these offsets are saved to `speechSampleOffsets`.
There's a bit of nuance to these numbers: the top byte of the word isn't part of the offset.
Instead its something like a flag/type entry.
I can't find anything that reads those bytes, so I don't know what they really are.

```cpp
struct speech_offset {
    u32   type :  8;
    u32 offset : 24;
}; // size = 0x8
```

Each sample starts with around 12 bytes worth of a header (of sorts).

```cpp
struct mort_header {
    /* 0x00 */ char file_magic[5]; // Always "MORT\0"
    /* 0x05 */ u8  unk05; // No idea what this byte is
    /* 0x06 */ u16 unk06; // Seemingly 8000 or 16000 for every samle, unclear what this is meant to be. Might be a frequency setting?
    /* 0x08 */ u32 word_count; // Size of the MORT sample in 4-byte words, including the header
}
```

After this header the next `(word_count * 4) - 12` bytes are raw data.
I have no idea how to interpret any of it.
