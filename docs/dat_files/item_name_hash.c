#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        uint32_t hash = 0xFFFF;
        char *string = argv[i];
        while (*string != '\0') {
            hash = *string++ + (hash * 0x21);
        }
        printf("0x%02x\n", hash & 0xFF);
    }
    return 0;
}
