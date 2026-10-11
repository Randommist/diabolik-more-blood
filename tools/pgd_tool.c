#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kirk_engine.h"
int verbose=0;
void hex_dump(const char *s, void *p, int n) {}
typedef struct {u8 vkey[16];int open_flag,key_index,drm_type,mac_type,cipher_type,data_size,align_size,block_size,block_nr,data_offset,table_offset;u8 *buf;} PGD;
extern PGD *pgd_open(u8 *,int,u8 *);
extern int pgd_decrypt(u8 *,int,int,u8 *);
extern int pgd_encrypt(u8 *,int,u8 *);
int main(int argc,char **argv){
 if(argc<4) return 1;
 FILE *f=fopen(argv[2],"rb"); if(!f) return 2;
 fseek(f,0,SEEK_END);long n=ftell(f);rewind(f);
 u8 *b=malloc(n);if(fread(b,1,n,f)!=n)return 3;fclose(f);
 kirk_init();
 if(!strcmp(argv[1],"decrypt")){
  int size=pgd_decrypt(b,n,2,NULL);if(size<0)return 4;
  f=fopen(argv[3],"wb");fwrite(b+0x90,1,size,f);fclose(f);
  printf("Decrypted %d bytes\n",size);
 }else if(!strcmp(argv[1],"encrypt") && argc==5){
  PGD *p=pgd_open(b,2,NULL);if(!p)return 5;
  f=fopen(argv[3],"rb");if(!f)return 6;
  fseek(f,0,SEEK_END);long datasize=ftell(f);rewind(f);
  long align=(datasize+15)&~15;long blocks=(align+p->block_size-1)/p->block_size;
  long newsize=p->data_offset+align+blocks*16;
  b=realloc(b,newsize);memset(b+p->data_offset,0,newsize-p->data_offset);n=newsize;
  *(u32*)(b+0x44)=datasize;
  if(fread(b+p->data_offset,1,datasize,f)!=datasize)return 7;fclose(f);
  if(pgd_encrypt(b,2,p->vkey))return 8;
  f=fopen(argv[4],"wb");fwrite(b,1,n,f);fclose(f);
 }else return 9;
 free(b);return 0;
}
