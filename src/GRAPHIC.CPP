//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

// This module contains graphic basic routins.

#include "PUBLIC.H"

void bline(int x1,int y1,int x2,int y2,void (*func)(int x,int y)) {
 int t,d;
 int xerr=0,yerr=0,dx,dy, incx,incy;
 dx=x2-x1; dy=y2-y1;
 if(dx>0)incx=1;  else if(dx==0)incx=0;  else incx=-1;
 if(dy>0)incy=1;  else if(dy==0)incy=0;  else incy=-1;
 dx=abs(dx); dy=abs(dy);
 if(dx>dy) d=dx;  else d=dy;
 for(t=0;t<d+1;t++){  (*func)(x1,y1); xerr+=dx;  yerr+=dy;
  if(xerr>d){   xerr-=d;   x1+=incx;  }
  if(yerr>d){   yerr-=d;   y1+=incy;  }
}}
int accept(){
 char ch=0;
here:
 ch=getch();
 if(ch=='y'|| ch=='Y' || ch=='n'|| ch=='N')goto there;
 goto here;
there:
 if(ch=='y' ||  ch=='Y') return 1;
 if(ch=='n' ||  ch=='N') return 0;
 goto there;
}

void savescreen(char *m){
 int i;
 char far *p=(char far *)0xb8000000;
 for(i=0;i<4000;i++)  m[i]=*(p++);
 getcurpos(&m[4000],&m[4001]);
}

void restorescreen(char *m){
 int i;
 char far *p=(char far *)0xb8000000;
 for(i=0;i<4000;i++)  *(p++)=m[i];
 goxy(m[4001],m[4000]);
}

void getcurpos(char *a,char *b){
 char  vc1,vc2;
 asm{
  mov ah,3
  mov bh,0
  int 0x10
  mov vc1,dh
  mov vc2,dl
  }
 *a=vc1;
 *b=vc2;
}

void box(int x1,int y1,int x2,int y2){
if(x1>=0&&x1<smaxx) boxfill(x1,y1,x1,y2);
if(y1>=0&&y1<smaxy) boxfill(x1,y1,x2,y1);
if(y2>=0&&y2<smaxy) boxfill(x1,y2,x2,y2);
if(x2>=0&&x2<smaxx) boxfill(x2,y1,x2,y2);
}

