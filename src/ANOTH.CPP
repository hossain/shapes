//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------
#include "GAME.H"

int  CuSc=247;	//Current Scheme of colors

void Home::InitHome(int num,int colr){
 int i;
 int h;
 h=openf(GameShapes,0,0);
 if(!h)AnyError("some files needed.");
 ps=new int [100];
 orgx=0,orgy=0,bkcolor=colr;
 size=1;
 movef((200*num)+2,0,h);
 hs=readw(h);
 fpx=readw(h);
 fpy=readw(h);
 readf((char *)ps,194,h);
 closef(h);
}
void Home::Remove(){
 int i;
 delete ps;
}
void Home::ChangeColor(int newcol){
 bkcolor=newcol;
}
void Home::ShowHome(){
 int i,j,k=0,n;
 int x1,y1,x2,y2;
 dotcolor=bkcolor;
 for(j=0;j<hs;j++){
  n=ps[k++];x1=float(ps[k++]*size)+orgx;y1=float(ps[k++]*size)+orgy;
  for(i=0;i<n-1;i++){
   x2=float(ps[k++]*size)+orgx;y2=float(ps[k++]*size)+orgy;
   line(x1,y1,x2,y2);
   x1=x2,y1=y2;
   }
  }
 brdcolor=brc;dotcolor=bkcolor;filler(orgx+float(fpx*size),orgy+float(fpy*size));
}
void Home::MoveHome(int x,int y){
 orgx=x,orgy=y;
}
int  Home::ChkFill(){
 int rv=1;
 return(rv);
}
int Home::CenX(){
 int i,j,n,k=0;
 int mix,max;mix=ps[1];max=ps[1];
 n=ps[k++];
 for(j=0;j<n;j++,k+=2){
   if(ps[k]<mix)mix=ps[k];
   if(ps[k]>max)max=ps[k];
   }
 return (max+mix)/2;
}
int Home::CenY(){
 int i,j,n,k=0;
 int mix,max;mix=ps[2];max=ps[2];
 n=ps[k];k+=2;
 for(j=0;j<n;j++,k+=2){
   if(ps[k]<mix)mix=ps[k];
   if(ps[k]>max)max=ps[k];
   }
 return (max+mix)/2;
}
void Home::FitSize(int x,int y){
int j,n,k;
int mix,max;
float xs,ys;
/* k=0;n=ps[k];k+=2;mix=ps[2];max=ps[2];
 for(j=0;j<n;j++,k+=2){
   if(ps[k]<mix)mix=ps[k];
   if(ps[k]>max)max=ps[k];
   }
 ys=y/float(max-mix);
 k=0;n=ps[k];k++;mix=ps[1];max=ps[1];
 for(j=0;j<n;j++,k+=2){
   if(ps[k]<mix)mix=ps[k];
   if(ps[k]>max)max=ps[k];
   }
 ys=y/float(max-mix);
 if(ys<xs)size=ys;
 if(ys>=xs)size=xs;*/
 size=1;
}
void Home::ResizeHome(float nsz){
 size=nsz;
}
int Game::InitialGame(){
 int i,h;char pal[768];
 noh=MAXHOMES;
 for(i=0;i<7;i++) {
	Cards[i].PolySet(i,sss[i],100,ob[i],1);//Setting Seven Segments//
	Cards[i].PolyMove(120,150);
	droped[i]=0;
	}
 cc=-1; curhom=0; padcol=60; drpds=0;
 PlayerNamed=0;completed=0;
 h=openf("Options.dat",0,0);
 if(!h){
  GameMode=0;Langauge=0;
  }
 else{
  GameMode=readb(h);Langauge=readb(h);
  closef(h);
  }
// if(!PaletteLoad("standard.pal",pal))terminate(1);
 return 1;
}
void Game::GameFree(){
 int i;
 for(i=0;i<7;i++) Cards[i].RemovePoly();
 gb.Disturbe();
 bg.Disturbe();
 bb.Disturbe();
 sb.Disturbe();
 cd.Disturbe();
}
//void Game::AddHome(float *u){
// home.InitHome(u,homecolor[noh]);
// noh++;
//}
// _________________________________________________________________________
//                                         . . . . . . . . . . . . . . . . .
//      M A I N      S E L E C T I N G    . . . . . . . . . . . . . . . . .
// _________________________________________________________________________

