#ifndef ZLIB_FORWARD_DECLARES
#define ZLIB_FORWARD_DECLARES

struct inflate_huft_s;

struct inflate_codes_state;

struct inflate_blocks_state;

typedef u32 (*check_func)(u32 check, u8 *buf, u32 len);

typedef struct inflate_huft_s inflate_huft;
/* Huffman code lookup table entry--this entry is four bytes for machines
   that have 16-bit pointers (e.g. PC's in the small or medium model). */
struct inflate_huft_s {
    union {
        struct {
            u8 Exop;        /* number of extra bits or operation */
            u8 Bits;        /* number of bits in this code or subcode */
        } what;
        u8 *pad;         /* pad structure to a power of 2 (4 bytes for */
    } word;               /*  16-bit, 8 bytes for 32-bit machines) */
    union {
        u32 Base;          /* literal, length base, or distance base */
        inflate_huft *Next; /* pointer to next level of table */
    } more;
};

/* inflate codes private state */
struct inflate_codes_state {
    /* mode */
    enum {        /* waiting for "i:"=input, "o:"=output, "x:"=nothing */
    START,    /* x: set up for LEN */
    LEN,      /* i: get length/literal/eob next */
    LENEXT,   /* i: getting length extra (have base) */
    DIST,     /* i: get distance next */
    DISTEXT,  /* i: getting distance extra */
    COPY,     /* o: copying bytes in window, waiting for space */
    LIT,      /* o: got literal, waiting for output space */
    WASH,     /* o: got eob, possibly still output waiting */
    END,      /* x: got eob and all data flushed */
    BADCODE}  /* x: got error */
    mode;               /* current inflate_codes mode */

    /* mode dependent information */
    u32 len;
    union {
        struct {
            inflate_huft *tree;       /* pointer into tree */
            u32 need;                /* bits needed */
        } code;             /* if LEN or DIST, where in tree */
        u32 lit;           /* if LIT, literal */
        struct {
            u32 get;                 /* bits to get for extra */
            u32 dist;                /* distance back to copy from */
        } copy;             /* if EXT or COPY, where and how much */
    } sub;                /* submode */

    /* mode independent information */
    u8 lbits;           /* ltree bits decoded per branch */
    u8 dbits;           /* dtree bits decoder per branch */
    inflate_huft *ltree;          /* literal/length/eob tree */
    inflate_huft *dtree;          /* distance tree */
};
typedef struct inflate_codes_state inflate_codes_statef;

typedef enum {
      TYPE,     /* get type bits (3, including end bit) */
      LENS,     /* get lengths for stored */
      STORED,   /* processing stored block */
      TABLE,    /* get table lengths */
      BTREE,    /* get bit lengths tree for a dynamic block */
      DTREE,    /* get length, distance trees for a dynamic block */
      CODES,    /* processing fixed or dynamic block */
      DRY,      /* output remaining window bytes */
      DONE,     /* finished last block, done */
      BAD}      /* got a data error--stuck here */
inflate_block_mode;

struct inflate_blocks_state {
    /* mode */
    inflate_block_mode mode;               /* current inflate_block mode */

    /* mode dependent information */
    union {
        u32 left;          /* if STORED, bytes left to copy */
        struct {
            u32 table;               /* table lengths (14 bits) */
            u32 index;               /* index into blens (or border) */
            u32 *blens;             /* bit lengths of codes */
            u32 bb;                  /* bit length tree depth */
            inflate_huft *tb;         /* bit length decoding tree */
        } trees;            /* if DTREE, decoding info for trees */
        struct {
            inflate_huft *tl, *td;    /* trees to free */
            inflate_codes_statef 
            *codes;
        } decode;           /* if CODES, current state */
    } sub;                /* submode */
    u32 last;            /* true if this block is the last block */

    /* mode independent information */
    u32 bitk;            /* bits in bit buffer */
    u32 bitb;           /* bit buffer */
    u8 *window;        /* sliding window */
    u8 *end;           /* one byte after sliding window */
    u8 *read;          /* window read pointer */
    u8 *write;         /* window write pointer */
    check_func checkfn;   /* check function */
    u32 check;          /* check on output */
};
typedef struct inflate_blocks_state inflate_blocks_statef;

/* constants */

#define Z_NO_FLUSH      0
#define Z_PARTIAL_FLUSH 1
#define Z_SYNC_FLUSH    2
#define Z_FULL_FLUSH    3
#define Z_FINISH        4
/* Allowed flush values; see deflate() below for details */

#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_ERRNO        (-1)
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR   (-3)
#define Z_MEM_ERROR    (-4)
#define Z_BUF_ERROR    (-5)
#define Z_VERSION_ERROR (-6)
/* Return codes for the compression/decompression functions. Negative
 * values are errors, positive values are used for special but normal events.
 */

#define Z_NO_COMPRESSION         0
#define Z_BEST_SPEED             1
#define Z_BEST_COMPRESSION       9
#define Z_DEFAULT_COMPRESSION  (-1)
/* compression levels */

#define Z_FILTERED            1
#define Z_HUFFMAN_ONLY        2
#define Z_DEFAULT_STRATEGY    0
/* compression strategy; see deflateInit2() below for details */

#define Z_BINARY   0
#define Z_ASCII    1
#define Z_UNKNOWN  2
/* Possible values of the data_type field */

#define Z_DEFLATED   8
/* The deflate compression method (the only one supported in this version) */

#define Z_NULL  0  /* for initializing zalloc, zfree, opaque */

/* defines for inflate input/output */
/*   update pointers and return */
#define UPDBITS {s->bitb=b;s->bitk=k;}
#define UPDIN {z->avail_in=n;z->total_in+=p-z->next_in;z->next_in=p;}
#define UPDOUT {s->write=q;}
#define UPDATE {UPDBITS UPDIN UPDOUT}
#define LEAVE {UPDATE return inflate_flush(s,z,r);}
/*   get bytes and bits */
#define LOADIN {p=z->next_in;n=z->avail_in;b=s->bitb;k=s->bitk;}
#define NEEDBYTE {if(n)r=Z_OK;else LEAVE}
#define NEXTBYTE (n--,*p++)
#define NEEDBITS(j) {while(k<(j)){NEEDBYTE;b|=((u32)NEXTBYTE)<<k;k+=8;}}
#define DUMPBITS(j) {b>>=(j);k-=(j);}
/*   output bytes */
#define WAVAIL (q<s->read?s->read-q-1:s->end-q)
#define LOADOUT {q=s->write;m=WAVAIL;}
#define WRAP {if(q==s->end&&s->read!=s->window){q=s->window;m=WAVAIL;}}
#define FLUSH {UPDOUT r=inflate_flush(s,z,r); LOADOUT}
#define NEEDOUT {if(m==0){WRAP if(m==0){FLUSH WRAP if(m==0) LEAVE}}r=Z_OK;}
#define OUTBYTE(a) {*q++=(u8)(a);m--;}
/*   load local pointers */
#define LOAD {LOADIN LOADOUT}

#endif