void putpict(int x1,int y1,struct Picture pic){
	int x,sv;
	int x2,y2,sx,sy;
	x2=x1+pic.x,y2=y1+pic.y;
	if(x2<x1){sv=x1;x1=x2;x2=sv;}
	if(y2<y1){sv=y1;y1=y2;y2=sv;}
	sx=x2-x1,sy=y2-y1;
	if(x1<0)x1=0;   if(y1<0)y1=0;
	if(x2>=smaxx)x2=smaxx-1;
	if(y2>=smaxy)y2=smaxy-1;
	y2=min(y2,smaxy);
	int tx,ty,nx,ny;
	nx=x2-x1+1,ny=y2-y1+1;
	tx=nx-sx;
	int k,i,j;
	for(k=0,j=y1;j<y2;j++) {
		for(i=x1;i<x2;i++) {
			dotcolor=pic.ras[k++];
			point(i,j);
			}
		k+=tx;
		}
}
void putpictfore(int x1,int y1,struct Picture pic){
	int x,sv;
	int x2,y2,sx,sy;
	x2=x1+pic.x,y2=y1+pic.y;
	if(x2<x1){sv=x1;x1=x2;x2=sv;}
	if(y2<y1){sv=y1;y1=y2;y2=sv;}
	sx=x2-x1,sy=y2-y1;
	if(x1<0)x1=0;   if(y1<0)y1=0;
	if(x2>=smaxx)x2=smaxx-1;
	if(y2>=smaxy)y2=smaxy-1;
	int tx,ty,nx,ny;
	nx=x2-x1+1,ny=y2-y1+1;
	tx=nx-sx;
	int k,i,j;
	for(k=0,j=y1;j<y2;j++) {
		for(i=x1;i<x2;i++)     {
			dotcolor=pic.ras[k++];
			if(!dotcolor)continue;
			point(i,j);
			}
		k+=tx;
		}
}
int  getpict(int x1,int y1,int x2,int y2,struct Picture& pic){
	int x,sv,sx,sy;
	sx=x2-x1,sy=y2-y1;
	pic.x=x2-x1,pic.y=y2-y1;
	x=pic.x*pic.y;
	pic.ras=new char[x];
	if(!pic.ras)return 0;
	int tx,ty,nx,ny;
	nx=x2-x1+1,ny=y2-y1+1;
	tx=nx-sx;
	int k,i,j;
	for(k=0,j=y1;j<=y2;j++,k+=tx)
		for(i=x1;i<=x2;i++)
			pic.ras[k++]=rdpoint(i,j);
	return 1;
}
void getpicture(int x1,int y1,struct Picture pic){
	int x2,y2;
	x2=x1+pic.x,y2=y1+pic.y;
	int k,i,j;
	for(k=0,j=y1;j<=y2;j++)
		for(i=x1;i<=x2;i++)
			pic.ras[k++]=rdpoint(i,j);
}
void boxfill(int x1,int y1,int x2,int y2){
	int x,sv;
	if(x2<x1){sv=x1;x1=x2;x2=sv;}
	if(y2<y1){sv=y1;y1=y2;y2=sv;}
	if(x1<0)x1=0;   if(y1<0)y1=0;
	if(x2>=smaxx)x2=smaxx-1;
        if(y2>=smaxy)y2=smaxy-1;
        y2=min(y2,smaxy);
        int nx,ny;nx=x2-x1+1,ny=y2-y1+1;
//      int jj;jj=smaxx-nx;
//      for(j=y1;j<=y2;j++)
//      for(i=x1;i<=x2;i++)
//      point(i,j);
asm{
        mov     si,[x1]
        mov     es,[ourseg]
        mov     bx,[y1]
        mov     dx,si
        shl     bx,1
        shl     bx,1
        mov     di,word ptr adrtbl[bx]
        add     dx,di
        mov     si,di
        mov     ax,word ptr adrtbl[bx+2]
        mov     di,ax
        adc     ax,0
        mov     bx,dx
        call    bankadr
        mov     cx,[ny]
}
LP_Y:   asm{
        push    cx
        mov     cx,[nx]
        mov     ax,[x1]
        mov     [x],ax
        }
LP_X:   asm{
        mov     al,dotcolor
        mov     es:[bx],al
        inc     bx
        inc     x
        mov     dx,[x]
        add     dx,si
        mov     ax,di
        adc     ax,0
        cmp     ax,[curbk]
        jnz     incbank
        loop    LP_X

        inc     [y1]
        mov     dx,[x1]
        mov     si,[y1]
        shl     si,1
        shl     si,1
        mov     di,word ptr adrtbl[si]
        mov     ax,word ptr adrtbl[si+2]
        mov     si,di
        add     dx,di
        mov     bx,dx
        mov     di,ax
        adc     ax,0
        cmp     ax,[curbk]
        jnz     chgbank
        }
GhlZ:   asm{
        pop     cx
        loop    LP_Y
        }
        return;
incbank:asm{
        call    bankadr
        loop    LP_X
        }
chgbank:asm{
        call    bankadr
        jmp     GhlZ
        }
}

void xorbox(int x1,int y1,int x2,int y2){
//      register int i,j;
	int x,sv;
//	if((x1<0&&x2<0)||(y1<0&&y2<0))return;
	if(x1>x2) { sv=x2; x2=x1; x1=sv; }
	if(y1>y2) { sv=y1; y1=y2; y2=sv; }
	if(x1<0)x1=0;
	if(y1<0)y1=0;
	if(x2>=smaxx) x2=smaxx-1;
	if(y2>=smaxy) y2=smaxy-1;
	int nx,ny;nx=x2-x1+1,ny=y2-y1+1;
//      int jj;jj=smaxx-nx;
//      for(j=y1;j<=y2;j++)
//      for(i=x1;i<=x2;i++)
//      point(i,j);
asm{
        mov     si,[x1]
        mov     es,[ourseg]
        mov     bx,[y1]
        mov     dx,si
        shl     bx,1
        shl     bx,1
        mov     di,word ptr adrtbl[bx]
        add     dx,di
        mov     si,di
        mov     ax,word ptr adrtbl[bx+2]
        mov     di,ax
        adc     ax,0
        mov     bx,dx
        call    bankadr
        mov     cx,[ny]
}
LP_Y:   asm{
        push    cx
        mov     cx,[nx]
        mov     ax,[x1]
        mov     [x],ax
        }
LP_X:   asm{
        mov     al,dotcolor
        xor     es:[bx],al
        inc     bx
        inc     x
        mov     dx,[x]
        add     dx,si
        mov     ax,di
        adc     ax,0
        cmp     ax,[curbk]
        jnz     incbank
        loop    LP_X

        inc     [y1]
        mov     dx,[x1]
        mov     si,[y1]
        shl     si,1
        shl     si,1
        mov     di,word ptr adrtbl[si]
        mov     ax,word ptr adrtbl[si+2]
        mov     si,di
        add     dx,di
        mov     bx,dx
        mov     di,ax
        adc     ax,0
        cmp     ax,[curbk]
        jnz     chgbank
        }
GhlZ:   asm{
        pop     cx
        loop    LP_Y
        }
        return;
incbank:asm{
        call    bankadr
        loop    LP_X
        }
chgbank:asm{
        call    bankadr
        jmp     GhlZ
        }
}

