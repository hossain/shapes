//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

// Definitions:
#ifndef __HTSGLOBALS
#define __HTSGLOBALS

typedef unsigned int word;
typedef unsigned char byte;
typedef void *va_list;

 char buff[41]={40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 long oldi;
 long XMS,funcptr;
 word TXT_ADDR=0xb800;
 word GRP_ADDR=0xa000;
 word xpp=0,ypp=0;
 byte attr=7;
 byte MaxXtxt=79,MaxYtxt=24;
 byte ZF=1;
 word FEC=0;
 byte far *SAddr=(byte far *)0xa0000000;
 int map,zlen,gran,sow,maxx,maxy,lx,ly,mask,sp;
 byte c1,c2,WN,chall;
 long far *kt;         //Hacking Variables
 long far int3adr,badadr;
 char key1,key2;
 word mox,moy,mbutts;
 int  momv;
 int  EndOfGame=0,TSRLoaded=0;
 char far *xbf;
 long lbf;

 //SVGA VARIABLES:
int curbk,vgamem,bksize;
char dotcolor;
char brdcolor;

int cirrus,everex,acumos,paradise,tseng,trident,t8900;
int ativga,aheada,aheadb,oaktech,video7;
int chipstech,tseng4,genoa,ncr,compaq,vesa;

int  dactype ; //               ; 0 = Normal DAC
	       //               ; 1 = Sierra SC11481, SC11486, SC11488
	       //               ; 2 = Sierra SC11485, SC11487, SC11489
	       //               ; 3 = AT&T ATT20C491
	       //               ; 4 = ACUMOS ADAC1

int first ;   //                ;flag so whichvga() is only called once
int retval;   //                ;first return value from whichvga()
int axrr;
long bankadr ;
long vesafunc;
int vesamodes[]= {
		0x100,     640, 400, 8,
		0x101,     640, 480, 8,
		0x102,     800, 600, 4,
		0x103,     800, 600, 8,
		0x104,    1024, 768, 4,
                0x105,    1024, 768, 8,
                0x106,    1280,1024, 4,
                0x107,    1280,1024, 8,
                0x10D,     320, 200,16,
                0x10E,     320, 200,16,
                0x10F,     320, 200,24,
                0x110,     640, 480,16,
                0x111,     640, 480,16,
		0x112,     640, 480,24,
                0x113,     800, 600,16,
                0x114,     800, 600,16,
                0x115,     800, 600,24,
                0x116,    1024, 768,16,
                0x117,    1024, 768,16,
                0x118,    1024, 768,24,
                0x119,    1280,1024,16,
		0x11A,    1280,1024,16,
                0x11B,    1280,1024,24,
                0};
int buftbl[]={0xA000,0xA000,0xB000,0xB800};
int smaxx               ;//scanline of screen in pixels
int smaxy               ;//height of screen in pixels
int scanline            ;//actual width screen in bytes
int ourseg              ;//segment of screen buffer
int adrtbl [1024][2]    ;//offset and bank for each scanline
float sintb[360],costb[360];
#endif