#ifndef INFBLOCK_H
#define INFBLOCK_H

#include "PR/ultratypes.h"
#include "zlib/infcodes.h"
#include "zlib/inftrees.h"
#include "zlib/zutil.h"

struct inflate_blocks_state;
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
#define OUTBYTE(a) {*q++=(u8)(a);m--;}
/*   load local pointers */
#define LOAD {LOADIN LOADOUT}

void inflate_blocks_reset(inflate_blocks_statef*, z_stream*, u32*);
inflate_blocks_statef *inflate_blocks_new(z_stream*, check_func, u32);
s32  inflate_blocks(inflate_blocks_statef*, z_stream*, s32);
s32  inflate_blocks_free(inflate_blocks_statef*, z_stream*, u32*);
void inflate_set_dictionary(inflate_blocks_statef*, const u8*, u32);

#endif
