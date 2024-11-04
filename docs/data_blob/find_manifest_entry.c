struct _m2c_stack_find_manifest_entry {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ u8 sp10;                            /* inferred */
    /* 0x011 */ char pad11[0xFF];                   /* maybe part of sp10[0x100]? */
    /* 0x110 */ u8 sp110;                           /* inferred */
    /* 0x111 */ char pad111[0x37];
};                                                  /* size = 0x148 */

extern ? D_80110AA0;

struct manifest_entry *find_manifest_entry(s32 arg0, u8 *arg1) {
    u8 sp110;
    u8 sp10;
    struct D_80110A80_entry *temp_v0;
    struct manifest_entry *var_s2;
    u16 temp_v0_3;
    u32 temp_s0;
    u32 temp_s0_2;
    u32 temp_v1;
    u32 var_s4;
    u8 *temp_v0_2;
    u8 *temp_v0_4;
    u8 *var_s5;

    // That I can tell, D_80110AA0 can contain paths that are conditionally prended to arg1 (the search string)
    // This is...
    // Get the path out of D_80110AA0[arg0]
    rs_strcpy(&sp10, (arg0 * 0x50) + &D_80110AA0);
    // If its non-null AND not ending in '/'
    if ((sp10 != 0) && ((&sp10)[strlen((s8 *) &sp10)].unk-1 != 0x2F)) {
        // append a '/'
        rs_strcat(&sp10, "/");
    }
    // append arg1 (the search string) to the (potentially empty) sp10 (path) string
    rs_strcat(&sp10, arg1);
    // append a '/'
    rs_strcat(&sp10, "/");
    temp_v0 = &D_80110A80[arg0];
    var_s2 = temp_v0->manifest;
    // Start by considering all possible entries in the manifest
    var_s4 = temp_v0->entry_count;

    // "cut" the string at the first '/'
    temp_v0_2 = strchr(&sp10, 0x0000002F);
    temp_s0 = temp_v0_2 - &sp10;
    // save the left hand side of the cut to sp110
    rs_strncpy(&sp110, &sp10, temp_s0);
    var_s5 = temp_v0_2 + 1;
    // Replace the '/' with a null character. We have effectively split the search string into 2 strings
    (&sp110)[temp_s0] = 0;
    // While we haven't found the manifest entry...
loop_4:
    // compare the cut part of the string to the name of the manifest entry we're considering
    // If they are not the same...
    if (rs_strncmp(&sp110, var_s2->name, 0x00000010U) != 0) {
        // Check if the the entry in question is a directory.
        // If it is not a directory...
        if (!(var_s2->flags & 0x80)) {
            // Step forward to the next entry
            var_s2 += 0x20;
            var_s4 -= 1;
        // If it is a directory...
        } else {
            // Get the number of entries in the directory, then skip forward that many entries.
            // That is, skip the entire directory
            temp_v1 = (u16) var_s2->directory_size >> 5;
            var_s2 = &var_s2[temp_v1];
            var_s4 -= temp_v1;
        }
        // Go to loop condition check
        goto block_13;
    }
    // If the name matches, and the entry we're considering is not a directory...
    if (!(var_s2->flags & 0x80)) {
        // Success! Return the manifest entry, its the one we're looking for
        return var_s2;
    }
    // Otherwise, it is a directory, so we need to search the directory and nothing else...
    temp_v0_3 = var_s2->directory_size;
    // Walk forward past the directory entry itself
    var_s2 += 0x20;
    // Cut the string at the next '/'
    temp_v0_4 = strchr(var_s5, 0x0000002F);
    temp_s0_2 = temp_v0_4 - var_s5;
    // Again, save the left hand side of the cut to sp110
    rs_strncpy(&sp110, var_s5, temp_s0_2);
    var_s5 = temp_v0_4 + 1;
    // Set the count of entries-to-search to the number of entries in the directory (minus 1)
    var_s4 = (temp_v0_3 >> 5) - 1;
    // Replace the '/' with a null character. We have effectively split the search string into 2 strings
    (&sp110)[temp_s0_2] = 0;

    // Loop condition
    // If we're run out of entries to consider, return NULL. We failed to find the entry in question
block_13:
    if ((s32) var_s4 <= 0) {
        return NULL;
    }
    goto loop_4;
}
