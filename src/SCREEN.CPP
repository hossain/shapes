//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

// SCREEN FUNCTIONS:
//  Writing on text screen, Chaning screen parameters, Menus ,
//       Type convertions, String Works & ...
//..............................................................
#include "SCREEN.H"

void setscreen(byte c){
 asm {
  mov ah,0
  mov al,c
  int 16
  }
}
byte getscreen(){
 byte c;
 asm {
  mov ah,0xf
  int 16
  mov c,al
  }
 return c;
}
void setcursize(byte up,byte dn){
asm{
 mov ah,1
 mov ch,up
 mov cl,dn
 int 16
 }
}
void wc(byte c){
 byte a=attr;
 word x=xpp,y=ypp;
 asm {
  push es
  mov ax,0xb800
  mov es,ax
  mov bx,y
  mov ax,bx
  mov cl,7
  shl bx,cl
  mov cl,5
  shl ax,cl
  add bx,ax
  add bx,x
  add bx,x
  mov al,c
  mov es:[bx],al
  mov al,a
  mov es:[bx+1],al
  pop es
  }
}
byte gc(word xp,word yp,byte *art){
 int position;
 byte c,a;
 asm {
  push es
  mov ax,0xb800
  mov es,ax
  mov bx,yp
  mov ax,bx
  mov cl,7
  shl bx,cl
  mov cl,5
  shl ax,cl
  add bx,ax
  add bx,xp
  add bx,xp
  mov al,es:[bx]
  mov c,al
  mov al,es:[bx+1]
  mov a,al
  pop es
  }
 *art=a;
 return c;
}
void strw(byte *str){
 word i,d=strlen(str);
 for(i=0;i<d;i++,xpp++)wc(str[i]);
 }
void enter(){
 xpp=0;ypp++;
 if(ypp>MaxYtxt){ypp=MaxYtxt; movescreen(1,1);}
 goxy(xpp,ypp);
 }