void circle(int x,int y,int r,double ypx)
{
 int i,j,a,b;
 double xpy;
 a=int(double(r)/ypx);
 b=int(r*ypx);
 ypx=double(b)/double(a);
 xpy=double(a)/double(b);
 for(i=-a;i<a;i++){
  j=ypx*sqrt(a*a-i*i);
  point(i+x,y-j);
  point(i+x,y+j);
  }
 for(j=-b;j<b;j++){
  i=xpy*sqrt(b*b-j*j);
  point(x+i,y+j);
  point(x-i,y+j);
  }
}

void xcircle(int x,int y,int r,double ypx)
{
 int i,j,a,b;
 double xpy;
 a=int(double(r)/ypx);
 b=int(r*ypx);
 if(b>a){
 ypx=double(b)/double(a);
 for(i=-a;i<a;i++){
  j=ypx*sqrt(a*a-i*i);
  point(i+x,y-j);
  point(i+x,y+j);
  }}
 else{
 xpy=double(a)/double(b);
 for(j=-b;j<b;j++){
  i=xpy*sqrt(b*b-j*j);
  point(x+i,y+j);
  point(x-i,y+j);
  }}
}

void line(int x1,int y1,int x2,int y2)
{
 bline (x1,y1,x2,y2,&point);
}

int sright(int x,int y){
 unsigned char v;
 do{
 ++x;
 v=rdpoint(x,y);
 }while((v!=brdcolor)&&(v!=dotcolor)&&(x<640));
 return x;
}
int sleft(int x,int y){
 unsigned char v;
 do{
 --x;
 v=rdpoint(x,y);
 }while((v!=brdcolor)&&(v!=dotcolor)&&(x>0));
 return x+1;
}
int stop(int x,int y){
 unsigned char v;
 do{
 --y;
 v=rdpoint(x,y);
 }while((v!=brdcolor)&&(v!=dotcolor)&&(y>0));
 return y;
}
int sbot(int x,int y){
 unsigned char v;
 do{
 ++y;
 v=rdpoint(x,y);
 }while((v!=brdcolor)&&(v!=dotcolor)&&(y<480));
 return y;
}
void fillhor(int x,int y){
int x1,x2;
x1=sleft(x,y);
x2=sright(x,y);
if(x1==x2)return;
boxfill(x1,y,x2,y);
for(x=x1+1;x<x2;x++)
 fillver(x,y);
}
void fillver(int x,int y){
int y1,y2;
y1=stop(x,y);
y2=sbot(x,y);
if(y1==y2)return;
boxfill(x,y1,x,y2);
for(y=y1+1;y<y2;y++)
 fillhor(x,y);
}
//============================= Line Adjust Fill
int scanleft(int xl,int y){
 unsigned char v;
 do{
 --xl;
 v=rdpoint(xl,y);
 }while(v==brdcolor);
 return ++xl;
}
int scanright(int xr,int y){
 unsigned char v;
 do{
 ++xr;
 v=rdpoint(xr,y);
 }while(v==brdcolor);
 return xr;
}
int  filler(int sx,int y){
 int x,xl,xr;
 static unsigned char v;
 xl=sx,xr=sx;
 xl=scanleft(xl,y);
 xr=scanright(xr,y);
 if(xl==xr)return xr;
 boxfill(xl,y,xr,y);
 for(x=xl; x<xr; x++){
  v=rdpoint(x,y+1);
  if(v==brdcolor) x=filler(x,y+1)-2;
  }
 for(x=xl; x<xr; x++){
  v=rdpoint(x,y-1);
  if(v==brdcolor) x=filler(x,y-1)-2;
  }
 return xr;
}
