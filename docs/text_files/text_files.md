# Text Files

[ReRogues'a TXT file spec](https://github.com/dpethes/rerogue/blob/master/doc/file_txt_spec.txt) does a pretty good job of covering this topic.
This file will serve to be a more verbose specification.

There are 3 groups of text

- Front: Main menus
- Game:  In-mission menus
- Voice: Subtitles

The text files start with a header that looks like this C struct:

```cpp
struct text_file_header {
	uint16_t language_count;
	uint16_t string_count;
	uint32_t language_offset[5]; // Realistically this is sized to be the same as `language_count`, but whatever
	uint32_t file_size;
};
```

There are 5 languages in the game, the N64 and PC versions of the game are in agreement on that front.
The PC version (according to ReRogue) has English, Dutch, French, Spanish, and Japanese.
The N64 version (or, at least USA v1.0) has English, German, French, Italian, and Spanish.
While the USA v1.0 cart doesn't have a language select in any of its menus, you can change the language if you want via some bit fiddling.
`0x80130B46` is the address of the byte that controls the display language.
Set its value to whatever you want and then "change screens".
By this I mean go to the mission select screen (or to the main menu) to trigger the change.
See [unsorted thoughs](/docs/unsorted_thoughts/unsorted_thoughts.md) for more information about that particular ROM address.
Alternatively, set the byte at `0x8010FF20` to `1`(`OS_TV_TYPE_NTSC`) to activate a language selection menu in the "Game Settings" menu.
Note: it has to be `1`, the game (or, at least, the US version) only checks for that specific value.

```cpp
// from libultra's viint.h 
#define OS_TV_TYPE_PAL 0
#define OS_TV_TYPE_NTSC 1
#define OS_TV_TYPE_MPAL 2
```

```cpp
enum Language {
    LANGUAGE_EN, // English
    LANGUAGE_DE, // German
    LANGUAGE_FR, // French
    LANGUAGE_IT, // Italian
    LANGUAGE_ES, // Spanish
    NUM_LANGUAGES,
};
```

`string_count` is the number of strings present within any given language.

Each `language_offset` is a byte value relative to the beginning of the file where you can find a list of `uint16_t` numbers.
These numbers are offsets RELATIVE TO THE APPROPRIATE `language_offset` and point to a given string.
To be explicit, there are `string_count` numbers in this list.

```cpp
uint16_t string_offsets[text_file_header.string_count];
```

After all the `language_offsets` is a file size, in bytes.

I assume all the text in these files is in ASCII, but I haven't test that, I've only ever extracted the English text.

All text is obfuscated or if you want to be generous, encrypted.
So, to see the text in a readable form you have decrypt it.

## Text Decrypting

You can decrypt the text using the [text unmask utility](/docs/text_files/unmask_text.c), assuming you have extracted and decompressed the assets from the [Data Blob](/docs/data_blob/data_blob.md).

```cpp
// string_data is the encrypted data, which will be decrypted in-place
void decrypt(uint8_t *string_data, uint32_t string_size) {
    uint8_t prev = 0xf5;

    for (int i = 0; i < string_size; i++) {
        string_data[i] ^= prev;
        prev ^= string_data[i];
    }
}
```

It wouldn't surprise me if there's a name for this encryption/decryption scheme, but I don't know enough about those matters to find out for certain.
I don't know how to re-encrypt the text either, although I can't imagine its that difficult.
Hell, it might be as simple as running the plain text through the decryption program.

With Front and Game text you unmask all the text in one go.
Strings are only separated by their null-terminators.
Voice text is a little different; you have to unmask each string individually, resetting the unamsking process each time.
My way of unmasking Voice text is pretty fugly, I wouldn't be surprised to find out its broken to one extent or another.

[unmasked_text.txt](/docs/text_files/unmasked_text.txt) is pretty well what its name implies.
It contains all the decrypted strings in it, broken up visually into relevant blocks.
Its not the most beautiful thing on the planet but its good enough for now.

Looking at the unmasked text, some of them have unusual characters like `*{}` in them.
These don't show up in game, so something somewhere has to be using them for presentation/formatting purposes.

## Game Code Stuff

[func_800556A0.c](/docs/text_files/func_800556A0.c) and [func_80055978.c](/docs/text_files/func_80055978.c) appear to be the functions that do the decryption in-game.
There may or may not be other functions that do the decryption, I have not done a particularly thorough search.

[func_80055978.c](/docs/text_files/func_80055978.c) is specific to the Voice text I believe, it does some extra work to force all the decrypted text to be in upper case. (I wonder how this works for non-English text?).

[getGameOrFrontText.c](/docs/text_files/getGameOrFrontText.c) is pretty much what it says on the tin.
It takes a "text ID" and gives you back the string associated with that ID, but only for Front and Game text.
This function implies then that `D_8009ECA0` is a pointer to a `language_offset` list, and `D_80138E7C` is used to house the `string_count`.


