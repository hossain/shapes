//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

//     Screen Header File
// Includes: Text screen works
//
#if !defined( __HTSSCREEN )
#define __HTSSCREEN
extern void unloadTSR();
extern int TSRLoaded;
typedef unsigned int word;
typedef unsigned char byte;
typedef void *va_list;

#define Get_Back    16+14
#define Get_Border  16+3
#define Get_Msg     16+11
#define Get_Txt     16+14
#define Msg_Back    32+15
#define Msg_Border  32+14
#define Msg_Msg     32+15
#define Ask_Back    80+15
#define Ask_Border  80+12
#define Ask_Msg     80+15
#define Err_Back    64+15
#define Err_Border  64+12
#define Err_Msg     64+15

#define __size( x ) ( ( sizeof( x ) + sizeof( int ) - 1 ) & ~( sizeof( int ) - 1 ))
#define va_arg(ap, type) (*(type *)(((*(char **)&(ap))+=__size(type))-(__size(type))))
#define MK_FP( seg,ofs )( (void _seg * )( seg ) +( void near * )( ofs ))
#define FP_SEG( fp )( (unsigned )( void _seg * )( void far * )( fp ))
#define FP_OFF( fp )( (unsigned )( fp ))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

struct Menu {
 byte Mx,My;
 byte *ItemAddr;
 byte CAttr,BCAttr;
 byte Horize, IHD, sye;
};

struct time {
 char hour;
 char min;
 char sec;
 char msec;
};

struct date {
 int  year;
 char month;
 char day;
 char weekday;
};


extern word TXT_ADDR;
extern word xpp,ypp;
extern byte attr,ZF;
extern byte MaxXtxt,MaxYtxt;
extern char key1,key2;

void wc(byte c);
void strw(byte *str);// memory
void print(byte *str);//Intruppt
void iwc(byte c);
byte *input(byte *str);
byte getch();
byte gettxtx(),gettxty();
void setscreen(byte c);
byte getscreen();
void enter();
byte gc(word xp,word yp,byte *art);
void movescreen(byte where,byte how);
void cls();
void scol(byte c,byte bc);
void goxy(byte x,byte y);
void box(byte x1,byte y1,byte x2,byte y2,byte c,byte atr);
void win(byte x1,byte y1,byte x2,byte y2,byte c,byte atr);
void gettxt(byte x1,byte x2,byte y1,byte y2,byte *a);
void puttxt(byte x1,byte x2,byte y1,byte y2,byte *a);
word pow(word m,word n);
long lpow(long m,long n);
byte *itos(int number,byte *s);
byte *ltos(long number,byte *s);
long stol(byte *str);
word stoi(byte *str);
void getstr(byte *name,word maxc,word ifnum);
byte gkhit();
int  menuto(struct Menu m,word n);
word strlen(char *s);
void strcpy(byte *ss1,byte *ss2);
void memcpy(byte far *d,byte far *s,word how);
void strcat(byte *ss1,byte *ss2);
void setcursize(byte up,byte dn);
void getname(byte *name,byte *msg);
word ask(...);
void message(...);
void errmsg(byte *msg);
void terminate(byte errcode);
long cpuclock();
void delay(long msec);
void setcpuclock(long clk);
void getcurtime(struct time *t);
void setcurtime(struct time t);
void getcurdate(struct date *d);
void setcurdate(struct date d);
int  GetKey();
#endif