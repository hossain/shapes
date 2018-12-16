//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

//     Public Functions...

#include "PUBLIC.H"


void NEMError(){
 setscreen(0x03);
 print("Not Enough Memory! or memory error:<");
 terminate(1);
}
void GraphicError(){
 setscreen(0x03);
 print(" Graphic: Error  :( ");
 terminate(1);
}
void AnyError(char *msg){
 setscreen(0x03);
 print(msg);
 terminate(1);
}

// Font Constructors:

int BitFont::FontLoad(char *name){
 int fh,i,efs;
 fh=openf(name,0,0);
 if(!fh)return 0;
 strcpy(FontName,name);
 if(readb(fh)!='H')return 0;
 if(readb(fh)!='F')return 0;
 FontBaseSize=readw(fh);
 FontRowBytes=readw(fh);
 FontSpaceSize=1;
 FontSize=1;
 FontBytes=FontBaseSize*FontRowBytes;
 fontbits=new char[FontBytes*NOF];

 for(i=0;i<NOF;i++)
 {
	x_s[i]=readw(fh);
//      efs=((fonts[i].x_s/8)+1)*FontBaseSize;
//      fonts[i].fontbits=new char [efs];
	readf(&fontbits[i*FontBytes],FontBytes,fh);
 }
 return 1;
}
void BitFont::FontFree(){
  delete (fontbits);
 }
void BitFont::WriteChar(int x,int y,int ch){
 int i,j,k,xx;
 float f;
 int by_pl,e_s;
 by_pl=x_s[ch]/8;
 e_s=x_s[ch]%8;
 if(FontSize==0.5){
	for(j=0;j<FontBaseSize/2;j++)
	 {
	 xx=0;
	 for(i=0;i<by_pl;i++)
		for(k=0;k<8;k+=2,xx++)
			if(fontbits[ch*FontBytes+j*FontRowBytes*2+i]&(128>>k))
				point(x+xx,y+j);
	 for(k=0;k<e_s;k+=2,xx++)
		if(fontbits[ch*FontBytes+j*FontRowBytes*2+i]&(128>>k))
			point(x+xx,y+j);
	 }
	 return;
	 }
 if(FontSize==1){
	for(j=0; j<FontBaseSize; j++)
	 {
	 xx=0;
	 for(i=0;i<by_pl;i++)
		for(k=0;k<8;k++,xx++)
			if(fontbits[ch*FontBytes+j*FontRowBytes+i]&(128>>k))
				point(x+xx,y+j);
	 for(k=0;k<e_s;k++,xx++)
		if(fontbits[ch*FontBytes+j*FontRowBytes+i]&(128>>k))
			point(x+xx,y+j);
	 }
	 return;
	 }
 if(FontSize==2){}
}
void BitFont::TypeStr(int x,int y,char *str){
 int i;
 for(i=0;str[i]!=0;i++){
  WriteChar(x,y,str[i]-32);
  x+=FontSize*(x_s[str[i]-32]);
  x+=FontSpaceSize;
 }
}
void BitFont::TypeXStr(int x,int y,char *str,int mx){
 int i;
 mx+=x;
 for(i=0;str[i]!=0;i++){
  WriteChar(x,y,str[i]-32);
  x+=FontSize*(x_s[str[i]-32]);
  if(x>mx)return;
  x+=FontSpaceSize;
 }
}

