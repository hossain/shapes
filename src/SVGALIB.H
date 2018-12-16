//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------
// This is the Super VGA routines header file
//                                * * *

#ifndef __HTSSVGAHEAD
#define __HTSSVGAHEAD
#define FP_SEG( fp )( (unsigned )( void _seg * )( void far * )( fp ))
#define FP_OFF( fp )( (unsigned )( fp ))

//typedef unsigned char byte;
//typedef unsigned char word;

struct vgainfo {
int  VESASignature[4];   // 4 signature bytes
char VESAVersion    ;    // VESA version number
long OEMStringPtr   ;    // Pointer to OEM string
char Capabilities [4];   // Capabilities of the video environment
long VideoModePtr   ;    // Pointer to supported Super VGA modes
};
struct vesamodeinfo{
int  ModeAttributes;     // mode attributes
char WinAAttributes;     // window A attributes
char WinBAttributes;     // window B attributes
int  WinGranularity;     // window granularity
int  WinSize	   ;     // window size
int  WinASegment   ;     // window A start segment
int  WinBSegment   ;     // window B start segment
long WinFuncPtr	   ;	 // pointer to window function
int  BytesPerLine  ;     // bytes per scan line
// optional information (provided if bit D1 of ModeAttributes is set)
int  XResolution   ;     // horizontal resolution
int  YResolution   ;     // vertical resolution
char XCharSize	   ;     // character cell width
char YCharSize	   ;     // character cell height
char NumberOfPlanes;     // number of memory planes
char BitsPerPixel  ;     // bits per pixel
char NumberOfBanks ;     // number of banks
char MemoryModel   ;     // memory model type
char BankSize      ;   	 // bank size in kb
char buff[256]	   ;
};

extern int curbk,vgamem,bksize;
extern char dotcolor;

extern int cirrus,everex,acumos,paradise,tseng,trident,t8900;
extern int ativga,aheada,aheadb,oaktech,video7;
extern int chipstech,tseng4,genoa,ncr,compaq,vesa;

extern int  dactype ; //		; 0 = Normal DAC
	       //		; 1 = Sierra SC11481, SC11486, SC11488
	       //		; 2 = Sierra SC11485, SC11487, SC11489
	       //		; 3 = AT&T ATT20C491
	       //		; 4 = ACUMOS ADAC1

extern int first ;   //		;flag so whichvga() is only called once
extern int retval;   //		;first return value from whichvga()
extern int axrr;
extern long bankadr ;
extern long vesafunc;
extern int vesamodes[];
extern int buftbl[];
extern int smaxx		;//scanline of screen in pixels
extern int smaxy	 	;//height of screen in pixels
extern int scanline 		;//actual width screen in bytes
extern int ourseg	 	;//segment of screen buffer
extern int adrtbl [1024][2]  	;//offset and bank for each scanline
extern long int3adr;
void dummyvesa();
int  whichvga();
int  _t3memchk(),_cirrus(),_chkbk(),_gochk(),_isport2(),_isport1();
void mkadrtbl();
void svgamode();
void vesaset();
void setmany(char *palbuf,int begcol,int numcol);
void getmany(char *palbuf,int begcol,int numcol);
void point(int  xpos, int  ypos);
int  rdpoint(int x,int y);
void waitretrace();
#endif