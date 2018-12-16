//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

// Device.cpp
// Contains: Mouse Support, Disk & Files, EMS Memory, XMS Memory, & ...
//
// By H.Taheri

#include "DEVICE.H"
#include "SCREEN.H"

void imouse(){
 asm{  mov ax,0;  int 0x33; }//if ax=0 then error!
}
void mshow(){
 asm{  mov ax,1;  int 0x33; }
}
void rmouse(){
 asm{  mov ax,2;  int 0x33; }
}
void setmarea(word x1,word y1,word x2,word y2){
 asm{
  mov cx,x1;  mov dx,x2;  mov ax,7;  int 0x33;
  mov cx,y1;  mov dx,y2;  mov ax,8;  int 0x33;
 }
}
void setmpos(word x, word y){
 mox=x,moy=y;
 asm{
  mov ax,4;  mov cx,x;  mov dx,y;  int 0x33;
 }
}
void setmousespeed(word speedx,word speedy,word maxdub){
asm{
  mov ax,0x1a;  mov bx,speedx;  mov cx,speedy;  mov dx,maxdub;  int 0x33;
  }
}
void w4fm(word w){
 word x,y;
 while(w==kmouse(&x,&y));
}
word kmouse(word *x,word *y){
 word v1,v2,v3;
 asm{
  mov ax,3;  int 0x33;  mov v1,bx;  mov v2,cx;  mov v3,dx;
 }
 *x=v2; *y=v3;
 return v1;
}
void settxtmshape(word andmask,word xormask){
asm {
 mov ax,0xa;  mov bx,0; mov  cx,andmask;  mov dx,xormask;  int 0x33;
 }
}
void setgrpmshape(char *bitfield){
word s=FP_SEG(bitfield),o=FP_OFF(bitfield);
asm {
 push es
 mov ax,s; mov es,ax; mov ax,0x9;  mov bx,32; mov  cx,16;  mov dx,o;
 int 0x33;
 pop es
 }
}
void GetMouse(){
 mbutts = kmouse(&mox ,&moy);
}
void mkdir(char *str){
 word s=FP_SEG(str),o=FP_OFF(str);
 asm{
  push ds
  mov ax,s
  mov ds,ax
  mov ah,0x39
  mov dx,o
  int 0x21
  pop ds
  jnc Fin
  mov FEC,ax
  }
 return;
Fin:
 FEC=0;
}
void rddir(char *str){
 word s=FP_SEG(str),o=FP_OFF(str);
 asm{
  push ds
  mov ax,s
  mov ds,ax
  mov ah,0x3a
  mov dx,o
  int 0x21
  pop ds
  jnc Fin
  mov FEC,ax
  }
 return;
Fin:
 FEC=0;
}
void chdir(char *str){
 word s=FP_SEG(str),o=FP_OFF(str);
 asm{
  push ds
  mov ax,s
  mov ds,ax
  mov ah,0x3b
  mov dx,o
  int 0x21
  pop ds
  jnc Fin
  mov FEC,ax
  }
 return;
Fin:
 FEC=0;
}
void remove(char *str){
 word s=FP_SEG(str),o=FP_OFF(str);
 asm{
  push ds
  mov ax,s
  mov ds,ax
  mov ah,0x41
  mov dx,o
  int 0x21
  pop ds
  jnc Fin
  mov FEC,ax
  }
 return;
Fin:
 FEC=0;
}
word newfile(char *str,word a){
 word h,s=FP_SEG(str),o=FP_OFF(str);
 asm{
  push ds
  mov ax,s
  mov ds,ax
  mov ah,0x3c
  mov dx,o
  mov cx,a
  int 0x21
  pop ds
  mov h,ax
  jnc Fin
  mov FEC,ax
  }
 return 0;
Fin:
 FEC=0;
 return h;
}
word openf(char *str,byte m,word a){
 word h,s=FP_SEG(str),o=FP_OFF(str);
 asm{
  push ds
  mov ax,s
  mov ds,ax
  mov ah,0x3d
  mov al,m
  mov dx,o
  mov cx,a
  int 0x21
  pop ds
  mov h,ax
  jnc Fin
  mov FEC,ax
  }
 return 0;
Fin:
 FEC=0;
 return h;
}
void closef(word handle){
 asm{
  mov ah,0x3e
  mov bx,handle
  int 0x21
  jnc Fin
  mov FEC,ax
  }
 return ;
Fin:
 FEC=0;
}
word readf(char *str,word how,word handle){
 word rv,s=FP_SEG(str),o=FP_OFF(str);
 asm{
  push ds
  mov ax,s
  mov ds,ax
  mov ah,0x3f
  mov dx,o
  mov cx,how
  mov bx,handle
  int 0x21
  pop ds
  mov rv,ax
  jnc Fin
  mov FEC,ax
  }
 return 0;
Fin:
 FEC=0;
 return rv;
}
word writef(char *str,word how,word handle){
 word rv,s=FP_SEG(str),o=FP_OFF(str);
 asm{
  push ds
  mov ax,s
  mov ds,ax
  mov ah,0x40
  mov dx,o
  mov cx,how
  mov bx,handle
  int 0x21
  pop ds
  mov rv,ax
  jnc Fin
  mov FEC,ax
  }
 return 0;
Fin:
 FEC=0;
 return rv;
}
long movef(long how,byte mode,word handle){
 word s=word(how>>16),o=word(how);
 asm{
  mov cx,s
  mov dx,o
  mov ah,0x42
  mov al,mode
  mov bx,handle
  int 0x21
  mov o,ax
  mov s,dx
  jnc Fin
  mov FEC,ax
  }
 return 0;
Fin:
 FEC=0;
 return long(s<<16)+o;
}
byte readb(word handle){
 byte b,*a;a=&b;
 readf(a,1,handle);
 return b;
}
word readw(word handle){
 word b;
 readf((byte *)&b,2,handle);
 return b;
}
long readl(word handle){
 long b;
 readf((byte *)&b,4,handle);
 return b;
}
void writeb(byte b,word handle){
 byte *a;a=&b;
 writef(a,1,handle);
}
void writew(word b,word handle){
 word c=b;
 writef((byte *)&c,2,handle);
}
void writel(long b,word handle){
 long c=b;
 writef((byte *)&c,4,handle);
}
long filepos(word handle){
 return movef(0,1,handle);
}
long filesize(word handle){
 long l = filepos(handle);
 long v = movef(0,2,handle);
 movef(l,0,handle);
 return v;
}
byte iseof(word handle){
 long l1=filesize(handle);
 long l2=filepos(handle);
 if(l1==l2)return 1;else return 0;
}
void setdta(byte far *addr){
 word s=FP_SEG(addr),o=FP_OFF(addr);
asm {
 push ds
 mov ax,s
 mov ds,ax
 mov ah,0x1a
 mov dx,o
 int 0x21
 pop ds
 }
}
char far *getdta(){
 word s,o;long a,b;
asm {
 push es
 mov ah,0x2f
 int 0x21
 mov ax,es
 pop es
 mov s,ax
 mov o,bx
 }
 a=s,b=o;
 return((char far *)((a<<16)+b));//(byte far *)MK_FP(s,o);
}
long getdiskfree(byte disk){
 word a,b,c;
 long la,lb,lc;
asm{
 mov ah,0x36
 mov dl,disk
 int 0x21
 mov a,ax
 cmp ax,0xffff
 je  Err
 mov b,bx
 mov c,cx
 }
 la=a,lb=b,lc=c;
 return (la*lb*lc);
Err:
 FEC=1;
 return -1;
}
word findf(byte *name,word attb,struct fileblock *fb){
 word o,s;
 word s1=FP_SEG(name),o1=FP_OFF(name);
 word s2=FP_SEG(fb),o2=FP_OFF(fb);
asm{
 push ds
 push es
 mov ah,0x2f
 int 0x21
 mov ax,es
 mov s,ax
 mov o,bx
 mov ax,s2
 mov ds,ax
 mov dx,o2
 mov ah,0x1a
 int 0x21
 mov ax,s1
 mov ds,ax
 mov dx,o1
 mov ah,0x4e
 mov cx,attb
 int 0x21
 jnc okaid
 mov FEC,ax
 mov ax,s
 mov ds,ax
 mov dx,o
 mov ah,0x1a
 int 0x21
 pop es
 pop ds
}
 return 0;
okaid:
asm{
 mov ax,s
 mov ds,ax
 mov dx,o
 mov ah,0x1a
 int 0x21
 pop es
 pop ds
}
 return 1;
}
word nextf(struct fileblock *fb){
 word o,s;
 word s2=FP_SEG(fb),o2=FP_OFF(fb);
asm{
 push es
 push ds
 mov ah,0x2f
 int 0x21
 mov ax,es
 mov s,ax
 mov o,bx
 mov ax,s2
 mov ds,ax
 mov dx,o2
 mov ah,0x1a
 int 0x21
 mov ah,0x4f
 int 0x21
 jnc okaid
 mov FEC,ax
 mov ax,s
 mov ds,ax
 mov dx,o
 mov ah,0x1a
 int 0x21
 pop ds
 pop es
}
 return 0;
okaid:
asm{
 mov ax,s
 mov ds,ax
 mov dx,o
 mov ah,0x1a
 int 0x21
 pop ds
 pop es
}
 return 1;
}
word XMSInst(){
 long xm;
 asm{
  push es
  mov ax,0x4300
  int XMSINT
  cmp al,0x80
  jne  noxms
  mov ax,0x4310
  int XMSINT
  mov word ptr xm+2,es
  mov word ptr xm+0,bx
  pop es
  jmp xmsok;
  }
noxms:
 return 0;
xmsok:
 XMS=xm;
 return 1;
}
long XMSfreeSize(){
 long xm=XMS;
 word xkb;
 long xl;
 asm{
  mov ax,0x0800
  call xm
  mov xkb,dx;
  }
 xl=xkb;
 return xl*1024;
 }
