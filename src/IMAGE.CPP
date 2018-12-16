//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

//  Image Processor Module
//  header file: Public.cpp

#include "PUBLIC.H"

int  Image::MakeImage(int x,int y){
 ixs=x,iys=y;
 if(x>8000)return 0;
 isz=long(x)*long(y);
 bypp=1;// This is only in 256 color
 if(XMSGet(&hnd,(isz/1024)+1))return 0;
 lpb=8000/x;
 bpb=x*lpb;
 hmb=long(isz/long(bpb))+1;
 lablk=isz%long(bpb);
 palt=new char far [768];
 return 1;
}
void Image::Disturbe(){
 XMSFree(hnd);
 delete(palt);
 }
int  Image::LoadImage(char *filename){
 int h,i;
 h=openf(filename,0,0);
 if(!h)return 0;
 if(!LoadHI(h)){closef(h);return 0;}
 readf(palt,768,h);
 for(i=0;i<768;i++)palt[i]/=4;
 closef(h);
 return 1;
}
int  Image::LoadHI(int h){
 int i;
 long o=0;
// char *xbf;xbf=new char [bpb];
// if(!xbf)NEMError();
// long lbf;lbf=(long) xbf;
 if(readb(h)!=1)return 0;
 ixs=readw(h); iys=readw(h);
 if(!MakeImage(ixs,iys)) NEMError();
 for(i=0;i<hmb-1;i++){
   readf(xbf,bpb,h);
   RAM2XMS(lbf,hnd,o,bpb);
   o+=bpb;
   }
 readf(xbf,lablk,h);
 RAM2XMS(lbf,hnd,o,lablk);
// delete(xbf);
 return 1;
}
int  Image::LoadHIS(char *hfn,int w,int sc,long eapi){
 int i,h,j;
 long o=0;
 h=openf(hfn,0,0);
 if(!h)return 0;
 o=eapi*w;
 movef(o,0,h);
 if(readb(h)!=1)return 0;
 ixs=readw(h); iys=readw(h);
 o=0;
 if(!MakeImage(ixs,iys)) NEMError();
 for(i=0;i<hmb-1;i++){
   readf(xbf,bpb,h);
   for(j=0;j<bpb;j++)xbf[j]+=sc;
   RAM2XMS(lbf,hnd,o,bpb);
   o+=bpb;
   }
 readf(xbf,lablk,h);
 for(j=0;j<lablk;j++)xbf[j]+=sc;
 RAM2XMS(lbf,hnd,o,lablk);
 readf(palt,768,h);
 for(i=0;i<768;i++)palt[i]/=4;
 closef(h);
 return 1;
}
int  Image::LoadBMP(char *filename){return 1;}
int  Image::LoadPCX(char *filename){return 1;}
int  Image::LoadGIF(char *filename){return 1;}
int  Image::SaveHI(char *filename){
 int h,i;
 long o=0;
// char *xbf;xbf=new char [16000];
// long lbf;lbf=(long) xbf;
// if(!xbf)NEMError();
 h=newfile(filename,0);
 if(!h)return 0;
 writeb(bypp,h); writew(ixs,h); writew(iys,h);
 for(i=0;i<hmb-1;i++){
   XMS2RAM(lbf,hnd,o,bpb);
   writef(xbf,bpb,h);
   o+=bpb;
   }
 XMS2RAM(lbf,hnd,o,lablk);
 writef(xbf,lablk,h);
 for(i=0;i<768;i++)palt[i]*=4;
 writef(palt,768,h);
 for(i=0;i<768;i++)palt[i]/=4;
 closef(h);
// delete(xbf);
 return 1;
}
int  Image::SaveBMP(char *filename){return 1;}
int  Image::SavePCX(char *filename){return 1;}
int  Image::SaveGIF(char *filename){return 1;}
int  Image::GetImage(int x1,int y1,int x2,int y2){
	int v=FP_SEG(xbf);
	int dr=FP_OFF(xbf);
	int i,j,k,hn=0;
	int bbb, eee, ccc, ddd;
	long o=0;
	int nx;

	if(x1<0)x1=0;
	if(y1<0)y1=0;

	ixs=x2-x1+1,iys=y2-y1+1;
	nx=x2-x1+1;k=0;
	if(!MakeImage(ixs,iys))return 0;
	//XMS2RAM(lbf,hnd,o,bpb);hn=1;o+=bpb;

//DOT GETTING:
for(i=y1;i<y2;i++){
  asm push es;
  ccc=adrtbl[i][0];
  ddd=adrtbl[i][1];
  bbb=ccc+x1;  eee=ddd;
  asm adc eee,0;
  if(eee!=curbk)asm{mov ax,eee; call bankadr;}
  ddd=curbk;
  _ES=ourseg;
  _SI=k,_CX=nx,_BX=x1,_DI=bbb;
  asm add si,[dr];
lpx:	asm{
	push	ds
	mov     ax,[v]
	mov	ds,ax
	mov     al,es:[di]
	mov     ds:[si],al
	pop	ds
	inc     di
	inc     si
	inc	bx
	mov     dx,bx
	add	dx,ccc
	mov     ax,ddd
	adc     ax,0
	cmp     ax,[curbk]
	jnz     incbank
	loop    lpx
	jmp	another
	}
incbank:asm{
	call	bankadr
	loop    lpx
	}
another:asm pop es;
	k+=nx;
	if(k>=bpb){
		RAM2XMS(lbf,hnd,o,bpb);
		k=0,hn++,o+=bpb;
		}
	}
RAM2XMS(lbf,hnd,o,lablk);
return 1;
}
void Image::PutImage(int x1,int y1){
	int v=FP_SEG(xbf);
	int dr=FP_OFF(xbf);
	int x,i,j,nl,k,hn=0,bbb;
	int eee;
	int x2,y2,ccc,ddd;
	int tlx=0, tly=0, trx=0;
	long o=0;
	x2=ixs+x1; y2=iys+y1;
	if(x1<0){tlx=-x1;x1=0;}
	if(y1<0){tly=-y1;y1=0;}
	if(x2>smaxx){trx=x2-smaxx+1;x2=smaxx-1;}
	if(y2>smaxy){y2=smaxy-1;}
	int nx,ny;
	nx=x2-x1,ny=y2-y1;
	XMS2RAM(lbf,hnd,o,bpb);hn=1;o+=bpb;
	k=ixs*tly+tlx;
	nl=tlx+trx;
	y2--;
	for(i=y1;i<y2;i++){
  asm push es;
  ccc=adrtbl[i][0];
  ddd=adrtbl[i][1];
  bbb=ccc+x1;  eee=ddd;
  asm adc eee,0;
  if(eee!=curbk)asm{mov ax,eee; call bankadr;}
  //ddd=curbk;
  _ES=ourseg;
  _SI=k,_CX=nx,_BX=x1,_DI=bbb;
  asm add si,[dr];
lpx:	asm{
	push	ds
	mov     ax,[v]
	mov	ds,ax
	mov     al,ds:[si]
	mov     es:[di],al
	pop	ds
	inc     di
	inc     si
	inc	bx
	mov     dx,ccc
	add	dx,bx
	mov     ax,ddd
	adc     ax,0
	cmp     ax,[curbk]
	jnz     incbank
	loop    lpx
	jmp	another
	}
incbank:asm{
	call	bankadr
	loop    lpx
	}
another:asm pop es;
	k+=ixs;
	if(k>=bpb){
		if(hn==hmb-1) XMS2RAM(lbf,hnd,o,lablk);
		else XMS2RAM(lbf,hnd,o,bpb);
		k=tlx;
		hn++;
		o+=bpb;
		}
	}
}
void Image::PutFore(int x1,int y1){
	int v=FP_SEG(xbf);
	int dr=FP_OFF(xbf);
	int x,i,j,nl,k,hn=0,bbb;
	int eee;
	int x2,y2,ccc,ddd;
	int tlx=0, tly=0, trx=0;
	long o=0;
	x2=ixs+x1; y2=iys+y1;
	if(x1<0){tlx=-x1;x1=0;}
	if(y1<0){tly=-y1;y1=0;}
	if(x2>smaxx){trx=x2-smaxx+1;x2=smaxx-1;}
	if(y2>smaxy){y2=smaxy-1;}
	int nx,ny;
	nx=x2-x1,ny=y2-y1;
	XMS2RAM(lbf,hnd,o,bpb);hn=1;o+=bpb;
	k=ixs*tly+tlx;
	nl=tlx+trx;
	for(i=y1;i<y2;i++){
	if(i==479)return;
  asm push es;
  ccc=adrtbl[i][0];
  ddd=adrtbl[i][1];
  bbb=ccc+x1;  eee=ddd;
  asm adc eee,0;
  if(eee!=curbk)asm{mov ax,eee; call bankadr;}
  //ddd=curbk;
  _ES=ourseg;
  _SI=k,_CX=nx,_BX=x1,_DI=bbb;
  asm add si,[dr];
lpx:	asm{
	push	ds
	mov     ax,[v]
	mov	ds,ax
	mov     al,ds:[si]
	or	al,al
	jz	nocol
	mov     es:[di],al
	}
nocol:	asm{
	pop	ds
	inc     di
	inc     si
	inc	bx
	mov     dx,bx
	add	dx,ccc
	mov     ax,ddd
	adc     ax,0
	cmp     ax,[curbk]
	jnz     incbank
	loop    lpx
	jmp	another
	}
incbank:asm{
	call	bankadr
	loop    lpx
	}
another:asm pop es;
	k+=ixs;
	if(k>=bpb){
		if(hn==hmb-1) XMS2RAM(lbf,hnd,o,lablk);
		else XMS2RAM(lbf,hnd,o,bpb);
		k=tlx;
		hn++;
		o+=bpb;
		}
	}
}
void Image::PutXORFore(int x1,int y1){
	int v=FP_SEG(xbf);
	int dr=FP_OFF(xbf);
	int x,i,j,nl,k,hn=0,bbb;
	int eee;
	int x2,y2,ccc,ddd;
	int tlx=0, tly=0, trx=0;
	long o=0;
	x2=ixs+x1; y2=iys+y1;
	if(x1<0){tlx=-x1;x1=0;}
	if(y1<0){tly=-y1;y1=0;}
	if(x2>smaxx){trx=x2-smaxx+1;x2=smaxx-1;}
	if(y2>smaxy){y2=smaxy-1;}
	int nx,ny;
	nx=x2-x1,ny=y2-y1;
	XMS2RAM(lbf,hnd,o,bpb);hn=1;o+=bpb;
	k=ixs*tly+tlx;
	nl=tlx+trx;
	for(i=y1;i<y2;i++){
  asm push es;
  ccc=adrtbl[i][0];
  ddd=adrtbl[i][1];
  bbb=ccc+x1;  eee=ddd;
  asm adc eee,0;
  if(eee!=curbk)asm{mov ax,eee; call bankadr;}
  //ddd=curbk;
  _ES=ourseg;
  _SI=k,_CX=nx,_BX=x1,_DI=bbb;
  asm add si,[dr];
lpx:	asm{
	push	ds
	mov     ax,[v]
	mov	ds,ax
	mov     al,ds:[si]
	or	al,al
	jz	nocol
	xor     es:[di],al
	}
nocol:	asm{
	pop	ds
	inc     di
	inc     si
	inc	bx
	mov     dx,bx
	add	dx,ccc
	mov     ax,ddd
	adc     ax,0
	cmp     ax,[curbk]
	jnz     incbank
	loop    lpx
	jmp	another
	}
incbank:asm{
	call	bankadr
	loop    lpx
	}
another:asm pop es;
	k+=ixs;
	if(k>=bpb){
		if(hn==hmb-1) XMS2RAM(lbf,hnd,o,lablk);
		else XMS2RAM(lbf,hnd,o,bpb);
		k=tlx;
		hn++;
		o+=bpb;
		}
	}
}
void Image::PutCutImage(int x1,int y1,int ix1,int iy1,int ix2,int iy2){
	int v=FP_SEG(xbf);
	int dr=FP_OFF(xbf);
	int i,j,nl,k,hn=0,bbb,eee;
	int x2,y2,ccc,ddd;
	int tlx=0, tly=0, trx=0;
	long o;
	x2=x1+ix2-ix1; y2=y1+iy2-iy1;
	tlx=ix1,tly=iy1,trx=ixs-ix2;
	if(x1<0){tlx-=x1;x1=0;}
	if(y1<0){tly-=y1;y1=0;}
	if(x2>smaxx){trx+=ix2-smaxx-1;x2=smaxx-1;}
	if(y2>smaxy){y2=smaxy-1;}
	int nx,ny;
	nx=x2-x1,ny=y2-y1;
	hn=long(long(ixs)*long(tly)+tlx)/long(bpb);
	k=long(long(ixs)*long(tly)+tlx)%long(bpb);
	o=long(hn)*long(bpb);
	XMS2RAM(lbf,hnd,o,bpb); o+=bpb;
	nl=tlx+trx;
	for(i=y1;i<y2;i++){

  asm push es;
  ccc=adrtbl[i][0];
  ddd=adrtbl[i][1];
  bbb=ccc+x1;  eee=ddd;  asm adc eee,0;
  if(eee!=curbk)asm{mov ax,eee; call bankadr;}
  //ddd=curbk;
  _ES=ourseg;
  _SI=k,_CX=nx,_BX=x1,_DI=bbb;
  asm add si,[dr];
/*
asm{
	mov     dx,[x1]
	mov     bx,[i]
	shl     bx,1
	shl     bx,1
	mov     cx,word ptr adrtbl[bx]
	mov	ccc,cx
	mov     ax,word ptr adrtbl[bx+2]
	add     dx,cx
	adc     ax,0
	mov	ddd,ax
	mov	di,dx
	mov	si,[k]
	add	si,[dr]
	cmp     ax,[curbk]
	jz      nonew
	call    bankadr                 //;switch banks if a new bank entered
	}*/
nonew:  asm{
	mov	bx,[x1]
	mov	ax,[ourseg]
	mov	es,ax
	mov	cx,[nx]
	}
lpx:	asm{
	push	ds
	mov     ax,[v]
	mov	ds,ax
	mov     al,ds:[si]
	mov     es:[di],al
	pop	ds
	inc     di
	inc     si
	inc	bx
	mov     dx,bx
	add	dx,ccc
	mov     ax,ddd
	adc     ax,0
	cmp     ax,[curbk]
	jnz     incbank
	loop    lpx
	jmp	another
	}
incbank:asm{
	call	bankadr
	loop    lpx
	}
another:asm pop es;
	k+=ixs;
	if(k>=bpb){
		if(hn==hmb-1) XMS2RAM(lbf,hnd,o,lablk);
		else XMS2RAM(lbf,hnd,o,bpb);
		k=tlx;
		hn++;
		o+=bpb;
		}
	}
}
void Image::PutCutLine(int x1,int y1,int iy,int ix1,int ix2){
	int i, k, hn=0, x2;
	int tlx=0, tly=0, trx=0;
	long o;
	x2=x1+ix2-ix1;
	tlx=ix1,tly=iy,trx=ixs-ix2;
	if(x1<0){tlx-=x1;x1=0;}
	if(y1<0){tly-=y1;y1=0;}
	if(x2>smaxx){trx+=ix2-smaxx-1;x2=smaxx-1;}
	hn=long(long(ixs)*long(tly)+tlx)/long(bpb);
	k=long(long(ixs)*long(tly)+tlx)%long(bpb);
	o=long(hn)*long(bpb);
	XMS2RAM(lbf,hnd,o,bpb); o+=bpb;
	for(i=x1;i<=x2;i++){dotcolor=xbf[k++];point(i,y1);}
}
void Image::PutCutFore(int x1,int y1,int ix1,int iy1,int ix2,int iy2){
	int v=FP_SEG(xbf);
	int dr=FP_OFF(xbf);
	int i,j,nl,k,hn=0,bbb,eee;
	int x2,y2,ccc,ddd;
	int tlx=0, tly=0, trx=0;
	long o;
	x2=x1+ix2-ix1; y2=y1+iy2-iy1;
	tlx=ix1,tly=iy1,trx=ixs-ix2;
	if(x1<0){tlx-=x1;x1=0;}
	if(y1<0){tly-=y1;y1=0;}
	if(x2>smaxx){trx+=ix2-smaxx-1;x2=smaxx-1;}
	if(y2>smaxy){y2=smaxy-1;}
	int nx,ny;
	nx=x2-x1,ny=y2-y1;
	hn=long(long(ixs)*long(tly))/long(bpb);
	k=long(long(ixs)*long(tly)+tlx)%long(bpb);
	o=long(hn)*long(bpb);
	XMS2RAM(lbf,hnd,o,bpb); o+=bpb;
	nl=tlx+trx;
	for(i=y1;i<y2;i++){

  asm push es;
  ccc=adrtbl[i][0];
  ddd=adrtbl[i][1];
  bbb=ccc+x1;  eee=ddd;
  asm adc eee,0;
  if(eee!=curbk)asm{mov ax,eee; call bankadr;}
 // ddd=curbk;
  _ES=ourseg;
  _SI=k,_CX=nx,_BX=x1,_DI=bbb;
  asm add si,[dr];
lpx:	asm{
	push	ds
	mov     ax,[v]
	mov	ds,ax
	mov     al,ds:[si]
	or	al,al
	jz      nocol
	mov     es:[di],al
	}
nocol:	asm{
	pop	ds
	inc     di
	inc     si
	inc	bx
	mov     dx,bx
	add	dx,ccc
	mov     ax,ddd
	adc     ax,0
	cmp     ax,[curbk]
	jnz     incbank
	loop    lpx
	jmp	another
	}
incbank:asm{
	call	bankadr
	loop    lpx
	}
another:asm pop es;
	k+=ixs;
	if(k>=bpb){
		if(hn==hmb-1) XMS2RAM(lbf,hnd,o,lablk);
		else XMS2RAM(lbf,hnd,o,bpb);
		k=tlx;
		hn++;
		o+=bpb;
		}
	}
}
void Image::PutDoubleSize(int x1,int y1){
	int v=FP_SEG(xbf);
	int dr=FP_OFF(xbf);
	int i,j,nl,k,hn=0,bbb,eee;
	int x2,y2,ccc,ddd;
	int z;
	int tlx=0, tly=0, trx=0;
	long o;
	x2=x1+ixs*2; y2=y1+iys*2;
	tlx=0,tly=0,trx=0;
	if(x1<0){tlx-=x1/2;x1=0;}
	if(y1<0){tly-=y1/2;y1=0;}
	if(x2>smaxx) {trx+=ixs-smaxx-1;x2=smaxx-1;}
	if(y2>smaxy) {y2=smaxy-1;}
	int nx;
	nx=(x2-x1)/2;
	hn=long(long(ixs)*long(tly)+tlx)/long(bpb);
	k=long(long(ixs)*long(tly)+tlx)%long(bpb);
	o=long(hn)*long(bpb);
	XMS2RAM(lbf,hnd,o,bpb); o+=bpb;
	nl=tlx+trx;
	for(i=y1;i<y2;){
	for(z=0;z<2;z++,i++){
	 asm push es;
asm{
	mov     dx,[x1]
	mov     bx,[i]
	shl     bx,1
	shl     bx,1
	mov     cx,word ptr adrtbl[bx]
	mov	[ccc],cx
	mov     ax,word ptr adrtbl[bx+2]
	mov	[ddd],ax
	add     dx,cx
	adc     ax,0
	mov	di,dx
	mov	si,[k]
	add	si,[dr]
	cmp     ax,[curbk]
	jz      nonew
	call    bankadr                 //;switch banks if a new bank entered
	}
nonew:  asm{
	mov	bx,[x1]
	mov	ax,[ourseg]
	mov	es,ax
	mov	cx,[nx]
	}
lpx:	asm{
	push	ds
	mov     ax,[v]
	mov	ds,ax
	mov     al,ds:[si]
	mov     es:[di],al
	mov	es:[di+1],al
	pop	ds
	inc     di
	inc	di
	inc     si
	inc	bx
	inc     bx
	mov     dx,bx
	add	dx,ccc
	mov     ax,ddd
	adc     ax,0
	cmp     ax,[curbk]
	jnz     incbank
	loop    lpx
	jmp	another
	}
incbank:asm{
	call	bankadr
	loop    lpx
	}
another:asm pop es;
	}
	k+=ixs;
	if(k>=bpb){
		if(hn==hmb-1) XMS2RAM(lbf,hnd,o,lablk);
		else XMS2RAM(lbf,hnd,o,bpb);
		k=tlx;
		hn++;
		o+=bpb;
		}
	}
}
void Image::PutPicIn(int x,int y,struct Picture pic){}
int  Image::GetPicIn(int x1,int y1,int x2,int y2,struct Picture& pic){return 1;}
int  Image::Image2Pic(struct Picture& pic){return 1;}
int  Image::Pic2Image(struct Picture pic){return 1;}
void Image::ImageInImage(int x,int y,Image img){}
int  Image::ImageOutImage(int x,int y,Image& img){return 1;}
void Image::PutXORImage(int x1,int y1){
	int v=FP_SEG(xbf);
	int dr=FP_OFF(xbf);
	int i,j,nl,k,hn=0,bbb;
	int eee;
	int x2,y2,ccc,ddd;
	int tlx=0, tly=0, trx=0;
	long o=0;
	x2=ixs+x1; y2=iys+y1;
	if(x1<0){tlx=-x1;x1=0;}
	if(y1<0){tly=-y1;y1=0;}
	if(x2>smaxx){trx=x2-smaxx-1;x2=smaxx-1;}
	if(y2>smaxy){y2=smaxy-1;}
	int nx,ny;
	nx=x2-x1,ny=y2-y1;
	XMS2RAM(lbf,hnd,o,bpb);hn=1;o+=bpb;
	k=ixs*tly+tlx;
	nl=tlx+trx;
	for(i=y1;i<y2;i++){
  asm push es;
  ccc=adrtbl[i][0];
  ddd=adrtbl[i][1];
  bbb=ccc+x1;  eee=ddd;
  asm adc eee,0;
  if(eee!=curbk)asm{mov ax,eee; call bankadr;}
  //ddd=curbk;
  _ES=ourseg;
  _SI=k,_CX=nx,_BX=x1,_DI=bbb;
  asm add si,[dr];
lpx:	asm{
	push	ds
	mov     ax,[v]
	mov	ds,ax
	mov     al,ds:[si]
	xor     es:[di],al
	pop	ds
	inc     di
	inc     si
	inc	bx
	mov     dx,bx
	add	dx,ccc
	mov     ax,ddd
	adc     ax,0
	cmp     ax,[curbk]
	jnz     incbank
	loop    lpx
	jmp	another
	}
incbank:asm{
	call	bankadr
	loop    lpx
	}
another:asm pop es;
	k+=nx;
	if(k>=bpb){
		if(hn==hmb-1) XMS2RAM(lbf,hnd,o,lablk);
		else XMS2RAM(lbf,hnd,o,bpb);
		k=tlx;
		hn++;
		o+=bpb;
		}
	else k+=nl;
	}
}
void Image::PutLine2Image(int y,int x1,int x2,char c){
 int d;
 int i;
 long o;
 if(x1>x2){d=x1;x1=x2;x2=d;}
 if(x1<0)x1=0;
 if(x2>=ixs)x2=ixs-1;
 d=x2-x1;
 for(i=0;i<d;i++)xbf[i]=c;
 o=y*ixs+x1;
 RAM2XMS(lbf,hnd,o,d);
}
void Image::FillWith(char c){
 int i;
 register int j;
 long o=0;
 for(i=0;i<hmb-1;i++){
   for(j=0;j<bpb;j++)xbf[j]=c;
   RAM2XMS(lbf,hnd,o,bpb);
   o+=bpb;
   }
 for(j=0;j<lablk;j++)xbf[j]=c;
 RAM2XMS(lbf,hnd,o,lablk);
}
void Image::PutORImage(int x,int y){}
void Image::ResizeImage(float newsize){}
void Image::ImageCopy(Image& img){}
void Image::RotateImage(int deg){}
void Image::puredata(int x,int y,char *data){}
void Image::putpicpix(int x,int y){}
void Image::ChangePalette(char far p[768]){
 int i;
 for(i=0;i<768;i++)palt[i]=p[i];
 }
