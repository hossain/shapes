//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

// Public Graphic Routines Header File
// this file contents: Fonts,Basic Shapes,Fillings,...
//---------------------------------------------------------------------------
#ifndef __HTSPUBLIC
#define __HTSPUBLIC

#include "SVGALIB.H"
#include "DEVICE.H"
#include "SCREEN.H"
#include <math.h>
#define NOF 223
#define RAD(x) float(x*3.141592)/180
#define DotXRot(t,x,y,ox,oy) (float(x-ox)*costb[t]-float(y-oy)*sintb[t])+ox
#define DotYRot(t,x,y,ox,oy) (float(x-ox)*sintb[t]+float(y-oy)*costb[t])+oy

void NEMError();
void GraphicError();
void AnyError(char *msg);

//Bit Map Fonts Class:
class BitFont {
private:
        int  x_s[NOF];
        char *fontbits;
        int  FontBytes;
public:
        char FontName[18];
        int  FontBaseSize;
        int  FontRowBytes;
	int  FontSpaceSize;
        float FontSize;
        int  FontLoad(char *filename);
        void WriteChar(int x,int y,int ch);
	void TypeStr(int x,int y,char *str);
	void TypeXStr(int x,int y,char *str,int mx);
	void GetStr(int x,int y,char *str,int maxn,int maxu,int bc);
	void GetFars(int x,int y,char *str,int maxn,int maxu,int bc);
	int  StrSize(char *str);
	void FontFree();
};
///////////////////////////////////////////////////////////////BitFont class

char *PaletteLoad(char *name,char *pal);
void FadeOut(unsigned int speed);
void FadeIn(char far *inpalt,unsigned int speed);

void bline(int x1,int y1,int x2,int y2,void (*func)(int x,int y)) ;
int  accept();
void savescreen(char *m);
void restorescreen(char *m);
void getcurpos(char *a,char *b);
void box(int x1,int y1,int x2,int y2);
void boxfill(int x1,int y1,int x2,int y2);
void xorbox(int x1,int y1,int x2,int y2);
void circle(int x,int y,int r,double ypx);
void xcircle(int x,int y,int r,double ypx);
void line(int x1,int y1,int x2,int y2);

void InitSinCosTan();
extern float sintb[],costb[];

struct Picture {
 int bypp,x,y;
 char far *ras;
};
extern char brdcolor;
void putpict (int x,int y,struct Picture pic);
void putpictfore (int x,int y,struct Picture pic);
int  getpict (int x1,int y1,int x2,int y2,struct Picture& pic);
void getpicture(int x1,int y1,struct Picture pic);
void fillhor(int ,int ),fillver(int ,int );
int filler(int ,int );


extern char far *xbf;
extern long lbf;

class Image {   // XMS storation & SVGA doter...
private:
 long isz;
 int bypp,ixs,iys; //bytes per pixel...
 int bpb; // bytes per Block...
 int hmb; // How many blocks
 int lpb; // lines per block
 int lablk;// last block size
 word hnd;
public:
 char *palt;
 int  Xsz(){return ixs;}
 int  Ysz(){return iys;}
 int  BypBlk(){return bpb;}
 int  handle(int h){return hnd;}
 char *Palette(){return palt;}
 int  MakeImage(int x,int y);
 void Disturbe();
 int  LoadImage(char *filename);
 int  LoadHI(int fileh);
 int  LoadHIS(char *fn,int w,int sc,long eapi);
 int  LoadBMP(char *filename);
 int  LoadPCX(char *filename);
 int  LoadGIF(char *filename);
 int  SaveHI(char *filename);
 int  SaveBMP(char *filename);
 int  SavePCX(char *filename);
 int  SaveGIF(char *filename);
 int  LoadPalette(int h);
 void SetPalette(){ setmany(palt,0,256); }
 int  GetImage(int x1,int y1,int x2,int y2);
 void PutImage(int x,int y);
 void PutFore(int x1,int y1);
 void PutDoubleSize(int x,int y);
 void PutXORFore(int x1,int y1);
 void PutCutFore(int x1,int y1,int ix1,int iy1,int ix2,int iy2);
 void PutCutImage(int x,int y,int x1,int y1,int x2,int y2);
 void PutCutLine(int x1,int y1,int iy,int ix1,int ix2);
 void PutPicIn(int x,int y,struct Picture pic);
 int  GetPicIn(int x1,int y1,int x2,int y2,struct Picture& pic);
 int  Image2Pic(struct Picture& pic);
 int  Pic2Image(struct Picture pic);
 void ImageInImage(int x,int y,Image img);
 int  ImageOutImage(int x,int y,Image& img);
 void PutXORImage(int x,int y);
 void PutORImage(int x,int y);
 void ResizeImage(float newsize);
 void ImageCopy(Image& img);
 void RotateImage(int deg);
 void puredata(int x,int y,char *data);
 void putpicpix(int x,int y);
 void PutLine2Image(int y,int x1,int x2,char c);
 void FillWith(char c);
 void ChangePalette(char far pal[768]);
 };
//////////////////////////////////////////////////////////////////Image Class

//Polygon Functions:
class Poly {
 private:
  int  convex;
  float xpos,ypos;
  int  color;
  int  nod;
  float size;
  float centerx,centery;
  float *points;    // x0,y0,x1,y1,x2,y2,...
  int  topdot(),botdot(),lftdot(),rgtdot();
  int  next(int n){n++;if(n==nod)return 0;return n;}
  int  prev(int n){if(n==0)return nod-1;n--;return n;}
 public:
  float mancx,mancy;
  int  number;
  void PolySet(int num,int n,int col,float *dots,int c);
  int xcent(){return centerx+xpos;}
  int ycent(){return centery+xpos;}
  int maxx(){return xpos+pmaxx();}
  int maxy(){return ypos+pmaxy();}
  int minx(){return xpos+pminx();}
  int miny(){return ypos+pminy();}
  float polx(int n){return points[n*2];}
  float poly(int n){return points[n*2+1];}
  void RemovePoly(){delete points;}
  void PolyDraw();      // Graphic Effect
  void PolyMove(int x,int y){xpos=x;ypos=y;}
  void Conduction(int x,int y);
  int  PolyX(){return xpos;}
  int  PolyY(){return ypos;}
  float pminy(),pmaxy(),pminx(),pmaxx();
  void FillConvexPoly();           // Graphic Effect
  void XorPoly();
  void PutPolyPic(Image pic,int px,int py);
  void PutPolyInPic(Image pic,int c);
  void FillPoly();
  void FillPolyDraw(){PolyDraw();if(convex)FillConvexPoly();else FillPoly();}
  int  CheckFillPoly(int bk);
  void RotatePoly(int deg);
  void MirrorPoly();
  void RotateRound(int deg,int x,int y){centerx=x;centery=y;RotatePoly(deg);}
  void CenterResize(float nsz);
  void ResizePoly(float newsize);
  void ChangeColor(int newcol){color=newcol;}
  };
//////////////////////////////////////////////////////////////////Poly Class


extern int momv;

void InitCursor();
void LoadCursor();
void DeleteMouse();
void ShowMouse();
void RemoveMouse();
void Mouser();

#endif
