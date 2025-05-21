#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <endian.h>

struct medal_info {
    uint32_t completion_time;
    uint16_t enemies_destroyed;
    uint16_t accuracy;
    uint16_t friendlies_saved;
    uint16_t bonus_collected;
};

int main(int argc, char *agv[]) {
    struct medal_info entry;
    uint32_t count = 0;
    FILE *minfo = fopen("./data_blob/data/medal_info", "rb");

    while(fread(&entry, sizeof(struct medal_info), 1, minfo) == 1) {
        entry.completion_time   = be32toh(entry.completion_time);
        entry.enemies_destroyed = be16toh(entry.enemies_destroyed);
        entry.accuracy          = be16toh(entry.accuracy);
        entry.friendlies_saved  = be16toh(entry.friendlies_saved);
        entry.bonus_collected   = be16toh(entry.bonus_collected);

        if ((count % 3) == 0) printf("Level %d:\n", count / 3);
        if ((count % 3) == 0) printf("\tBronze:\n");
        if ((count % 3) == 1) printf("\tSilver:\n");
        if ((count % 3) == 2) printf("\tGold  :\n");
        printf("\t\tCompletion Time:   %5.2f\n", *(float*)(&entry.completion_time));
        printf("\t\tEnemies Destroyed: %5d\n", entry.enemies_destroyed);
        printf("\t\tAccuracy:         %5d%%\n", entry.accuracy);
        printf("\t\tFriendlies Saved:  %5d\n", entry.friendlies_saved);
        printf("\t\tBonus Collected:   %5d\n", entry.bonus_collected);
        count++;
        if ((count % 3) == 0) printf("\n");
    }

    return 0;
}
