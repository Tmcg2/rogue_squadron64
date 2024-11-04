# Cheat Codes

Copied from http://www.factor5.com/secrets_rogue_squadron.shtml:

| Cheat Code | Effect                                          |
| ---------- | ----------------------------------------------- |
| GAMEFLO!   | Unlocks all regular missions.                   |
| KOELSCH    | Turns the V-Wing into a 1969 Buick convertible. |
| FARMBOY    | Enables the Millennium Falcon.                  |
| TIEDUP     | Enables the Tie Fighter.                        |
| HALIFAX?   | First step access the Naboo Starfighter         |
| BLAMEUS    | Displays a picture of the development team.     |
| ACE        | Changes difficulty level to really hard.        |
| ICHHELD    | Luke turns into R. Henke                        |
| PSYLOCK    | Luke turns into M. Wagner                       |
| WUTZI      | Luke turns into J. Eggebrecht                   |
| BERGLOWE   | Luke turns into H. Schmidt                      |
| TIECK      | Luke turns into F. Sauer                        |
| RUDIBUBI   | Luke turns into R. Stember                      |
| CHIPPIE    | Luke turns into C. Huelsbeck                    |
| TOBIASS    | Luke turns into T. Richter                      |
| SIRHISS    | Luke turns into J. Petersam                     |
| HARDROCK   | Luke turns into T. Engel                        |
| THBPILOT   | Luke turns into B. Hoppe                        |
| FLYDODGE   | Luke turns into D. Jagalski                     |
| MAESTRO    | Activates the music menu.                       |
| DIRECTOR   | Let's you view all the cutscenes.               |
| CREDITS    | The Credits.                                    |
| IGIVEUP    | Unlimited lives.                                |
| RADAR      | Switches dark for bright in radar screen.       |
| TOUGHGUY   | All weapon and shield powerups.                 |
| CHICKEN    | Play as an AT-ST.                               |
| WOMPRAT!   | Unlocks the Tatooine race bonus level.          |
| WOISTHAN   | Unlocks the Death Star Trench bonus level.      |
| DEADDACK   | Unlocks the Battle of Hoth bonus level.         |
| !YNGWIE!   | Second stop to access the Naboo Starfighter     |

Cheat codes are not stored or verified in plaintext.
Cheats codes instead are passed through a CRC32 hash function and the hash is compared to a list of accepted hashes found at ROM address `0x800A0ED0`.

You can activate cheats codes via bit fiddling as well.
`0x80130B58` is the address of a 32 bit word that has a bunch of bit-flags for each cheatcode.
Reference the table below to see which flag is appropriate for which cheat code.

| ROM      | CRC32      | Code     | 80130B58   |
| -------- | ---------- | -------- | ---------- |
| 800A0ED0 | 0xaf6fa05c | GAMEFLO! | 0x00000001 |
| 800A0ED4 | 0x63d0142e | KOELSCH- | 0x00000002 |
| 800A0ED8 | 0x393f8bbf | FARMBOY- | 0x00000004 |
| 800A0EDC | 0xb66a9445 | TIEDUP-- | 0x00000008 |
| 800A0EE0 | 0x8fb7a6f2 | HALIFAX? | 0x00000010 |
| 800A0EE4 | 0x2f696225 | BLAMEUS- | 0x00000020 |
| 800A0EE8 | 0x40c19208 | ACE----- | 0x00000040 |
| 800A0EEC | 0x7dd0cc4b | ICHHELD- | 0x00000080 |
| 800A0EF0 | 0xa789b6ed | PSYLOCK- | 0x00000100 |
| 800A0EF4 | 0xc9278ee5 | WUTZI--- | 0x00000200 |
| 800A0EF8 | 0x3ebf0a20 | BERGLOWE | 0x00000400 |
| 800A0EFC | 0xe8a593fa | TIECK--- | 0x00000800 |
| 800A0F00 | 0x80080388 | RUDIBUBI | 0x00001000 |
| 800A0F04 | 0x0dccdf98 | CHIPPIE- | 0x00002000 |
| 800A0F08 | 0x5cae7f9f | TOBIASS- | 0x00004000 |
| 800A0F0C | 0xceb94078 | SIRHISS- | 0x00008000 |
| 800A0F10 | 0x654092d5 | HARDROCK | 0x00010000 |
| 800A0F14 | 0xe999ec85 | THBPILOT | 0x00020000 |
| 800A0F18 | 0x56289944 | FLYDODGE | 0x00040000 |
| 800A0F1C | 0xd842019e | MAESTRO- | 0x00080000 |
| 800A0F20 | 0x0c687bea | DIRECTOR | 0x00100000 |
| 800A0F24 | 0x09b770c0 | CREDITS- | 0x00200000 |
| 800A0F28 | 0xa04a5db4 | IGIVEUP- | 0x00400000 |
| 800A0F2C | 0x81a84cca | RADAR--- | 0x00800000 |
| 800A0F30 | 0x9a58a558 | TOUGHGUY | 0x01000000 |
| 800A0F34 | 0x477ac2fb | CHICKEN- | 0x02000000 |
| 800A0F38 | 0x557e6ad9 | WOMPRAT! | 0x04000000 |
| 800A0F3C | 0x494dac91 | WOISTHAN | 0x08000000 |
| 800A0F40 | 0x3c0ef6f5 | DEADDACK | 0x10000000 |
| N/A      | 0x050fe09c | !YNGWIE! | N/A        |
| N/A      | 0xcd668fa5 | MEAKMAN- | N/A        |

