//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

 // Devices: Mouse, Disks, Files, Ram, &...
#ifndef __DEVICE
#define __DEVICE
typedef unsigned int word;
typedef unsigned char byte;
typedef void *va_list;
extern word FEC;
extern long XMS;
extern word mox,moy,mbutts;
#define __size( x ) ( ( sizeof( x ) + sizeof( int ) - 1 ) & ~( sizeof( int ) - 1 ))
#define va_arg(ap, type) (*(type *)(((*(char **)&(ap))+=__size(type))-(__size(type))))
#define MK_FP( seg,ofs )( (void _seg * )( seg ) +( void near * )( ofs ))
#define FP_SEG( fp )( (unsigned )( void _seg * )( void far * )( fp ))
#define FP_OFF( fp )( (unsigned )( fp ))
#define XMSINT 0x2F

struct XMSC{
 long Size;
 word SHdl;
 long SOfs;
 word THdl;
 long TOfs;
 };
struct fileblock {
 byte reserved[21];
 byte attrib;
 word ftime,fdate;
 long fsize;
 byte fname[13];
 };
void imouse();
void setmarea(word x1,word y1,word x2,word y2);
void setmpos(word x, word y);
void setmousespeed(word speedx,word speedy,word maxdub);
void settxtmshape(word andmask,word xormask);
void setgrpmshape(char *bitfield);
word kmouse(word *x,word *y);
void w4fm(word w);
void mshow();
void rmouse();
void GetMouse();
void mkdir(char *str);
void rddir(char *str);
void chdir(char *str);
word newfile(char *str,word a);
word openf(char *str,byte m,word a);
void closef(word handle);
word readf(char *str,word how,word handle);
word writef(char *str,word how,word handle);
long movef(long how,byte mode,word handle);
long filepos(word handle);
long filesize(word handle);
byte iseof(word handle);
byte readb(word handle);
word readw(word handle);
long readl(word handle);
void writeb(byte b,word handle);
void writew(word b,word handle);
void writel(long b,word handle);
word findf(byte *name,word attb,struct fileblock *fb);
word nextf(struct fileblock *fb);
void setdta(byte far *addr);
char far *getdta();
long getdiskfree(byte disk);
word XMSInst();
long XMSfreeSize();
byte XMSFree(word Handle);
byte XMSGet(word *Handle,word size);
byte RAM2XMS(long p,word h,long xo,long size);
byte XMS2RAM(long p,word h,long xo,long size);
byte XMS2XMS(word sh,long sxo,word h,long dxo,long size);


#endif