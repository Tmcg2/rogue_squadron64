#ifndef INFBLOCK_H
#define INFBLOCK_H

#include "PR/ultratypes.h"
#include "zlib/infcodes.h"
#include "zlib/inftrees.h"
#include "zlib/zutil.h"

struct inflate_blocks_state {

  /* mode */
  enum {
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
    mode;               /* current inflate_block mode */

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
#define OUTBYTE(a) {*q++=(Byte)(a);m--;}
/*   load local pointers */
#define LOAD {LOADIN LOADOUT}

void inflate_blocks_reset(inflate_blocks_statef*, z_stream*, u32*);
inflate_blocks_statef *inflate_blocks_new(z_stream*, check_func, u32);
s32  inflate_blocks(inflate_blocks_statef*, z_stream*, s32);
s32  inflate_blocks_free(inflate_blocks_statef*, z_stream*, u32*);
void inflate_set_dictionary(inflate_blocks_statef*, const u8*, u32);

#endif