Note: The game reads the `-` from the cheat code screen when hashing the code, hence their inclusion in the table.

`MEAKMAN` might be a PC only cheat code.
Its referenced in many places online but it doesn't have a hash associated with it in the USA v1.0 ROM.

The 2nd cheat code used to enable the Naboo Starfighter (`!YNGWIE!`) is a little unique, its used in an encryption key like manner and as such you won't find it in the ROM's hash list.
Reference the [Naboo Starfighter](#naboo-starfighter) section for more details.

---

## CRC32

Reference [rs_crc32.c](/docs/cheat_codes/rs_crc32.c) for the in-game version of the CRC32 function.
Reference [crc32.c](/docs/cheat_codes/crc32.c) for a compilable version of that function.
The CRC32 hash function used in Star Wars Rogue Squadron is not exactly the same as the normal CRC32 function.
Most CRC32 implementations seed the hash with a value of `-1`/`0xFFFFFFFF`, but in Rogue Squadron its seeded with `0xFAC5FAC5` (cute choice on Factor 5's part)

---

## Naboo Starfighter

According to some interviews I've read (that I ashamedly can't find to cite here) the Naboo Starfighter was added into the game secrectly, with only 2 devs on the team knowing of its existence.
Thus, its HMT asset file is encrypted and you'll have to decrypt it to see it in its raw form.

The [ns_hmt_decode.c](/docs/cheat_codes/ns_hmt_decode.c) utility can do this after you've extracted the encrypted asset from the [Data Blob](/docs/data_blob/data_blob.md).
The decryption process can be roughly described with this python code:

```python
key = 0x050FE09C
plaintext = list()

for cipher_byte in cipher_text:
	plaintext_byte = (key & 0xFF) ^ cipher_byte
	plaintext.append(plaintext_byte)
	key = (key >> 8) | ((key & 0xFF) << 24)
	key += cipher_byte
print(plaintext)
```

Where `0x050FE09C` is the result of putting the second Naboo Starfighter cheat code (`!YNGWIE!`) through the [CRC32](#crc32) function.
I am sure this process is a well known encryption/decryption scheme, but I don't know enough about these matters to find out for certain.
I also don't know how to re-encrypt the file.
It might be as simple as passing the plain-text file through the decrypter function.

The in-game version of the decryption process is called [decrypt_ns_hmt](/docs/cheat_codes/decrypt_ns_hmt.c).
[func_8006C780.c](/docs/cheat_codes/func_8006C780.c) is the function that really drives the loading of the Naboo Starfighter's HMT asset.
It also crucially validates that the decryption process worked correctly.
The short version of validation is that it goes through the decrypted HMT file and confirms that a variety of offsets in the file are "sane".
Where "sane" means non-zero, multiples of 4, and are commensurate with the size of the file.
If the wrong cheat code was input, it is highly unlikely that all offets checked are "sane".

Curiously, all the asset files relating to the Naboo Starfighter are named `koelsch`, which seems like purposeful deception since the `KOELSCH` cheat code is for unlocking the Buick Electra, not the Naboo Starfighter.