void BitFont::GetStr(int x,int y,char *str,int maxn,int maxu,int bc){
 int i,u,u2,bfc;
 int curp=0;
 char ch;
 u2=x+maxu;
 ch=GetKey();
lp__:
 ch=GetKey();
 if(ZF)goto lp__;
 if(key1==13)goto entered;
 if(key1==8&&curp>0){bfc=dotcolor;dotcolor=bc;curp--;u=FontSize*(x_s[str[curp]-32])+FontSpaceSize;x-=u;boxfill(x,y,x+u,y+FontBaseSize);dotcolor=bfc;}
 if(key1>=32&&curp<maxn&&x<u2){str[curp++]=key1;WriteChar(x,y,key1-32);x+=FontSize*(x_s[key1-32])+FontSpaceSize;}
 goto lp__;
entered:
 str[curp]=0;
}
void BitFont::GetFars(int x,int y,char *str,int maxn,int maxu,int bc){
 static char et[]=" `1234567890-=qwertyuiop[]asdfghjkl;\'\\zxcvbnm,./~!@#$\%^&*()_+QWERTYUIOP{}ASDFGHJKL:\"|ZXCVBNM<>\?";
 static char ct[]=" •‚ƒ„…†‡ˆ‰€-=®¬™ìêèäû¡Ÿ›ª¨ş“ó—÷õîğ¦à¯¥¤£¢ø/ ”!@#$\%:Šx()‹+­«˜ëéåáù šœ©§ü’ñ‘–öôíïæèâäòû<>Œ";
 int i,u,u2,bfc;
 int curp;
 char ch;
 u2=x-maxu;
 curp=maxn-1;
lp__:
 ch=GetKey();
 if(ZF)goto lp__;
 if(key1==13) goto entered;
 if(key1==8&&curp<maxn-1) {bfc=dotcolor; dotcolor=bc; curp++; u=FontSize*(x_s[str[curp]-32])+FontSpaceSize; boxfill(x,y,x+u,y+FontBaseSize); x+=u; dotcolor=bfc; }
 if(key1>=32&&curp>0&&x>u2) {for(i=0;i<95;i++)if(key1==et[i]){str[curp--]=ct[i];break;} x-=FontSize*(x_s[ct[i]-32])+FontSpaceSize; WriteChar(x,y,ct[i]-32); }
 goto lp__;
entered:
 u=maxn-curp-1;
 for(i=0;i<u;i++)str[i]=str[i+curp+1];
 str[i]=0;
}
int BitFont::StrSize(char *str){
 int i,u=0;
 for(i=0;str[i]!=0;i++) u+=FontSize*(x_s[str[i]-32])+FontSpaceSize;
 return u;
}
///////////////////// Palette:
char *PaletteLoad(char *name,char *pal){
 int ph;
 ph=openf(name,0,0);
 if(!ph)return 0;
 readf(pal,768,ph);
 return pal;
 }
void FadeOut(unsigned int speed){
 byte far *pale;
 int i,j;
 pale=new byte [768];
 if(!pale)NEMError();
 getmany(pale,0,256);/*
 for(i=0;i<63;i++){
  for(j=0;j<768;j++)if(pale[j]>1)pale[j]-=2;
  for(j=0;j<speed;j++);
  waitretrace();
  setmany(pale,0,256);
//  waitretrace();
  }                    */
  for(i=0;i<8;i++){
   for(j=0;j<768;j++)if(pale[j]>=1)pale[j]>>=1;
   delay(speed*1000);
   waitretrace();
   setmany(pale,0,256);
   }
}
void FadeIn(char far *palet,unsigned int speed){
 byte far *pale;
 int i,j;
 float f;
 pale=new byte [768];
 if(!pale)NEMError();
 for(i=0;i<768;i++)pale[i]=0;
 setmany(pale,0,256);
/* for(i=0;i<64;i++){
  for(j=0;j<768;j++)if(pale[j]<palet[j]-1)pale[j]+=2;
//  for(i=0;i<speed;i++)delay(5);
  waitretrace();
  setmany(pale,0,256);
//  waitretrace();
  }*/
  for(i=0;i<1000;i++){
   i+=i;
   for( j = 0 ; j < 768 ; j ++ ) { f=palet[j]; f*=i; f/=1000; pale[j] = f; }
   delay(speed*5000);
   waitretrace();
   setmany(pale,0,256);
   }
  setmany(palet,0,256);
}

void InitSinCosTan(){
 int i;
 for(i=0;i<360;i++) sintb[i]=sin(RAD(i));
 for(i=0;i<360;i++) costb[i]=cos(RAD(i));
// for(i=0;i<360;i++) tantb[i]=tan(RAD(i));
 }