void Game::GotoSelecting(){
 struct Players *pl;
 int S=0,Set=0,i,j,Opt=0,Opl=0,h,first=1,Page,Pages,lPage,Pitp,changei;
 static char mm[768];
 static char tm[20],tm2[10],str[80];
 Image im,im2;
 float f2;
 static char cm1[4]="OK",cm2[8]="Cancel",cm3[6]="Next",cm4[6]="Prev",cm5[8]="About";
 static char lan[2][8]={"English"," Farsi "},cm6[6]="Bomb!",mod[2][9]={"Standard","Minimum "};
// strcpy(cm1,"OK");strcpy(cm2,"Cancel"); strcpy(cm3,"Next");strcpy(cm4,"Prev");
 if(!im.LoadImage("MAINARTS.HI"))AnyError("File Mainarts.Hi needed! Sorry..");
 for(i=0;i<768;i++)mm[i]=0;
 setmany(mm,0,256);
 memcpy(mm,im.Palette(),720);
 for(i=720;i<768;i++)mm[i]=basecolor[i-720];
// for(i=0;i<640;i+=100)
//  for(j=0;j<480;j+=100)
 im.PutCutImage(0,0,160,100,176,116);
 LoadCursor();
Begin:
 PlayerNamed=0;
 im.PutCutImage(0,0,180,50,820,530);
if(first) {FadeIn(mm,200);first=0;}else setmany(mm,0,256);
// im.SetPalette();
 for(i=0;i<5;i++)
  im.PutCutImage(440,i*75+60,0,0,140,50);
 im.PutCutImage(440,60,280,0,419,50);
 dotcolor=255;
 for(i=0;i<5;i++)
  im.PutCutFore(443,i*75+68,0,96+i*31,120,124+i*30);
 im.PutCutFore(220,15,0,50,177,95);
 setmpos(300,200);
 ShowMouse();Set=0;
 gkhit();while(!ZF)gkhit();
 while(!Set){
  GetMouse();
  Mouser();
  if(momv)
   for(i=0;i<5;i++){
    if(ismousein(440,i*75+60,580,i*75+110)){
     if(i==Opt)continue;
     Opt=i;
     }
    }
  if(Opl!=Opt){
   RemoveMouse();
   im.PutCutImage(440,Opl*75+60,0,0,140,50);
   im.PutCutFore(443,Opl*75+68,0,96+Opl*31,120,124+Opl*30);
   im.PutCutImage(440,Opt*75+60,280,0,419,50);
   im.PutCutFore(443,Opt*75+68,0,96+Opt*31,120,124+Opt*30);
   Opl=Opt;
   ShowMouse();
   }
  GetKey();
 if(mbutts==1)
  for(i=0;i<5;i++)
   if(ismousein(440,i*75+60,580,i*75+110)){ZF=0;key1=13;}
 if(!ZF){
  if(key1==13){
     RemoveMouse();
     im.PutCutImage(440,Opt*75+60,140,0,280,50);
     im.PutCutFore(445,Opt*75+71,0,96+Opt*31,120,124+Opt*30);
     delay(150000);
     Set=1;
     }
  if(key1==0&&key2==80){
   Opt++;if(Opt>4)Opt=0;
   }
  if(key1==0&&key2==72){
   Opt--;if(Opt<0)Opt=4;
   }
   }
 }
ItemCheck:
 switch(Opt){// _________________ SELECT SHAPE: ___________________
 case 0:Set=0,Opt=0,Opl=-1,S=2;
   im.PutCutImage(60,110,160,135,180,245);
   im.PutCutImage(60,219,160,135,180,245);
   im.PutCutImage(260,110,160,135,180,245);
   im.PutCutImage(260,219,160,135,180,245);
   im.PutCutImage(60,80,420,0,530,30);
   im.PutCutImage(170,80,420,0,530,30);
   im.PutCutImage(60,328,420,0,530,50);
   im.PutCutImage(170,328,420,0,530,50);
   im.PutCutImage(60,378,420,0,530,22);
   im.PutCutImage(170,378,420,0,530,22);
   im.PutCutFore(80,82,0,250,179,275);
   dotcolor=0;boxfill(60,80,280,80);boxfill(280,80,280,400);boxfill(79,110,79,328);boxfill(80,327,260,327);
   dotcolor=240;boxfill(60,80,60,400);boxfill(60,400,280,400);boxfill(79,110,260,110);boxfill(260,110,260,328);
   dotcolor=4;bf.TypeStr(70,340,"Number: ");
   dotcolor=2;boxfill(200,340,255,363);
   dotcolor=5;itos(Opt+1,tm);bf.TypeStr(202,342,tm);
   CuSc=247;
   PutCommand(80,370,150,390,cm1);
   PutCommand(170,370,260,390,cm2);
   ShowMouse();
  while(!Set){
  GetKey();
  GetMouse();
  if(!ZF){
   if(key1==27){Opt=0;Opl=1;goto Begin;}
   if(key1==13)Set=1;
   if(key1==0&&key2==72){S=0;Opt--;if(Opt<0)Opt=noh-1;}
   if(key1==0&&key2==80){S=1;Opt++;if(Opt>=noh)Opt=0;}
   if(key1==9){RemoveMouse();dotcolor=2;boxfill(200,340,255,363);dotcolor=5;itos(Opt,tm);bf.GetStr(202,340,tm,3,100,2);Opt=stoi(tm)-1;ShowMouse();}
   }
  Mouser();
//  if(mbutts==2)Set=1;
  if(ProcessCommand(80,370,150,390,cm1))Set=1;
  if(ProcessCommand(170,370,260,390,cm2)){Opt=0;Opl=1;goto Begin;}
  if(momv){
   if( ismousein( 80, 110, 260, 140) && S!=0 ){S=0;RemoveMouse();im.PutCutFore(80, 300,0,300,179,320);im.PutCutFore(80,120,0,325,179,345);ShowMouse();}
   if( ismousein( 80, 300, 260, 330) && S!=1 ){S=1;RemoveMouse();im.PutCutFore(80, 120, 0,280,179,300);im.PutCutFore(80,300,0,345,179,365);ShowMouse();}
  }
  if(mbutts==1){
//   if(!ismousein(60,  60, 280, 380) ){Opt=0;Opl=1;goto Begin;}
   if(ismousein( 80, 110, 260, 140) ){Opt--;if(Opt<0)Opt=noh-1;w4fm(1);}
   if(ismousein( 80, 300, 260, 330) ){Opt++;if(Opt>=noh)Opt=0;w4fm(1);}
   if(ismousein(80,150,260,290)){Set=1;w4fm(1);}
   if(ismousein(100,330,260,360) ){RemoveMouse();dotcolor=2;boxfill(200,340,255,363);dotcolor=5;itos(Opt,tm);bf.GetStr(202,340,tm,3,100,2);Opt=stoi(tm)-1;ShowMouse(); }
//   w4fm(1);
  }
  if(Opt >= noh) Opt = 0;
  if(Opt != Opl) {
   RemoveMouse();
//   im.PutCutImage(80,110,0,245,180,465);
   dotcolor=254;boxfill(80,111,259,326);
   im.PutCutFore(80,120,0,280,179,300);
   im.PutCutFore(80,300,0,300,179,320);
   if(S==0){im.PutCutFore(80, 300,0,300,179,320);im.PutCutFore(80,120,0,325,179,345);}
   if(S==1){im.PutCutFore(80, 120, 0,280,179,300);im.PutCutFore(80,300,0,345,179,365);}
   dotcolor=251;boxfill(200,340,255,363);   dotcolor=250;box(200,340,255,363);
   dotcolor=245;itos(Opt+1,tm);bf.TypeStr(202,340,tm);

   home.InitHome(Opt,241);
   home.SetCurBack(254);
   home.MoveHome(170-home.CenX(),220-home.CenY());
   home.FitSize(150,150);
   home.ShowHome();
   home.Remove();
   ShowMouse();
   Opl=Opt;
   }
  }
  if(PlayerNamed){
   i=Opt/8,h=Opt%8;
   if(curplayer.games[i]&(1<<h)){RemoveMouse();Message("Warning","You completed this shape");Opt=0;goto ItemCheck;}
   }
  curhom=Opt;
  break;
 case 1://----------------------- Select a name...........................
 Set=0; //=========================================Player Station=========
 if(!HowManyPlayers){Message("Note","No Player Found!");Opt=0;Opl=1;goto Begin;}
 PlayerNamed=0;
 lPage=0;Page=0;Opt=0;Opl=0,Pages=(HowManyPlayers/10)+1;
 pl=new Players[10];
 Pitp=10;if(Pages==1)Pitp=HowManyPlayers;
 dotcolor=240+7;boxfill(0,0,640,480);
 CuSc=250;
 h=openf(SavedGames,0,0);
 if(!h)AnyError("Can't Opend Persons File:<");
 if(readw(h)!=HowManyPlayers)AnyError("Person File is bad...");
 readf((char *)pl,60*Pitp,h);
 PutCommand (70,22,560,458,"");
 im.PutCutFore (170,30,530,0,820,49);
 PutCommand (80,415,180,445,cm4);
 PutCommand (195,415,295,445,cm1);
 PutCommand (310,415,425,445,cm2);
 PutCommand (440,415,550,445,cm3);
 for(i=80;i<=360;i+=30) PutCommand2(90, i+5 , 550, i+24 , "");
 for(i=0;i<Pitp;i++)PutCommand2(90,i*30+85,550,i*30+104,pl[i].name);
 dotcolor=246;PushCommand2(92,Opt*30+87,548,Opt*30+102,pl[0].name);
 dotcolor=245;sf.TypeStr(100,390,"Number:");sf.TypeStr(260,390,"Completes:");sf.TypeStr(420,390,"Time:");
 PutCommand2(190,388,250,407,"1");itos(pl[0].howg,tm);PutCommand2(370,388,410,407,tm);
 itos((long)pl[Opt].totaltime/60,tm);strcat(tm,":");itos( (long) pl[Opt].totaltime%60,tm2);strcat(tm,tm2);
 PutCommand2(475,388,540,407,tm);
 PlayerNumber=0;changei=0;
 ShowMouse();
 while(!Set){
  GetMouse();
  Mouser();
  GetKey();
  if(ProcessCommand(195,415,295,445,cm1))Set=1;
  if(ProcessCommand(310,415,425,445,cm2))Set=2;
  if(ProcessCommand(80,415,180,445,cm4)) {Page--; if(Page<0)Page=Pages-1;}
  if(ProcessCommand(440,415,550,445,cm3)) {Page++; if(Page>=Pages)Page=0; }
  if(mbutts==1){
   for(i=0;i<Pitp;i++)if(Opt!=i&&ismousein(90,i*30+85,550,i*30+104))Opt=i;
   if(ismousein(190,388,250,407)){ZF=0;key1=9;}
   }
  if(!ZF){
   if(key1==0&&key2==72) { Opt--; if(Opt<0)Opt=Pitp-1; }
   if(key1==0&&key2==80) { Opt++; if(Opt>=Pitp)Opt=0; }
   if(key1==0&&key2==75) { Page--; if(Page<0)Page=Pages-1; }
   if(key1==0&&key2==77) { Page++; if(Page>=Pages)Page=0; }
   if(key1==13)Set=1;
   if(key1==27)Set=2;
   if(key1==9){
    dotcolor=251;
    RemoveMouse();
    boxfill(192,390,248,405);
    dotcolor=241;
    sf.GetStr(192,390,str,4,50,251);
    ShowMouse();
    i=stoi(str)-1;
    if(i<HowManyPlayers){Page=i/10;Opt=i%10;}
    }
   }
  if(Page!=lPage){
   movef(Page*600+2,0,h);
   Pitp=10;if(Page==Pages-1) Pitp=HowManyPlayers%10;
   readf((char *)pl,60*Pitp,h);
   changei=1;
   if(Opt>=Pitp){Opt=0;}
//   Opt=0;Opl=0;
   for(i=80;i<=360;i+=30) PutCommand2(90, i+5 , 550, i+24 , "");
   for(i=0;i<Pitp;i++)PutCommand2(90,i*30+85,550,i*30+104,pl[i].name);
//   dotcolor=246;PushCommand2(92,Opt*30+87,548,Opt*30+102,pl[Opt].name);
//   itos(10*Page,tm);PutCommand2(190,388,250,407,tm);itos(pl[Opt].howg,tm);PutCommand2(370,388,410,407,tm);
//   itos((long)pl[Opt].totaltime/60,tm);strcat(tm,":");itos( (long) pl[Opt].totaltime%60,tm2);strcat(tm,tm2);
//   PutCommand2(475,388,540,407,tm);
   lPage=Page;
   }
  if(Opt!=Opl||changei){
   RemoveMouse();
   if(Opl<Pitp)PutCommand2(90,Opl*30+85,550, Opl*30+104,pl[Opl].name);
   dotcolor=246;PushCommand2(92,Opt*30+87,548,Opt*30+102,pl[Opt].name);
   itos(10*Page+Opt+1,tm);PutCommand2(190,388,250,407,tm);itos(pl[Opt].howg,tm);PutCommand2(370,388,410,407,tm);
   itos((long)pl[Opt].totaltime/60,tm);strcat(tm,":");itos( (long) pl[Opt].totaltime%60,tm2);strcat(tm,tm2);
   PutCommand2(475,388,540,407,tm);
   ShowMouse();
   Opl=Opt;changei=0;
   }
 }
  key1=0;
  delete(pl);
  closef(h);
  if(Set!=1){Opt=0;Opl=1;goto Begin;}
  PlayerNumber=Page*8+Opt;
  curplayer.howg=pl[Opt].howg;
  curplayer.totaltime=pl[Opt].totaltime;
  for(i=0;i<20;i++)curplayer.games[i]=pl[Opt].games[i];
  for(i=0;i<34;i++)curplayer.name[i]=pl[Opt].name[i];
  Opt=0;PlayerNamed=1;
  im.PutCutImage(0,0,180,50,820,530);
  goto ItemCheck;
  break;
 ////////////////////////////////////////////////////////////////////////////
 case 2:///////////// -------- (((((((((((((((( H I G H   S C O R E S )))))))
 ////////////////////////////////////////////////////////////////////////////
  FadeOut(100);
  HighScoresShow();
  first=1;
  Opt=0;Opl=2;goto Begin;
  break;
 case 3://////////////O O O   P P P   T T T   I I I   O O O   N N N   S S S
 ///////-------------------------============================****************++++
  h=openf("Options.dat",0,0);
  if(!h){
   h=newfile("Options.dat",0);
   GameMode=0;Langauge=0;
   writeb(0,h);writeb(0,h);
   closef(h);
   }
  else{
   GameMode=readb(h);
   Langauge=readb(h);
   closef(h);
   }
  dotcolor=246;boxfill(0,0,640,480);
  CuSc=253;PutCommand(80,80,560,400,"");
  PutCommand(120,360,230,385,cm1);
  PutCommand(410,360,520,385,cm2);
  PutCommand(250,360,390,385,cm5);
  dotcolor=245;bf.TypeStr(260,90,"Options");
  PutCommand2(100,125,540,350,"");
  dotcolor=240;
  sf.TypeStr(120,150,"Names Langauge "); PutCommand(400,148 ,520,172,lan[Langauge]);
  sf.TypeStr(120,190,"Clear One Name          Number:");PutCommand2(450,188,520,210,"");
  sf.TypeStr(120,230,"Clear All Names"); PutCommand(400,228,520,252,cm6);
  sf.TypeStr(120,270,"Game Files Mode"); PutCommand(400,268,520,292,mod[GameMode]);
//  sf.TypeStr(120,310,"
 changei=0;
  ShowMouse();
  while(1){
  GetMouse();
  Mouser();
  GetKey();
  if(!ZF){
    if(key1==13){break;}
     if(key1==27){break;}
    }
  if(mbutts==1&&ismousein(450,188,520,210)){
    RemoveMouse();
    PutCommand2(450,188,520,210,"");
    dotcolor=241;
    sf.GetStr(455,192,str,4,50,253);
    i = stoi(str)-1;
    if(i>=0 && i<HowManyPlayers){
      h=openf(SavedGames,2,0);
      if(!h)Message("Warning...","Cant Open Person File");
      else{
       movef((60*i)+2,0,h);
       readf((char *)&curplayer,60,h);
       strcpy(str,"Sure to delete ");
       strcat(str,curplayer.name);
       if(GetOK("Warning",str)){
	HowManyPlayers--;
	movef(0,0,h); writew(HowManyPlayers,h);
	movef(60*HowManyPlayers+2,0,h); readf((char *)&curplayer,60,h);
	movef(60*i+2,0,h); writef((char *)&curplayer,60,h);
	}
       closef(h);
       }
     }
     ShowMouse();
   }
  if(ProcessCommand(400,148 ,520,172,lan[Langauge])){RemoveMouse();Langauge^=1;PutCommand(400,148 ,520,172,lan[Langauge]);ShowMouse();}
  if(ProcessCommand(400,228,520,252,cm6)){RemoveMouse();if(GetOK("Warning!!!","Are you sure you want delete all?"))changei=1;ShowMouse();}
  if(ProcessCommand(400,268,520,292,mod[GameMode])){RemoveMouse();GameMode^=1;PutCommand(400,268,520,292,mod[GameMode]);ShowMouse();}
  if(ProcessCommand(120,360,230,385,cm1)){Set=1;break;}
  if(ProcessCommand(410,360,520,385,cm2)){Set=2;break;}
  if(ProcessCommand(250,360,390,385,cm5)){break;}
  }
  if(Set==1){
   if(changei){
    h=newfile(SavedGames,0);
    if(!h)Message("Warning","The Names Not Removed!");
    else{
     HowManyPlayers=0;
     writew(0,h);
     closef(h);
     }
    }
   h=openf("Options.dat",2,0);
   if(!h)Message("Warning","Options Not Saved.");
   else{
    writeb(GameMode,h);
    writeb(Langauge,h);
    closef(h);
    }
   }
  Opt=0;Opl=1;goto Begin;
  break;
 case 4:////[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
 ///////////////QQQ     UUU      III     TTT:::::::::::::::::::::::::::()()()()
 ///////////]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
  FadeOut(100);
  im.Disturbe();
  bf.FontFree();
  setscreen(0x03);
  print("Thanks for playing with my game:)");
  terminate(0);
  break;
 }
 im.Disturbe();
}
int  Game::CheckFill(){
 return home.ChkFill();
}
void Game::Display_Board(){//_____________Board Making:_____________________
 static char cm1[8]="Help",cm2[8]="Pause",cm3[8]="Exit";
 int i,j;
 char t[10];
 char palr[768];
 char far *ppp;
// if(!PaletteLoad("STANDARD.PAL",palr))AnyError("Standard.Pal needed!");
// setmany(palr,0,256);
 if(!gb.LoadImage("GAMEPAD.HI"))AnyError("File Gamepad.Hi needed! Sorry..");
 if(GameMode){if(!bg.LoadHIS("MINBKG.HI",0,100,102773))AnyError("File MinBkg.Hi not found or Error!");}
 else{if(!bg.LoadHIS("BACKGRND.HIS",curhom,100,102773))AnyError("File Backgrnd.His not found or Error!");}
 for(i=0; i<768; i++) palr[i]=0;
 setmany(palr, 0, 256);
 ppp=gb.Palette();
 for(i=0;i<300;i++) palr[i]=ppp[i];
 ppp=bg.Palette();
 for(i=300;i<720;i++) palr[i]=ppp[i-300];
 for(i=720;i<768;i++) palr[i]=basecolor[i-720];
 gb.PutCutImage(0,0,204,284,220,300);
 LoadCursor();
 for(i=0;i<640;i+=50)
   for(j=0;j<480;j+=104)
     gb.PutCutImage(i,j,200,0,250,104) ; //Background asli
// Menarha:
 gb.PutCutFore(15, 20,220,250,249,449) ; gb.PutCutFore(15, 218,250,250,279,449) ;
 gb.PutCutFore(345,20,220,250,249,449) ; gb.PutCutFore(345,218,250,250,279,449) ;

 //bg.PutImage(44,78); // Shape Background

 gb.PutCutImage( 15,418,  0,450,280,490) ; //  Divar ziri
 gb.PutCutImage(295,418,200,110,280,150) ; //
 PutCommand(40,425,120,450,cm1);
 PutCommand(140,425,240,450,cm2);
 PutCommand(260,425,350,450,cm3);
 dotcolor=86;boxfill(44,78,344,418);
//  home.ResizeHome(0.982);
 home.InitHome(curhom,1);
 home.FitSize(300,340);
 home.MoveHome(195-home.CenX()*2,242-home.CenY()*2);
 home.SetCurBack(86);
 home.ShowHome();
 stp=home.size;
 for(i=0;i<7;i++)   Cards[i].ResizePoly(stp);
 home.Remove();
 if(!bb.GetImage(44,78,344,418))AnyError("Not Enough Ram:(=");
 if(!sb.GetImage(0,0,639,479))AnyError("Not Enough Ram:(=");
 if(!cd.GetImage(0,0,170,170))AnyError("Not Enough Ram:(=");
 GamePad();
 FadeIn(palr,100);
 setmpos(520,200);
 ShowMouse();
// im.Disturbe();
}
void Game::GamePad(){//________________ Game Pad ------------------------
  int i,cenx,ceny;
  gb.PutCutImage(385,15,0,300,219,448);
  gb.PutCutImage(385,163,0,300,219,448);
  gb.PutCutImage(385,311,0,300,219,448);
  for(i=0;i<7;i++)
   if(!droped[i] && i!=cc )
    gb.PutCutFore(segcmds[i][0], segcmds[i][1], segcmds[i][2], segcmds[i][3], segcmds[i][4], segcmds[i][5]);
  dotcolor=125; // boxfill(30,30,390,440);
  bb.PutImage(44,78);
  for(i=0;i<7;i++)
   if(droped[i])
    {
     Cards[i].PutPolyPic(bg,44,78);
     dotcolor=246;Cards[i].PolyDraw();
     cenx=Cards[i].mancx+Cards[i].PolyX();ceny=Cards[i].mancy+Cards[i].PolyY();
//     if(i==5){cenx=(cenx+Cards[i].polx(3))/2;ceny=(ceny+Cards[i].poly(3))/2;}
//     if(i==6){cenx=(cenx+Cards[i].polx(1))/2;ceny=(ceny+Cards[i].poly(1))/2;}
     gire[i][0]=cenx-10;     gire[i][1]=ceny-10;
     gire[i][2]=cenx+10;     gire[i][3]=ceny+10;
     gb.PutCutFore(gire[i][0],gire[i][1],250,0,279,29);
    }
 ShowTime();
 sb.Disturbe();
 if(!sb.GetImage(0,0,639,479))NEMError();
}
void Game::RemoveCard(){
 int y2;
 y2=Cards[cc].miny()+cd.Ysz();
 if(y2>479)y2=479;
 sb.PutCutImage(Cards[cc].minx(),Cards[cc].miny(),Cards[cc].minx(),Cards[cc].miny(),Cards[cc].minx()+cd.Xsz(),y2);
}
void Game::PutCard(){
// waitretrace();
 cd.PutImage(Cards[cc].minx(),Cards[cc].miny());

}
void Game::ProcessCard(){
 cd.Disturbe();
 if(!cd.MakeImage(Cards[cc].pmaxx()-Cards[cc].pminx(),Cards[cc].pmaxy()-Cards[cc].pminy()))NEMError();
 cd.FillWith(0);
 Cards[cc].PutPolyInPic(cd,242);
 cd.PutImage(0,0);
 getch();
}
void Game::StartGame(){        //------------- Start & End
 starttime=cpuclock();
}
void Game::EndGame(){
 endtime=cpuclock();
 completed=1;
}
void Game::TimeUsed(int& m,int& s){
 m=int(float(endtime-starttime)/18.2)/60;
 s=int(float(endtime-starttime)/18.2)%60;
}
void Game::ShowTime(){         //==========-( Time Displaying )-----*****====
 char r[10],t[10];
 static int m,s,s2;
 endtime=cpuclock();
 TimeUsed(m,s2);
 if(s2==s)return; s=s2;
 strcpy(r,itos(m,t));
 strcat(r,":");
 strcat(r,itos(s,t));
 gb.PutCutImage(435,400,0,490,150,529);
 dotcolor=241;
 bf.TypeStr(548-bf.StrSize(r)/2,410,r);
}
void Game::Completed(){
 int i;
 bg.PutImage(44,78);
 EndGame();
 dotcolor=0;
 for(i=0;i<7;i++)Cards[i].PolyDraw();
 for(i=0;i<5000&&!gkhit();i++)delay(1000);
 Thriumph();
 if(!PlayerNamed)GetPlayerName();
 Scoring();
 Finish=1;
}
void Game::DragDrop(){		//_______________ Drag and Drop
 int lmx,lmy;
 int i,k;
 w4fm(1);
 Cards[cc].PolyMove(mox,moy);
 ProcessCard();
 PutCard();
 lmx=mox,lmy=moy;
 while(1){
  GetMouse();
  if(gkhit()==27){Scoring();Finish=1;return;}
  if(lmx!=mox || lmy!=moy){
   RemoveCard();
   Cards[cc].PolyMove(mox,moy);
   PutCard();
   lmx=mox,lmy=moy;
  }
  if(mbutts){
   for(i=0;i<40;i++) {k=kmouse(&mox,&moy);if(k!=mbutts)break;delay(1500);}
   if(k==3)mbutts=3;
   w4fm(3);w4fm(1);w4fm(2);w4fm(4);
   }
  if(mbutts==1){
//    setmarea(0,0,623,472);
    RemoveCard();
    if(350<Cards[cc].xcent()) {droped[cc]=0;cc=-1;GamePad();return;}
    if(Cards[cc].CheckFillPoly(1))drpds++; else    {PutCard(); continue;}
    droped[cc]=1;
    if(drpds==7){Completed();return;}
    GamePad();
    return;
  }
  if(mbutts==2){
   RemoveCard();
   Cards[cc].RotatePoly(45);
   ProcessCard();
   PutCard();
  }
  if(mbutts==3){
   RemoveCard();
   Cards[cc].MirrorPoly();
   ProcessCard();
   PutCard();
  }
  if(mbutts==4){
   RemoveCard();
   Cards[cc].RotatePoly(315);
   ProcessCard();
   PutCard();
  }
  ShowTime();
 }
}
void Game::ProcessKey(){       //_____________________ Processing KeyBoard
GetKey();
if(ZF)return;
if(key1==27){Scoring();Finish=1;}
if(key1==13 && cc!=-1){
   RemoveCard();
   if(350<Cards[cc].xcent()) {droped[cc]=0;cc=-1;GamePad();return;}
   if(Cards[cc].CheckFillPoly(1))drpds++; else    {PutCard(); return;}
   droped[cc]=1;
   if(drpds==7){Completed();return;}
   GamePad();
   return;
 }
if(key1<'8'&&key1>'0'){
 if(cc+1)RemoveCard();//else Cards[cc].PolyMove(200,200);
 cc=key1-'1';
 if(droped[cc]){drpds--;droped[cc]=0;}
 GamePad();
 ProcessCard();
 PutCard();
 return;
 }
if(key1==0 && key2==59)Help();
if(key1=='p'||key1=='P')GamePause();
if(key1==0 && key2==68){Scoring();Finish=1;}
if(key1==0 && cc+1){
 switch(key2){
  case 80:if(!droped[cc]){RemoveCard();Cards[cc].PolyMove(Cards[cc].PolyX(),Cards[cc].PolyY()+stp);PutCard();} break;
  case 72:if(!droped[cc]){RemoveCard();Cards[cc].PolyMove(Cards[cc].PolyX(),Cards[cc].PolyY()-stp);PutCard();} break;
  case 75:if(!droped[cc]){RemoveCard();Cards[cc].PolyMove(Cards[cc].PolyX()-stp,Cards[cc].PolyY());PutCard();} break;
  case 77:if(!droped[cc]){RemoveCard();Cards[cc].PolyMove(Cards[cc].PolyX()+stp,Cards[cc].PolyY());PutCard();} break;
  case 81:if(!droped[cc]){RemoveCard();Cards[cc].RotatePoly(45);ProcessCard();PutCard();}   break;
  case 73:if(!droped[cc]){RemoveCard();Cards[cc].RotatePoly(315);ProcessCard();PutCard();}   break;
  case 71:if(!droped[cc]){RemoveCard();Cards[cc].MirrorPoly();ProcessCard();PutCard();}   break;
  }
 }
}
void Game::ProcessMouse(){
 static char cm1[8]="Help",cm2[8]="Pause",cm3[8]="Exit";
 int i;
 GetMouse();
 Mouser();
 if(ProcessCommand(40,425,120,450,cm1))Help();
 if(ProcessCommand(140,425,240,450,cm2))GamePause();
 if(ProcessCommand(260,425,350,450,cm3)){Scoring();Finish=1;return;}
 if(mbutts==1){
  for(i=0;i<7;i++){
   if(!droped[i]&&ismousein(segcmds[i][0],segcmds[i][1],segcmds[i][0]+(segcmds[i][4]-segcmds[i][2]),segcmds[i][1]+(segcmds[i][5]-segcmds[i][3])))
     { cc=i; GamePad(); setmpos(200,200); DragDrop(); setmpos(500,180); if(droped[i])setmpos(gire[cc][0]+10,gire[cc][1]+15); ShowMouse();  return; }
   if(droped[i]&&ismousein(gire[i][0]-10,gire[i][1]-10,gire[i][2],gire[i][3]))
     { cc=i; drpds--; droped[cc]=0; GamePad(); setmpos(Cards[cc].PolyX(),Cards[cc].PolyY()); DragDrop(); setmpos(500,180);if(droped[i]) setmpos(gire[cc][0]+10,gire[cc][1]+15);ShowMouse(); return; }
   }
  }
}
void Game::Thriumph(){         //___________Congratulation______________
 int i;
 for(i=0;i>=-100;i-=2){waitretrace(); bg.PutDoubleSize(20,i*2); delay(1000);}
 dotcolor=0; bf.TypeStr(80,10,"Congratulation ! ! !  ");
 gb.PutCutFore(250,50,0,531,255,585);
 delay(650000);
}
void Game::Scoring(){         //___________Score Computing______________
 int i,h;
 long l;
 if(!PlayerNamed)return;
 h=openf(SavedGames,0,0);
 if(!h)AnyError("Players Data File Cant Open:<");
 movef((PlayerNumber*60)+2, 0, h);
 readf((char *)&curplayer,60,h);
 closef(h);
 l=(endtime-starttime)/18.2;
 if(completed) curplayer.howg+=1;
 curplayer.totaltime += l;
 i=curhom/8, h=curhom%8;
 if(completed) curplayer.games[i] |= 1<<h;
 h=openf(SavedGames,2,0);
 if(!h)AnyError("Players Data File Cant Open:<");
 movef((PlayerNumber*60)+2, 0, h);
 writef((char *)&curplayer, 60, h);
 closef(h);
 Finish=1;
}
int Game::HighScoresShow(){
 Image im;
 int i,j,h,n,k,y=150; //x=100
 static char tm[10],tm2[10],*ps;
 int *ns,*vs;
 long *l;
 struct Players pl;
 if(!im.LoadImage("HSCOREB.HI"))AnyError("HSCOREB.HI Needed.");
 ps=new char [768];
 im.PutImage(0,0);
 memcpy(ps,im.Palette(),720);
 for(i=720;i<768;i++)ps[i]=basecolor[i-720];
 FadeIn(ps,100);
 delete (ps);
 if(HowManyPlayers){
// pl=new struct Players ;
 ns=new int [HowManyPlayers];
 vs=new int [HowManyPlayers];
 l=new long [HowManyPlayers];
// for(i=0;i<HowManyPlayers;i++)ns[i]=0;
 h=openf(SavedGames,0,0);
 if(!h)AnyError("Person file not found.");
 if(readw(h)!=HowManyPlayers)AnyError("Person File Has Errors");
 for(i=0;i<HowManyPlayers;i++){
  readf((char *)&pl,60,h);
  ns[i]=i;vs[i]=pl.howg;l[i]=pl.totaltime;
  }
 for(i=0;i<HowManyPlayers;i++)
  for(j=i+1;j<HowManyPlayers;j++){
   if(vs[i]<vs[j]){k=vs[i];vs[i]=vs[j];vs[j]=k; k=ns[i];ns[i]=ns[j];ns[j]=k; k=l[i];l[i]=l[j];l[j]=k;}
   if(vs[i]==vs[j]&&l[i]>l[j]){k=vs[i];vs[i]=vs[j];vs[j]=k; k=ns[i];ns[i]=ns[j];ns[j]=k; k=l[i];l[i]=l[j];l[j]=k;}
   }
 for(j=0;j<10&&j<HowManyPlayers;j++){
  movef(ns[j]*60+2,0,h);
  readf((char *)&pl,60,h);
  if(!j)dotcolor=6;else dotcolor=11*16;
  sf.TypeXStr(100,y,pl.name,200);
  itos(pl.howg,tm);sf.TypeStr(380,y,tm);
  itos((long)pl.totaltime/60,tm);strcat(tm,":");itos( (long) pl.totaltime%60,tm2);strcat(tm,tm2);
  sf.TypeStr(480,y,tm);
  y+=25;
  }
 delete (ns);
 delete (vs);
 delete (l);
 }
 getch();
 FadeOut(100);
 im.Disturbe();

}
void Game::GetPlayerName(){
 char ch=0;
 int i,h;
 CuSc=253;
 GetName(400,32,"Enter Your Name:",curplayer.name,Langauge);
 if(curplayer.name[0]==0){PlayerNamed=0;return;}
 PlayerNamed=1;
 PlayerNumber=HowManyPlayers;
 curplayer.howg=0;
 for(i=0;i<20;i++)curplayer.games[i]=0;
 i=curhom/8,h=curhom%8;
 curplayer.games[i]|=1<<h;
 curplayer.totaltime=0;
 h=openf(SavedGames,2,0);
 if(!h)AnyError("Players Data File Cant Open:<");
 writew(HowManyPlayers+1,h);
 movef((PlayerNumber*60)+2, 0, h);
 writef((char *)&curplayer, 60, h);
 HowManyPlayers++;
 closef(h);
}
void Game::GamePause(){
long l,l2;
int i,j;
Image im;
l=cpuclock();
if(!im.GetImage(0,0,640,480))AnyError("Not Enough Ram................");
 for(i=0;i<640;i+=50)
   for(j=0;j<480;j+=104)
     gb.PutCutImage(i,j,200,0,250,104) ; //Background asli
dotcolor=242;bf.TypeStr(110,230,"Press Any Key To Continue");
getch();
im.PutImage(0,0);
l2=cpuclock();
starttime+=(l2-l);
im.Disturbe();
}
void Game::Help(){
int i,j;
long l,l2;
Image im;
l=cpuclock();
if(!im.GetImage(0,0,640,480))AnyError("Not Enough Ram..............");
for(i=0;i<640;i+=80)
  for(j=0;j<480;j+=80)
     gb.PutCutImage(i,j,200,151,280,231) ; //Background asli
dotcolor=245;bf.TypeStr(280,10,"HELP");
dotcolor=240;sf.TypeStr(40,50,"These keys are available:");
dotcolor=241;sf.TypeStr(30,70 ,"ESC or F10 : Back to main menu.");
dotcolor=241;sf.TypeStr(30,90 ,"P :            Pause");
dotcolor=241;sf.TypeStr(30,110,"F1 :          This Help");
dotcolor=241;sf.TypeStr(30,130,"1-7 :         Choose Segment");
dotcolor=242;sf.TypeStr(40,150,"When You Choose a Segment:");
dotcolor=241;sf.TypeStr(30,170,"Enter :        Drop Segment");
dotcolor=241;sf.TypeStr(30,190,"Arrows :      Move Segment");
dotcolor=241;sf.TypeStr(30,210,"PgUp,PgDn :  Rotate Segment");
dotcolor=241;sf.TypeStr(30,230,"Home :          Mirror Segment");
dotcolor=240;sf.TypeStr(40,250," Also you can click on the segment that are");
dotcolor=240;sf.TypeStr(30,270,"in right part of screen with your mouse.");
dotcolor=240;sf.TypeStr(40,290," When you drop a segment you can change it's");
dotcolor=240;sf.TypeStr(30,310,"place by clicking on it's handhold.");
dotcolor=241;sf.TypeStr(30,330,"Left Botton : Drop the segment");
dotcolor=241;sf.TypeStr(30,350,"Right Botton: Rotate the segment");
dotcolor=241;sf.TypeStr(30,370,"Left & Right: Mirror the segment");
dotcolor=244;sf.TypeStr(40,400,"Game Seaseon:");
dotcolor=242;sf.TypeStr(30,420,"You must fill the left shape by the right segments");
dotcolor=242;sf.TypeStr(30,440,"Know that the time is not most important.");
dotcolor=242;sf.TypeStr(30,460,"But the deal of completed shapes has most value.");
if(!getch())getch();
for(i=0;i<640;i+=80)
  for(j=0;j<480;j+=80)
     gb.PutCutImage(i,j,200,151,280,231) ; //Background asli
dotcolor=245;bf.TypeStr(260,10," üþ‘õ÷û¤ ");
dotcolor=240;sf.TypeStr(340,50,":¢÷ª‘“ üõ ñ‘ãê ‘û¢þóî öþ");
dotcolor=241;sf.TypeStr(250,70 ,"ESC or F10 :  üó¬ ¯þŸõ ù“ –ªð¥‘“");
dotcolor=241;sf.TypeStr(250,90 ,"P :                             éìø— ");
dotcolor=241;sf.TypeStr(250,110,"F1 :                          üþ‘õ÷û¤");
dotcolor=241;sf.TypeStr(250,130,"1-7 :                     ùã¯ì ’‘¡—÷ ");
dotcolor=242;sf.TypeStr(350,150,":¢ª ’‘¡—÷ üùã¯ì ü—ìø");
dotcolor=241;sf.TypeStr(250,170,"Enter :               ùã¯ì ö¢¢ ¤¤ì");
dotcolor=241;sf.TypeStr(250,190,"‘ú—ú› :               ùã¯ì ö¢¢ –î¤Ÿ");
dotcolor=241;sf.TypeStr(250,210,"PgUp,PgDn :           ùã¯ì ö¢÷‘¡¤");
dotcolor=241;sf.TypeStr(250,230,"Home :                ùã¯ì ö¢÷¢¤ð¤“");
dotcolor=240;sf.TypeStr(110,250,"” –õ¨ ¤¢ ùî ü—‘ã¯ì §ø‘õ ‘“ ¢þ÷ø—üõ ‘õª öþ÷õû");
dotcolor=240;sf.TypeStr(230,270," .¢þ¤¢¤“ ” íþóî ‘“ ¤ ¢÷ù¢ª ù¢þ ùŸê¬");
dotcolor=240;sf.TypeStr(110,290,"üø¤ ùî üù¤þð íõî“ ¢þ÷ø—þõ ¢þ—ª£ð ¤ üùã¯ì ü—ìø ");
dotcolor=240;sf.TypeStr(380,310,".¢þû¢ –î¤Ÿ ¤ ö –¨ ö");
dotcolor=241;sf.TypeStr(250,330," ” ùõî¢ :           ùã¯ì ö¢¢ ¤¤ì");
dotcolor=241;sf.TypeStr(250,350," –¨¤ ùõî¢:            ùã¯ì ö¢÷‘¡¤");
dotcolor=241;sf.TypeStr(250,370," –¨¤ ø ” ùõî¢:    ùã¯ì ö¢÷¢¤ð¤“");
dotcolor=244;sf.TypeStr(440,400,"  ü¥‘“ é¢û");
dotcolor=245;sf.TypeStr(40 ,420,":¢þ÷î ¤• ¤ ” –õ¨ ž¤¯ –¨¤ –õ¨ ùã¯ì –ìû íõî“ ¢þ‘“ ‘õª");
dotcolor=245;sf.TypeStr(90 ,440,"  –‘ã¯ì ¢¢ã— öþ ùîó“ ¢¤¢÷ ü÷¢÷ –þõû ö‘õ¥ ùî ¢þ÷î ù›ø—");
dotcolor=245;sf.TypeStr(240,460,".¢¤¢ ¤ –þõû öþ¤—ªþ“ ùî –¨ ù¢ª ñõ‘î");
if(!getch())getch();
im.PutImage(0,0);
l2=cpuclock();
starttime+=(l2-l);
im.Disturbe();
}
//
//       Game Functions Are Above^
//