byte XMSFree(word Handle){
 long xm=XMS;
 byte a;
 asm{
  mov dx,Handle
  mov ax,0x0A00
  call xm
  cmp ax,1
 jne Errf
 }
 return 0;
Errf:
 asm mov a,bl
 return a;
}
byte XMSGet(word *Handle,word size){
 long xm=XMS;
 word hnle;
 byte a;
 asm{
  mov ax,0x900
  mov dx,size
  call xm
  cmp ax,1
  jne Errg;
  mov hnle,dx
  }
 *Handle=hnle;
 return 0;
Errg:
 asm mov a,bl;
 return a;
}
byte RAM2XMS(long p,word h,long xo,long size){
 long xm=XMS;
 byte a;
 struct XMSC xc;
// byte far *x;x=(byte far *)&xc;
 word y=FP_SEG(&xc),z=FP_OFF(&xc);
 xc.Size=size;
 xc.SHdl=0;
 xc.SOfs=p;
 xc.THdl=h;
 xc.TOfs=xo;
asm{
 push ds
 mov ax,y
 mov ds,ax
 mov si,z;
 mov ax,0xb00
 call xm
 pop ds
 cmp ax,1
 jne Errr
 }
 return 0;
Errr:
 asm mov a,bl
 return a;
}
byte XMS2RAM(long p,word h,long xo,long size){
 long xm=XMS;
 byte a;
 struct XMSC xc;
// byte far *x;x=(byte far *)&xc;
 word y=FP_SEG(&xc),z=FP_OFF(&xc);
 xc.Size=size;
 xc.SHdl=h;
 xc.SOfs=xo;
 xc.THdl=0;
 xc.TOfs=p;
asm{
 push ds
 mov ax,y
 mov ds,ax
 mov si,z
 mov ax,0xb00
 call xm
 pop ds
 cmp ax,1
 jne Errr
 }
 return 0;
Errr:
 asm mov a,bl
 return a;
}
byte XMS2XMS(word sh,long sxo,word h,long xo,long size){
 long xm=XMS;
 byte a;
 struct XMSC xc;
// byte far *x;x=(byte far *)&xc;
 word y=FP_SEG(&xc),z=FP_OFF(&xc);
 xc.Size=size;
 xc.SHdl=sh;
 xc.SOfs=sxo;
 xc.THdl=h;
 xc.TOfs=xo;
asm{
 push ds
 mov ax,y
 mov ds,ax
 mov si,z
 mov ax,0xb00
 call xm
 pop ds
 cmp ax,1
 jne Errr
 }
 return 0;
Errr:
 asm mov a,bl
 return a;
}