void Poly::PolySet(int num,int n,int col,float *dots,int c){
 int i;
 number=num;
 convex=c;
 nod=n;
 color=col;
 points=new float[n*2+2];
 if(!points){setscreen(3);print("Not Enough Ram for Polygons!");terminate(1);}
 for(i=0;i<n*2+2;i++) points[i]=dots[i];
 mancx=dots[n*2+2]; mancy=dots[n*2+3];
 size=1;
 centerx=(pmaxx()+pminx())/2;
 centery=(pmaxy()+pminy())/2;
// InitSinCosTan();
 PolyMove(0,0);
}
void Poly::PolyDraw(){
 int i;float x1,x2,y1,y2;
 dotcolor=color;
 for(i=0;i<nod;i++){
  x1=points[i*2];x2=points[i*2+2];
  y1=points[i*2+1];y2=points[i*2+3];
  line(x1+xpos,y1+ypos,x2+xpos,y2+ypos);
  }
}
//---------------------------------- Fill Convex Poly . .  .   .    .     .
void Poly::FillConvexPoly(){
 int x=topdot(),endy;
 int sv;
 float lx1,ly1,lx2,ly2;
 float rx1,ry1,rx2,ry2;
 int y,ey,direct;
 int lx,rx;
 int lc,rc;
 int v1;
 double lm,rm;
 dotcolor=color;
 x=topdot();lc=x,rc=x;
 y=points[x*2+1];
 rx1=points[x*2],ry1=y;
 rc=next(rc);
 rx2=points[rc*2],ry2=points[rc*2+1];
 if(rx1!=rx2) rm=(ry2-ry1)/(rx2-rx1); else rm=19999;
 lx1=rx1,ly1=ry1;
 lc=prev(lc);
 lx2=points[lc*2],ly2=points[lc*2+1];
 if(lx1!=lx2) lm=(ly2-ly1)/(lx2-lx1); else lm=19999;
 if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
 if(ly2==ry2){direct=2;ey=ly2;}
 endy=pmaxy();
 while(y<endy){
  while(y<ey){
   if(y+ypos>=smaxy)return;
   if(y>=endy-1)return;
   if(y+ypos>=0){
    if(lm==19999)lx=lx1;else lx=lx1+(float(y)-ly1)/lm;
    if(rm==19999)rx=rx1;else rx=rx1+(float(y)-ry1)/rm;
    lx+=xpos,rx+=xpos;
    if(lx!=rx){
     if(lx>639)lx=639;
     if(rx>639)rx=639;
     if(rx<0)rx=0;
     if(lx<0)lx=0;
     if(lx<rx)boxfill(lx,y+ypos,rx,y+ypos);
     else boxfill(rx,y+ypos,lx,y+ypos);
     }
    }
   y++;
   }
  if(y>=endy)return;
  if(ly2==ry2){
     if(lx2!=rx2){
      if(lx2<rx2)boxfill(lx2+xpos,y+ypos,rx2+xpos,y+ypos);
      else boxfill(rx2+xpos,y+ypos,lx2+xpos,y+ypos);
      }
   y++;
   }
  if(direct==1 || direct==2){
   lx1=lx2,ly1=ly2;
   lc=prev(lc);
   lx2=points[lc*2],ly2=points[lc*2+1];
   if(lx1!=lx2) lm=double(ly2-ly1)/double(lx2-lx1); else lm=19999;
   }
  if(direct==0 || direct==2){
   rx1=rx2,ry1=ry2;
   rc=next(rc);
   rx2=points[rc*2],ry2=points[rc*2+1];
   if(rx1!=rx2) rm=double(ry2-ry1)/double(rx2-rx1); else rm=19999;
   }
  if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
  if(ly2==ry2){direct=2;ey=ly2;}
  }
}
float Poly::pminy(){
 float m=points[1];
 for(int i=1;i<nod;i++) if(points[i*2+1]<m)m=points[i*2+1];
 return m;
}
float Poly::pmaxy(){
 float m=points[1];
 for(int i=1;i<nod;i++) if(points[i*2+1]>m)m=points[i*2+1];
 return m;
}
float Poly::pmaxx(){
 float m=points[0];
 for(int i=1;i<nod;i++) if(points[i*2]>m)m=points[i*2];
 return m;
}
float Poly::pminx(){
 float m=points[0];
 for(int i=1;i<nod;i++) if(points[i*2]<m)m=points[i*2];
 return m;
}
int Poly::topdot(){
 int m=0;
 for(int i=1;i<nod;i++) if(points[i*2+1]<points[m*2+1])m=i;
 return m;
}
int Poly::botdot(){
 int m=0;
 for(int i=1;i<nod;i++) if(points[i*2+1]>points[m*2+1])m=i;
 return m;
}
int Poly::rgtdot(){
 int m=0;
 for(int i=1;i<nod;i++) if(points[i*2]>points[m*2])m=i;
 return m;
}
int Poly::lftdot(){
 int m=0;
 for(int i=1;i<nod;i++) if(points[i*2]<=points[m*2])m=i;
 return m;
}
void Poly::RotatePoly(int deg){
 int i;
 float nx,ny;
 float x,y;
 for(i=0;i<=nod;i++){
  points[i*2]-=centerx;
  points[i*2+1]-=centery;
  }
 mancx-=centerx,mancy-=centery;
 nx=DotXRot(deg,0,0,centerx,centery);
 ny=DotYRot(deg,0,0,centerx,centery);
 for(i=0;i<=nod;i++) {
  x=points[i*2],y=points[i*2+1];
  points[i*2]=(x-centerx)*costb[deg]-(y-centery)*sintb[deg]+centerx-nx;
  points[i*2+1]=(x-centerx)*sintb[deg]+(y-centery)*costb[deg]+centery-ny;
  }
  x=mancx,y=mancy;
 mancx=(x-centerx)*costb[deg]-(y-centery)*sintb[deg]+centerx-nx;
 mancy=(x-centerx)*sintb[deg]+(y-centery)*costb[deg]+centery-ny;
 for(i=0;i<=nod;i++){
  points[i*2]+=centerx;
  points[i*2+1]+=centery;
  }
 mancx+=centerx,mancy+=centery;
 centerx=(pmaxx()+pminx())/2;
 centery=(pmaxy()+pminy())/2;
}
void Poly::MirrorPoly(){
 int i;
 centerx=(pmaxx()+pminx())/2;
 centery=(pmaxy()+pminy())/2;
 for(i=0;i<=nod;i++)
  points[i*2]=(centerx-points[i*2])+centerx;
 mancx=(centerx-mancx)+centerx;
}
void Poly::ResizePoly(float newsize){
 int i,c;c=nod*2+2;
 for(i=0;i<c;i++)
  points[i]=float(points[i])*newsize;
 mancy=float(mancy)*newsize;
 mancx=float(mancx)*newsize;
 centerx=(pmaxx()+pminx())/2;
 centery=(pmaxy()+pminy())/2;
}
void Poly::CenterResize(float newsize){
 int i;
 for(i=0;i<=nod;i++){
  points[i*2]=(points[i*2]-centerx)*newsize+centerx;
  points[i*2+1]=(points[i*2+1]-centery)*newsize+centery;
  }
 mancx=(mancx-centerx)*newsize+centerx;
 mancy=(mancy-centery)*newsize+centery;
 centerx=(pmaxx()+pminx())/2;
 centery=(pmaxy()+pminy())/2;
}

