#ifndef ZLIB_H
#define ZLIB_H

#include "PR/ultratypes.h"

typedef void *(*alloc_func)(void *opaque, u32 items, u32 size);
typedef void   (*free_func)(void *opaque, void *address);

struct internal_state;

typedef struct z_stream_s {
    u8    *next_in;  /* next input byte */
    u32     avail_in;  /* number of bytes available at next_in */
    u32    total_in;  /* total nb of input bytes read so far */

    u8    *next_out; /* next output byte should be put there */
    u32     avail_out; /* remaining free space at next_out */
    u32    total_out; /* total nb of bytes output so far */

    char     *msg;      /* last error message, NULL if no error */
    struct internal_state *state; /* not visible by applications */

    alloc_func zalloc;  /* used to allocate the internal state */
    free_func  zfree;   /* used to free the internal state */
    void     *opaque;  /* private data object passed to zalloc and zfree */

    s32     data_type;  /* best guess about the data type: ascii or binary */
    u32   adler;      /* adler32 value of the uncompressed data */
    u32   reserved;   /* reserved for future use */
} z_stream;

#endif
