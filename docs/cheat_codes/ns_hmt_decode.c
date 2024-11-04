#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

const char ns_hmt_filepath[] = "./data_block/0018e540_koelsch_HMT.raw";
const char plaintext_filepath[] = "./data_block/0018e540_koelsch_HMT";

int main(int argc, char *argv[]) {
    FILE *ciphertext;
    FILE *plaintext;
    uint8_t cipherbyte, plaintextbyte;
    uint32_t key = 0x050FE09C;

    plaintext = fopen(plaintext_filepath, "wb");
    if (plaintext == NULL) {
        printf("Given path: %s\n", plaintext_filepath);
        printf("errno: %d\nError string: %s\n", errno, strerror(errno));
        return -1;
    }

    ciphertext = fopen(ns_hmt_filepath, "rb");
    if (ciphertext == NULL) {
        printf("Given path: %s\n", ns_hmt_filepath);
        printf("errno: %d\nError string: %s\n", errno, strerror(errno));
        return -1;
    }

    while ((cipherbyte = getc(ciphertext)) != EOF) {
        plaintextbyte = (key & 0xFF) ^ cipherbyte;
        putc(plaintextbyte, plaintext);
        key = (key >> 8) | ((key & 0xFF) << 24);
        key += cipherbyte;
    }

    fclose(ciphertext);
    fclose(plaintext);

    return 0;
}