void iwc(byte c){
 asm{
  mov ah,2
  mov dl,c
  int 0x21
 }
}
void print(byte *str){
 word i,d=strlen(str);
 for(i=0;i<d;i++) iwc(str[i]);
}
byte *input(byte *str){
 byte c,x,y;word i=0;
 iwc(0);iwc(8);
 while(1){
  c=getch();
  if(c==8 && i>0){i--;str[i]=0;iwc(8);iwc(' ');iwc(8);continue;}
  if(c==13){str[i]=0;iwc(0xd);iwc(0xa);return str;}
  if(c<32) continue;
  iwc(c);iwc(0);iwc(8);
//  x++;if(x>MaxXtxt){x=0;y++;if(y>MaxYtxt){y--;movescreen(1,1);}}
//  x=gettxtx();iwc(0); goxy(x,y);
  str[i]=c; i++;
  }
}
byte getch(){
 byte c;
 asm{
 mov ah,0
 int 0x16
 mov c,al
 }
 return c;
}
void movescreen(byte where,byte how){
 byte d;
 byte x=MaxXtxt,y=MaxYtxt;
 if(where==1)d=6;else d=7;
 asm{
  mov ah,d
  mov al,how
  xor cx,cx
  mov dh,y
  mov dl,x
  int 16
 }
}
void cls(){
 goxy(0,0);
 movescreen(1,MaxYtxt+1);
}
void scol(byte c,byte bc){
 attr=bc<<4+c;
}
void goxy(byte x,byte y){
 xpp=x;ypp=y;
 asm{
  mov dh,y
  mov dl,x
  mov bh,0
  mov ah,2
  int 0x10
  }
}
byte gettxtx(){
 byte x;
 asm{
  mov ah,3
  int 0x10
  mov x,dl
  }
 return x;
}
byte gettxty(){
 byte y;
 asm{
  mov ah,3
  int 0x10
  mov y,dh
  }
 return y;
}
void box(x1,y1,x2,y2,c,atr)
byte x1,y1,x2,y2,c,atr;
{
byte boa;
boa=attr;
attr=atr;
for(xpp=x1;xpp<=x2;xpp++)
 for(ypp=y1;ypp<=y2;ypp++)
  wc(c);
attr=boa;
}
void win(x1,y1,x2,y2,c,atr)
byte x1,y1,x2,y2,c,atr;
{
byte boa;
boa=attr;
attr=atr;
xpp=x1;ypp=y1;if(c==1)wc(218);else wc(201);
xpp=x1;ypp=y2;if(c==1)wc(192);else wc(200);
xpp=x2;ypp=y1;if(c==1)wc(191);else wc(187);
xpp=x2;ypp=y2;if(c==1)wc(217);else wc(188);
ypp=y1;for(xpp=x1+1;xpp<x2;xpp++)if(c==1)wc(196);else wc(205);
xpp=x1;for(ypp=y1+1;ypp<y2;ypp++)if(c==1)wc(179);else wc(186);
ypp=y2;for(xpp=x1+1;xpp<x2;xpp++)if(c==1)wc(196);else wc(205);
xpp=x2;for(ypp=y1+1;ypp<y2;ypp++)if(c==1)wc(179);else wc(186);
attr=boa;
}
void gettxt(byte x1,byte y1,byte x2,byte y2,byte *a){
 word i,j,b=0;
 for(j=y1;j<=y2;j++)
  for(i=x1;i<=x2;i++,b+=2)
	a[b]=gc(i,j,&a[b+1]);
}
void puttxt(byte x1,byte y1,byte x2,byte y2,byte *a){
 word i,j,b=0,boa;
 boa=attr;
 for(j=y1;j<=y2;j++)
  for(i=x1;i<=x2;i++,b+=2)
	{xpp=i;ypp=j;attr=a[b+1];wc(a[b]);}
 attr=boa;
}
word pow(word m,word n){
 int i,rv=1;
 for(i=0;i<n;i++)
  rv*=m;
 return rv;
}
long lpow(long m,long n){
 long i,rv=1;
 for(i=0;i<n;i++)
  rv*=m;
 return rv;
}
byte *itos(int number,byte *str){
 byte s2[6];
 word i, m;
 for(i=0;i<5;i++){
  m=number%10;
  number=number/10;
  s2[i]=m+'0';
  if(number==0)break;
  }
 for(m=0;m<i+1;m++)
  str[m]=s2[i-m];
 str[i+1]=0;
 return str;
}
word stoi(byte *str){
 word i, m, t=strlen(str), number=0;
 for(i=0;str[i]!=0;i++){
  m=str[i]-'0';
  number=number+m*pow(10,t-i-1);
  }
 return number;
}
long stol(byte *str){
 word i,m, t=strlen(str);
 long number=0;
 for(i=0;str[i]!=0;i++){
  m=str[i]-'0';
  number=number+m*lpow(10,t-i-1);
  }
 return number;
}
byte *ltos(long number,byte *str){
 byte s2[11];
 word i;
 long m;
 for(i=0;i<10;i++){
  m=number%10;
  number=number/10;
  s2[i]=m+'0';
  if(number==0)break;
  }
 for(m=0;m<i+1;m++)
  str[m]=s2[i-m];
 str[i+1]=0;
 return str;
}
byte gkhit(){
 byte g;
 asm{
  mov dl,0xff
  mov ah,6
  int 0x21
  mov g,al
  jz empty;
 }
 ZF=0;
 return g;
empty:
 ZF=1;
 return 0;
}
void getstr(byte *name,word maxc,word ifnum){
 byte c;
 word i=0;
 goxy(xpp,ypp);wc(0);
lp0:
 c=gkhit();
 if(ZF)goto lp0;
 if(c==8 && i>0){i--;name[i]=0;xpp--;wc(' ');goxy(xpp,ypp);goto lp0;}
 if(c==13){name[i]=0; return ;}
 if(c<32)goto lp0;
 if(i>=maxc)goto lp0;
 if(ifnum && (c>'9' || c<'0'))goto lp0;
 wc(c); xpp++; goxy(xpp,ypp);wc(0);
 name[i]=c; i++;
 goto lp0;
}
int menuto(struct Menu m,word n){
 int i,c,j;
 byte h,ch=1,tx,ty,*s,sz[20],boa,*last,lx;
 s=m.ItemAddr;
 boa=attr;
 attr=m.CAttr;
 tx=m.Mx;ty=m.My;
 for(i=0;i<n;i++){
  xpp=tx;ypp=ty;lx=tx;
  sz[i]=strlen(s);
  last=s;
  strw(s);
  if(m.sye){gc(xpp,ypp,&h);attr=h&240;wc(220);ypp++;for(j=0;j<strlen(s);j++){gc(xpp,ypp,&h);attr=h&240;wc(223);xpp--;}attr=m.CAttr;}
  if(m.Horize)tx+=sz[i]+m.IHD;else ty+=m.IHD;
  s+=sz[i]+1;
  }
 attr=m.BCAttr;
 tx=m.Mx; ty=m.My;
 s=m.ItemAddr;
 xpp=tx;ypp=ty;
 strw(s); c=0;
lp0:
  ch=gkhit();
  if(!ch)ch=gkhit();
  if(ch==13) {if(m.sye){attr=h;xpp-=strlen(s);strw(" ");attr=m.BCAttr;strw(s);xpp-=strlen(s)+1;strw(s);attr=h&240;wc(220);}attr=boa;return c+1;}
  if(ch==27) {attr=boa;return 0;}
  if(ch==80 || ch==77){
			attr=m.CAttr;
			xpp=tx; ypp=ty;
			strw(s);s+=sz[c]+1; c++;
			if(m.Horize){tx+=sz[c-1]+m.IHD;if(c>=n){tx=m.Mx;c=0;s=m.ItemAddr;}}
								else {ty+=m.IHD;if(c>=n){ty=m.My;c=0;s=m.ItemAddr;}}
			attr=m.BCAttr;
			xpp=tx; ypp=ty;
			strw(s);
			}
  if(ch==72 || ch==75){
			attr=m.CAttr;
			xpp=tx; ypp=ty;
			strw(s);
			c--;s-=sz[c]+1;
			if(m.Horize){tx-=sz[c]+m.IHD;if(c<0){tx=lx;c=n-1;s=last;}}
								else {ty-=m.IHD;if(c<0){ty=m.My+(n-1)*m.IHD;c=n-1;s=last;}}
			attr=m.BCAttr;
			xpp=tx; ypp=ty;
			strw(s);
		  }
 goto lp0;
}

