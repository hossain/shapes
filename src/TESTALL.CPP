//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

// This is the main of shapes games in mode 640x480x256

#include "DEFS.H"
#include "SCREEN.H"
#include "DEVICE.H"
#include "SVGALIB.H"
#include "PUBLIC.H"
#include "OBJCTS.H"
#include "GAME.H"

 Poly ssg[7];
 BitFont bf,sf;
 int Finish;

 void PreGame(),Title();
 void NullFunc(){/*VOID*/}
 void interrupt MyInt9(...);
 void loadTSR(),unloadTSR();

void main(int argc,char *argv[]){
 Poly pl;
 Game g;
 unsigned int i,j,k;
 long kz;
 char tmp[20];
 int far *v;
 int v1,v2;
 long far *kt;
//Check XMS:
 if(!XMSInst()){print(" Please add to you config.sys C:\\DOS\\HIMEM.SYS ");return;}
 print("XMS Free: ");kz=XMSfreeSize();print(ltos(kz,tmp));enter();
 if(kz<2097151){print("Sorry Minimum 2M free ram requird.");return;}
 if(XMSGet(&k,2000)){print("Sorry Can't Allocate Memory!!!,check you ram & your HIMEM.SYS");return;}XMSFree(k);

//Init Some Values:
 InitSinCosTan();
 InitCursor();
 for(i=0;i<7;i++) ssg[i].PolySet(i,5,1,ob[i],1);//Setting Seven Segments//
 if(!bf.FontLoad("MYF.FNT"))return ;
 if(!sf.FontLoad("htsfn14.FNT"))return ;
 j=0;
Proffessional:
 loadTSR();TSRLoaded=1;
Hack1Off:
 for(i=0;i<3000;i+=2) { i--;j*=2;j/=2; } //Hackers Off
 kz=XMSfreeSize();
 for(i=0;i<9000;i+=3)  i-=2; //Hackers Off
 if(j++>=600) goto hj;
 goto Hack1Off;
hj:
 xbf=new char far[8016];
 lbf=(long) xbf;
 if(!xbf)NEMError();
 int h;
 h=openf(SavedGames,0,0);
 g.HowManyPlayers=readw(h);
 closef(h);
 kt=(long far *)3;
 PreGame();
 *kt=10000;
 //Start Program:
if(whichvga()){
 svgamode();
 imouse();
 kt=(long far *)3;
 setmarea(0,0,623,472);
gametitle:
 if(*kt!=10000) return;
 Title();
gameinit:
 g.InitialGame();
gameselect:
 g.GotoSelecting();
 if(EndOfGame)goto xixi;
display:
 g.Display_Board();
 if(*kt!=10000)terminate(1);
start:     // message you are ready;
 g.StartGame();
 Finish=0;
while(!Finish){  // Game loop
 g.ProcessKey();
 g.ProcessMouse();
 g.ShowTime();
}
 FadeOut(100);
 g.GameFree();
 if (*kt!=10000) terminate(1);
 goto gametitle;
xixi:
 setscreen(0x3);
// Removing all allocated memories:
 for(i=0;i<7;i++) ssg[i].RemovePoly();
 bf.FontFree();
 print("Thanks for playing with my game:)");
 g.GameFree();
 terminate(0);
}
 terminate(0);
}

void Title(){
/* No Title */
}

void PreGame(){
 char far *ptr=(char far *)0xA0000000l;
 char *mem;
 char *mbuf;
 int i,j;
 long l;
 setscreen(0x13);
 mem=new char [768];
 for(i=0;i<768;i++)mem[i]=0;
 setmany(mem,0,256);
 j=openf("title1.hi",0,0);if(!j)AnyError("Files Not Complete.");
 readf(mem,5,j);
 mbuf=new char [16000];
 for(l=0;l<64000;l+=16000){
  readf(mbuf,16000,j);
  memcpy(ptr+l,mbuf,16000);
  }
 delete (mbuf);
// readf(ptr,64000,j);
 readf(mem,768,j);
 closef(j);
 for(i=0;i<768;i++) mem[i]/=4;
// delay(10000);
 FadeIn(mem,100);
 delay(30000);
 for(i=0;i<500;i++){
  delay(1000);
  if(gkhit())break;
  }
 FadeOut(100);
 delete(mem);
}

void interrupt MyInt9(...){
 asm{
  push ax
  push bx
  push dx
  push ds
  push es
  }
 int s=FP_SEG(buff);
 asm{
  mov ax,s
  mov ds,ax
  }
 asm{
  in  al,0x60
  xor bx,bx
  mov es,bx
  mov bl,byte ptr es:[0x417]
  mov bh,bl
  cmp al,83
  jne no_r
  and bl,0xc
  cmp bl,0xc
  jne no_r
  }
block:
 asm{
  mov al,0x20
  out 0x20,al
  jmp finished
  }
no_r:
  asm{
   and bh,4
   cmp bh,4
   jne legal
   cmp al,46
   je  block
   cmp al,224
   je  block
   }
legal:
 asm{
  pushf
  call oldi
  }
finished:
 asm{
  pop es
  pop ds
  pop dx
  pop bx
  pop ax
  }
}
void unloadTSR(){
int v1,v2;
 v2=long(oldi>>16);
 v1=(int)oldi;
 asm{
  push ds
  mov ax,0x2509
  mov bx,v2
  mov ds,bx
  mov dx,v1
  int 0x21
  pop ds
 }
}
void loadTSR(){
 long l2;
 int v1,v2;
 l2=(long)&MyInt9;
 asm{
  mov ax,0x3509
  int 0x21
  mov v1,bx
  mov bx,es
  mov v2,bx
  }
 oldi=long(long(v2)<<16)+long(v1);
 v2=long(l2>>16);
 v1=(int)l2;
 asm{
  push ds
  mov ax,0x2509
  mov bx,v2
  mov ds,bx
  mov dx,v1
  int 0x21
  pop ds
 }
}