void Poly::FillPoly(){
 int lx[10],ly[10];
 float ms [100];
 int adx[100];
 int tys[100][2];
 int y,endy;
 int n,i;
 int sx,x,x1,y1,x2,y2;
 dotcolor=color;
 for(i=0;i<=nod;i++){
	x1=points[i*2];y1=points[i*2+1];
	x2=points[i*2+2];y2=points[i*2+3];
	if(y1!=y2) {
	 ms[i]=float(x2-x1)/float(y2-y1);
	 if(y1>y2){tys[i][0]=y2;tys[i][1]=y1;adx[i]=x2;}else {tys[i][0]=y1;tys[i][1]=y2;adx[i]=x2;}
	 }
	}
 y=pminy(),endy=pmaxy();
 sx=lftdot();
 while(y<endy&&y<smaxy-ypos){
   n=0;x=sx;
   for(i=0;i<nod;i++){
    if(tys[x][0]<=y && y<tys[x][1])
	{lx[n]=adx[x]+float(y)*ms[x];n++;}
    x=next(x);
    }
   if(y+ypos>=0){
    for(i=0;i<n;i+=2)
     if(lx[i]!=lx[i+1]) boxfill(lx[i]+xpos,y+ypos,lx[i+1]+xpos,y+ypos);
    }
   y++;
  }
}
int Poly::CheckFillPoly(int bk){
 int i,x=topdot(),endy;
 int lx1,ly1,lx2,ly2;
 int rx1,ry1,rx2,ry2;
 int y,ey,direct;
 int lx,rx;
 int lc,rc;
 int v1,fdd;
 double lm,rm;
 dotcolor=color;
 x=topdot();lc=x,rc=x;
 y=points[x*2+1];
 rx1=points[x*2],ry1=y;
 rc=next(rc);
 rx2=points[rc*2],ry2=points[rc*2+1];
 if(rx1!=rx2) rm=double(ry2-ry1)/double(rx2-rx1); else rm=19999;
 lx1=rx1,ly1=ry1;
 lc=prev(lc);
 lx2=points[lc*2],ly2=points[lc*2+1];
 if(lx1!=lx2) lm=double(ly2-ly1)/double(lx2-lx1); else lm=19999;
 if(ly2<ry2){direct=1;ey=ly2;} else {direct=0;ey=ry2;}
 if(ly2==ry2){direct=2;ey=ly2;}
 endy=pmaxy();
 fdd=0;
 while(y<endy&&y<smaxy-ypos){
  y++;
  while(y<ey&&y<smaxy-ypos){
   if(y+ypos>=0){
    if(lm==19999)lx=lx1;else lx=lx1+double(y-ly1)/lm;
    if(rm==19999)rx=rx1;else rx=rx1+double(y-ry1)/rm;
    if(lx!=rx&&y<ey-2){
	if(lx>rx){v1=lx;lx=rx;rx=v1;}
	if( (rx-lx) > 4 )  for(i=lx+3;i<rx-2;i++) if(bk!=rdpoint(i+xpos,y+ypos)) fdd++;
	}
    }
   y++;
   }
  if(direct==1 || direct==2){
   lx1=lx2,ly1=ly2; lc=prev(lc);
   lx2=points[lc*2],ly2=points[lc*2+1];
   if(lx1!=lx2) lm=double(ly2-ly1) / double(lx2-lx1); else lm=19999;
   }
  if(direct==0 || direct==2){
   rx1=rx2,ry1=ry2; rc=next(rc);
   rx2=points[rc*2], ry2=points[rc*2+1];
   if(rx1!=rx2) rm=double(ry2-ry1) / double(rx2-rx1); else rm=19999;
   }
  if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
  if(ly2==ry2){direct=2;ey=ly2;}
  }
 if(!fdd)return 1;
 return 0;
}
void Poly::PutPolyPic(Image pic,int px,int py){
 int x=topdot(),endy;
 int sv;
 float lx1,ly1,lx2,ly2;
 float rx1,ry1,rx2,ry2;
 int y,ey,direct;
 int lx,rx;
 int lc,rc;
 int v1;
 double lm,rm;
 dotcolor=color;
 px=px,py=ypos-py;
 x=topdot();lc=x,rc=x;
 y=points[x*2+1];
 rx1=points[x*2],ry1=y;
 rc=next(rc);
 rx2=points[rc*2],ry2=points[rc*2+1];
 if(rx1!=rx2) rm=(ry2-ry1)/(rx2-rx1); else rm=19999;
 lx1=rx1,ly1=ry1;
 lc=prev(lc);
 lx2=points[lc*2],ly2=points[lc*2+1];
 if(lx1!=lx2) lm=(ly2-ly1)/(lx2-lx1); else lm=19999;
 if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
 if(ly2==ry2){direct=2;ey=ly2;}
 endy=pmaxy();
 while(y<endy){
  while(y<ey){
   if(y+ypos>=smaxy)return;
   if(y>=endy-1)return;
   if(y+ypos>=0){
    if(lm==19999)lx=lx1;else lx=lx1+(float(y)-ly1)/lm;
    if(rm==19999)rx=rx1;else rx=rx1+(float(y)-ry1)/rm;
    lx+=xpos,rx+=xpos;
    if(lx!=rx){
     if(lx>639)lx=639;
     if(rx>639)rx=639;
     if(rx<0)rx=0;
     if(lx<0)lx=0;
     if(lx<rx)pic.PutCutLine(lx,y+ypos,y+py,lx-px,rx-px);
     else pic.PutCutLine(rx,y+ypos,y+py,rx-px,lx-px);
     }
    }
   y++;
   }
  if(y>=endy)return;
  if(ly2==ry2){
     if(lx2!=rx2){
      if(lx2<rx2)pic.PutCutLine (lx2+xpos, y+ypos, y+py, lx2+xpos-px, rx2+xpos-px);
      else pic.PutCutLine (rx2+xpos, y+ypos, y+py, rx2+xpos-px, lx2+xpos-px);
      }
   y++;
   }
  if(direct==1 || direct==2){
   lx1=lx2,ly1=ly2;
   lc=prev(lc);
   lx2=points[lc*2], ly2=points[lc*2+1];
   if(lx1!=lx2) lm=double(ly2-ly1)/double(lx2-lx1); else lm=19999;
   }
  if(direct==0 || direct==2){
   rx1=rx2,ry1=ry2;
   rc=next(rc);
   rx2=points[rc*2],ry2=points[rc*2+1];
   if(rx1!=rx2) rm=double(ry2-ry1)/double(rx2-rx1); else rm=19999;
   }
  if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
  if(ly2==ry2){direct=2;ey=ly2;}
  }
}
void Poly::PutPolyInPic(Image pic,int c){
 int x=topdot(),endy;
 int sv;
 float lx1,ly1,lx2,ly2;
 float rx1,ry1,rx2,ry2;
 int y,ey,direct;
 int lx,rx;
 int px,py;
 int lc,rc;
 int v1;
 double lm,rm;
 dotcolor=color;
 px=pminx(),py=pminy();
 x=topdot();lc=x,rc=x;
 y=points[x*2+1];
 rx1=points[x*2],ry1=y;
 rc=next(rc);
 rx2=points[rc*2],ry2=points[rc*2+1];
 if(rx1!=rx2) rm=(ry2-ry1)/(rx2-rx1); else rm=19999;
 lx1=rx1,ly1=ry1;
 lc=prev(lc);
 lx2=points[lc*2],ly2=points[lc*2+1];
 if(lx1!=lx2) lm=(ly2-ly1)/(lx2-lx1); else lm=19999;
 if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
 if(ly2==ry2){direct=2;ey=ly2;}
 endy=pmaxy();
 while(y<endy){
  while(y<ey){
//   if(y>=endy-1)return;
   if(y+ypos>=0){
    if(lm==19999)lx=lx1;else lx=lx1+(float(y)-ly1)/lm;
    if(rm==19999)rx=rx1;else rx=rx1+(float(y)-ry1)/rm;
    if(lx<rx) pic.PutLine2Image(y-py, lx-px, rx-px, c );
    if(rx<lx) pic.PutLine2Image(y-py, rx-px, lx-px, c );
    }
   y++;
   }
  if(y>=endy)return;
  if(ly2==ry2){
     if(lx2<rx2) pic.PutLine2Image (y-py, lx2-px, rx2-px, c );
     if(rx2<lx2) pic.PutLine2Image (y-py, rx2-px, lx2-px, c );
   y++;
   }
  if(direct==1 || direct==2){
   lx1=lx2,ly1=ly2;
   lc=prev(lc);
   lx2=points[lc*2], ly2=points[lc*2+1];
   if(lx1!=lx2) lm=double(ly2-ly1)/double(lx2-lx1); else lm=19999;
   }
  if(direct==0 || direct==2){
   rx1=rx2,ry1=ry2;
   rc=next(rc);
   rx2=points[rc*2],ry2=points[rc*2+1];
   if(rx1!=rx2) rm=double(ry2-ry1)/double(rx2-rx1); else rm=19999;
   }
  if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
  if(ly2==ry2){direct=2;ey=ly2;}
  }
}
void Poly::Conduction(int x,int y){
 int i;
 for(i=0;i<=nod;i++)
  {
  points[i*2]+=x;
  points[i*2+1]+=y;
  }
 mancx+=x,mancy+=y;
 centerx=(pmaxx()+pminx())/2;
 centery=(pmaxy()+pminy())/2;
}
void Poly::XorPoly(){
 int x=topdot(),endy;
 int sv;
 float lx1,ly1,lx2,ly2;
 float rx1,ry1,rx2,ry2;
 int y,ey,direct;
 int lx,rx;
 int lc,rc;
 int v1;
 double lm,rm;
 dotcolor=color;
 x=topdot();lc=x,rc=x;
 y=points[x*2+1];
 rx1=points[x*2],ry1=y;
 rc=next(rc);
 rx2=points[rc*2],ry2=points[rc*2+1];
 if(rx1!=rx2) rm=(ry2-ry1)/(rx2-rx1); else rm=19999;
 lx1=rx1,ly1=ry1;
 lc=prev(lc);
 lx2=points[lc*2],ly2=points[lc*2+1];
 if(lx1!=lx2) lm=(ly2-ly1)/(lx2-lx1); else lm=19999;
 if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
 if(ly2==ry2){direct=2;ey=ly2;}
 endy=pmaxy();
 while(y<endy){
  while(y<ey){
   if(y+ypos>=smaxy)return;
   if(y>=endy-1)return;
   if(y+ypos>=0){
    if(lm==19999)lx=lx1;else lx=lx1+(float(y)-ly1)/lm;
    if(rm==19999)rx=rx1;else rx=rx1+(float(y)-ry1)/rm;
    lx+=xpos,rx+=xpos;
    if(lx!=rx){
     if(lx>639)lx=639;
     if(rx>639)rx=639;
     if(rx<0)rx=0;
     if(lx<0)lx=0;
     if(lx<rx)xorbox(lx,y+ypos,rx,y+ypos);
     else xorbox(rx,y+ypos,lx,y+ypos);
     }
    }
   y++;
   }
  if(y>=endy)return;
  if(ly2==ry2){
     if(lx2!=rx2){
      if(lx2<rx2)xorbox(lx2+xpos,y+ypos,rx2+xpos,y+ypos);
      else xorbox(rx2+xpos,y+ypos,lx2+xpos,y+ypos);
      }
   y++;
   }
  if(direct==1 || direct==2){
   lx1=lx2,ly1=ly2;
   lc=prev(lc);
   lx2=points[lc*2],ly2=points[lc*2+1];
   if(lx1!=lx2) lm=double(ly2-ly1)/double(lx2-lx1); else lm=19999;
   }
  if(direct==0 || direct==2){
   rx1=rx2,ry1=ry2;
   rc=next(rc);
   rx2=points[rc*2],ry2=points[rc*2+1];
   if(rx1!=rx2) rm=double(ry2-ry1)/double(rx2-rx1); else rm=19999;
   }
  if(ly2<ry2){direct=1;ey=ly2;}else {direct=0;ey=ry2;}
  if(ly2==ry2){direct=2;ey=ly2;}
  }
}

struct Picture mouc,moub;
word mux_,muy_;

void InitCursor(){
 mouc.ras=new char [256];
 mouc.x=16,mouc.y=16;
 moub.ras=new char [256];
 moub.x=16,moub.y=16;
 }
void LoadCursor(){
 getpicture(0,0,mouc);
 setmpos(300,200);
 mux_=300,muy_=200;
}
void DeleteCursor(){
 delete ( mouc.ras ) ;
}
void ShowMouse(){
 getpicture(mux_,muy_,moub);
 putpictfore(mux_,muy_,mouc);
}
void RemoveMouse(){
 putpict(mux_,muy_,moub);
}
void Mouser(){
 if(mux_==mox && muy_==moy) {momv=0;return;}
 RemoveMouse();
 mux_=mox,muy_=moy;
 ShowMouse();
 momv=1;
}