word strlen(char *s){
 word i;
 for(i=0;s[i]!=0;i++);
 return i;
}
void strcpy(byte *s1,byte *s2){
 register word i;
 for(i=0;s2[i];i++) s1[i]=s2[i];
 s1[i]=0;
}
void strcat(byte *s1,byte *s2){
 register word i;
 word b=strlen(s1);
 for(i=0;s2[i];i++) s1[i+b]=s2[i];
 s1[i+b]=0;
}
void memcpy(byte far *d,byte far *s,word how){
 word s1=FP_SEG(d),o1=FP_OFF(d);
 word s2=FP_SEG(s),o2=FP_OFF(s);
asm{
 push ds
 push es
 mov ax,s2
 mov ds,ax
 mov ax,s1
 mov es,ax
 mov si,o2
 mov di,o1
 cld
 mov cx,how
rep movsb
 pop es
 pop ds
 }
}
void getname(byte *name,byte *msg){
 word i=0,x1,y1,x2,y2,m;
 byte c=0,boa,*s;
 m=strlen(msg);
 x1=40-m/2-2;
 x2=40+m/2+2;
 y1=10;y2=15;
 s=new byte[(x2-x1+1)*(y2-y1+1)*2];//if(!s)errmsg(memerr);
 gettxt(x1,y1,x2,y2,s);
 boa=attr;
 box(x1,y1,x2,y2,' ',Get_Back);
 win(x1,y1,x2,y2,2,Get_Border);
 attr=Get_Msg;xpp=x1+2 ;ypp=12; strw(msg);
 attr=Get_Txt;goxy(x1+4,13); getstr(name,m-4,0);
 attr=boa;
 puttxt(x1,y1,x2,y2,s);
 delete(s);
}
word ask(...){
 word x1,y1,x2,y2,m[4],args,xxx,i;
 va_list a;
 byte *arg, c, boa, *s;
 a=...;
 for(i=0;(arg = va_arg(a,char *)) != 0;i++)m[i]=strlen(arg);args=i;
 for(i=1,xxx=m[0];i<args;i++)if(m[i]>xxx)xxx=m[i];
 x1=40-xxx/2-2;
 x2=40+xxx/2+2;
 y1=9;
 y2=12+args;
 for(i=0;i<args;i++)m[i]=2+x1+(xxx-m[i])/2;
 s=new byte[(x2-x1+1)*(y2-y1+1)*2];//if(!s)errmsg(memerr);
 gettxt(x1,y1,x2,y2,s);
 boa=attr;
 box(x1,y1,x2,y2,' ',Ask_Back);
 win(x1,y1,x2,y2,2,Ask_Border);
 attr=Ask_Msg;
 for(a=...,i=0;i<args;i++){goxy(m[i],11+i);arg = va_arg(a,char *); strw(arg);}
lp0: c=gkhit();
 if(c==13 || c=='y' || c=='Y'){c=1;goto lpe;}
 if(c==27 || c=='n' || c=='N'){c=0;goto lpe;}
 goto lp0;
lpe:
 attr=boa;
 puttxt(x1,y1,x2,y2,s);
 delete(s);
 return c;
}
void message(...){
 word x1,y1,x2,y2,m[4],args,xxx,i;
 va_list a;
 byte *arg, boa, *s;
 a=...;
 for(i=0;(arg = va_arg(a,char *)) != 0;i++)m[i]=strlen(arg);args=i;
 for(i=1,xxx=m[0];i<args;i++)if(m[i]>xxx)xxx=m[i];
 x1=40-xxx/2-2;
 x2=40+xxx/2+2;
 y1=10-(args)/2;
 y2=y1+3+args;
 for(i=0;i<args;i++)m[i]=2+x1+(xxx-m[i]+1)/2;
 s=new byte[(x2-x1+1)*(y2-y1+1)*2];//if(!s)errmsg(memerr);
 gettxt(x1,y1,x2,y2,s);
 boa=attr;
 box(x1,y1,x2,y2,' ',Msg_Back);
 win(x1,y1,x2,y2,2,Msg_Border);
 attr=Msg_Msg;
 for(a=...,i=0;i<args;i++){goxy(m[i],y1+2+i);arg = va_arg(a,char *); strw(arg);}
 lp0: gkhit(); if(ZF)goto lp0;
 attr=boa;
 puttxt(x1,y1,x2,y2,s);
 delete(s);
}
void errmsg(byte *msg){
 word i=0,x1,y1,x2,y2,m;
 byte c=0,boa,*s;
 m=strlen(msg);
 x1=40-m/2-2;
 x2=40+m/2+2;
 y1=10;y2=14;
 s=new byte[(x2-x1+1)*(y2-y1+1)*2];if(!s)terminate(1);
 gettxt(x1,y1,x2,y2,s);
 boa=attr;
 box(x1,y1,x2,y2,' ',Err_Back);
 win(x1,y1,x2,y2,2,Err_Border);
 attr=Err_Msg;xpp=x1+2 ;ypp=12; strw(msg);
 attr=boa;
 lp0: gkhit(); if(ZF)goto lp0;
 puttxt(x1,y1,x2,y2,s);
 delete(s);
}
void terminate(byte ec){
 if(TSRLoaded)unloadTSR();
asm{
 mov ah,0x4c
 mov al,ec
 int 0x21
 }
}
long cpuclock(){
//	long rv;
	unsigned int d1,d2;
	asm{
	mov	ah,0
	int	1ah
	mov     [d2],dx
	mov	[d1],cx
	}
	return(long(d1)<<16|long(d2));
}
void setcpuclock(long clk){
	unsigned int d1,d2;
	d1=clk;
	d2=clk>>16;
	asm{
	mov	ah,1
	mov	cx,d2
	mov	dx,d1
	int	1ah
	}
}
void delay(long clk){
	unsigned int d1,d2;
	d1=clk;
	d2=clk>>16;
	asm{
	mov	ah,86h
	mov	cx,d2
	mov	dx,d1
	int	15h
	}
}
void getcurtime(struct time *d){
	char d1,d2,d3,d4;
	asm{
	mov	ah,2ch
	int	21h
	mov	d1,ch
	mov	d2,cl
	mov	d3,dh
	mov	d4,dl
	}
	d->hour=d1;
	d->min=d2;
	d->sec=d3;
	d->msec=d4;
}
void setcurtime(struct time t){
	char d1,d2,d3,d4;
	d1=t.hour,
	d2=t.min,
	d3=t.sec,
	d4=t.msec;
	asm{
	mov	ah,2dh
	mov	ch,d1
	mov	cl,d2
	mov	dh,d3
	mov	dl,d4
	int	21h
	}
}
void getcurdate(struct date *d){
	int d1;char d2,d3,d4;
	asm{
	mov	ah,2ah
	int	21h
	mov	d1,cx
	mov	d2,dh
	mov	d3,dl
	mov	d4,al
	}
	d->year=d1;
	d->month=d2;
	d->day=d3;
	d->weekday=d4;
}
void setcurdate(struct date d){
	int d1;char d2,d3,d4;
	d1=d.year;
	d2=d.month;
	d3=d.day;
	d4=d.weekday;
	asm{
	mov	cx,d1
	mov	dh,d2
	mov	dl,d3
	mov	ah,2bh
	int	21h
	}
}
int GetKey(){
 key1=gkhit();
 if(ZF)return 0;
 if(!key1)key2=gkhit();
}