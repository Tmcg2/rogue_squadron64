#include <stdio.h>
#include <stdint.h>
#include <endian.h>

int main(int argv, char *argc[]) {
    char *speech_path = "./data_blob/data/speech.raw";
    FILE *speech_file = fopen(speech_path, "rb");

    if (speech_file == NULL) {
        printf("Failed to open %s", speech_path);
    }
    
    uint32_t sample_count;
    fread(&sample_count, sizeof(uint32_t), 1, speech_file);
    sample_count = be32toh(sample_count);

    for (int i = 0; i < sample_count; i++) {
        uint32_t offset;
        uint8_t  unknown;
        uint16_t freq;
        uint32_t word_count;

        fseek(speech_file, 4*(i + 1), SEEK_SET);
        fread(&offset, sizeof(uint32_t), 1, speech_file);

        offset = be32toh(offset);
        fseek(speech_file, offset & 0xFFFFFF, SEEK_SET);

        fseek(speech_file, 5, SEEK_CUR);
        fread(&unknown,    sizeof(uint8_t),  1, speech_file);
        fread(&freq,       sizeof(uint16_t), 1, speech_file);
        fread(&word_count, sizeof(uint32_t), 1, speech_file);

        freq       = be16toh(freq);
        word_count = be32toh(word_count);

        printf("MORT %03d: 0x%08x 0x%02x 0x%04x 0x%08x\n", i, offset & 0xFFFFFF, unknown, freq, word_count*4);
    }

    return 0;
}