void PutCommand(int x1,int y1,int x2,int y2,char *name){
 dotcolor=CuSc+1;boxfill(x1,y1,x2,y2);
 dotcolor=240;boxfill(x2,y1,x2,y2);boxfill(x1,y2,x2,y2);
 dotcolor=CuSc+2;boxfill(x1+1,y1+1,x2-1,y1+1);boxfill(x1+1,y1+1,x1+1,y2-1);
 dotcolor=CuSc;boxfill(x2-1,y1+1,x2-1,y2-1);boxfill(x1+1,y2-1,x2-1,y2-1);
 dotcolor=240;sf.FontSize=1;
 sf.TypeStr((x1+x2)/2 - sf.StrSize(name)/2 ,(y1+y2)/2-7, name);
}
void PushCommand(int x1,int y1,int x2,int y2,char *name){
 dotcolor=CuSc+1; boxfill(x1,y1,x2,y2);
 dotcolor=240; box(x1,y1,x2,y2);
 dotcolor=CuSc; box(x1+1,y1+1,x2-1,y2-1);
 dotcolor=240;sf.FontSize=1;
 sf.TypeStr((x1+x2)/2+1 - sf.StrSize(name)/2+1 ,(y1+y2)/2-7, name);
}
void PutCommand2(int x1,int y1,int x2,int y2,char *name){
 dotcolor=CuSc+1; boxfill(x1,y1,x2,y2);
 dotcolor=CuSc+2; boxfill(x2,y1,x2,y2);boxfill(x1,y2,x2,y2);
 dotcolor=CuSc; boxfill(x1,y1,x2-1,y1);boxfill(x1,y1,x1,y2-1);
 dotcolor=240; boxfill(x1+1,y1+1,x2-2,y1+1);boxfill(x1+1,y1+1,x1+1,y2-2);
 sf.FontSize=1;
 sf.TypeStr((x1+x2)/2+1 - sf.StrSize(name)/2+1 ,(y1+y2)/2-7, name);
}
void PushCommand2(int x1,int y1,int x2,int y2,char *name){
 boxfill(x1+2,y1+2,x2-2,y2-2);
 sf.FontSize=1;
 dotcolor=240;sf.TypeStr((x1+x2)/2+1 - sf.StrSize(name)/2+1 ,(y1+y2)/2-7, name);
}
int ProcessCommand(int x1,int y1,int x2,int y2,char *name){
 int rv=0,vv=0;
 GetMouse();
 if(!ismousein(x1,y1,x2,y2))return 0;
 do{
 GetMouse();
 Mouser();
 if(mbutts==1){
  if(!vv&&ismousein(x1,y1,x2,y2)){
   vv=1;
   RemoveMouse();
   PushCommand(x1,y1,x2,y2,name);
   ShowMouse();
   rv=1;
   }
  if(vv&&!ismousein(x1,y1,x2,y2)){
   vv=0;
   RemoveMouse();
   PutCommand(x1,y1,x2,y2,name);
   ShowMouse();
   rv=0;
   }
  }
 }while(mbutts==1);
 if(vv){
  RemoveMouse();
  PutCommand(x1,y1,x2,y2,name);
  ShowMouse();
  }
 return rv;
}
void Message(char *title,char *msg){
 static char s_ok[10]="OK";
 Image im ;
 int x1,x2 ;//y1=200,y2=290;
 int sz1, sz2 ; sz1 = bf.StrSize ( title ); sz2 = sf.StrSize ( msg );
 int sz; sz=max(sz1,sz2)/2;
 x1 = 320 - sz - 20 ;  x2 = 320 + sz + 20 ;
 im.GetImage(x1,190,x2,292);
 CuSc=253;
 PutCommand(x1,190,x2,290,"");
 dotcolor=244; bf.TypeStr(320-sz1/2,194,title);
 dotcolor=241; sf.TypeStr(320-sz2/2,227,msg);
 PutCommand(280,255,360,280,s_ok);
 ShowMouse();
 while(1){
  GetKey();
  GetMouse();
  Mouser();
  if(key1==13)break;
  if(ProcessCommand(280,255,360,280,s_ok))break;
  }
 RemoveMouse();
 im.PutImage(x1,190);
 im.Disturbe();
}
void GetName(int xsize,int mc,char *title,char *str,int l){
 Image im ;
 int x1,x2 ;//y1=200,y2=280;
 int sz1, sz2 ; sz1=bf.StrSize(title);sz2=xsize;
 int sz; sz=max(sz1,sz2)/2;
 x1 = 320 - sz - 20 ;  x2 = 320 + sz + 20 ;
 im.GetImage (x1, 200, x2, 281);
 CuSc = 253;
 PutCommand (x1, 200, x2, 280, "");
 dotcolor=242; bf.TypeStr (320-sz1/2, 205, title);
 PutCommand2 (x1+15, 240, x2-15, 268, "");
 dotcolor=241; if(!l)sf.GetStr (320-(sz2 / 2), 247, str, mc, xsize, CuSc+1);else sf.GetFars (320+(sz2 / 2), 247, str, mc, xsize, CuSc+1);
 im.PutImage (x1,200);
 im.Disturbe ();
}
int GetOK(char *title,char *msg){
 int rv;
 static char s_yes[4]="Yes",s_no[4]="No";
 Image im ;
 int x1,x2 ;//y1=200,y2=290;
 int sz1, sz2 ; sz1 = bf.StrSize ( title ); sz2 = sf.StrSize ( msg );
 int sz; sz=max(sz1,sz2)/2;
 x1 = 320 - sz - 20 ;  x2 = 320 + sz + 20 ;
 im.GetImage(x1,190,x2,291);
 CuSc=253;
 PutCommand(x1,190,x2,290,"");
 dotcolor=244; bf.TypeStr(320-sz1/2,194,title);
 dotcolor=241; sf.TypeStr(320-sz2/2,227,msg);
 PutCommand(240,255,310,280,s_yes);
 PutCommand(330,255,400,280,s_no);
 ShowMouse();
 while(1){
  GetKey();
  GetMouse();
  Mouser();
  if(key1==13)break;
  if(ProcessCommand(240,255,310,280,s_yes)){rv=1;break;}
  if(ProcessCommand(330,255,400,280,s_no)){rv=0;break;}
  }
 RemoveMouse();
 im.PutImage(x1,190);
 im.Disturbe();
 return rv;
}
