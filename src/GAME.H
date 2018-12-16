//-----------------------*( in the name of GOD )*-------------------
// By Hossein Taheri
// Copyright 1998                                                   
//------------------------------------------------------------------

//           This file contains ... game subrotines
#include "PUBLIC.H"
#define MAXHOMES 100
#define SavedGames "PLAYERS.DAT"
#define GameShapes "SHAPES.POL"

struct Players {
 int  howg;            // how many filled plays..
 char name[34];        // Player name..
 char games[20];       // Which games he fill..
 long totaltime;       // Times he or she used.. (per second)
};

extern float ob[][14];
extern float bo[][28];
extern int sss[];
extern BitFont bf,sf;
extern int homecolor[],homebests[][2];
extern float homesizes[];
extern segcmds[][6];
extern char basecolor[];
extern int Finish;

inline int ismousein(int x1,int y1,int x2,int y2){
 if(x1<=mox && x2>=mox && y1<=moy && y2>=moy)return 1;
 return 0;
 }

void PutCommand(int x1,int y1,int x2,int y2,char *name);
void PushCommand(int x1,int y1,int x2,int y2,char *name);
void PutCommand2(int x1,int y1,int x2,int y2,char *name);
void PushCommand2(int x1,int y1,int x2,int y2,char *name);
int ProcessCommand(int x1,int y1,int x2,int y2,char *name);

class Home {
 public:
  int  orgx,orgy;
  int  BestX,BestY;
  int  bkcolor,brc;
  int  hs,fpx,fpy;
  int  *ps;
  float size;
  int  CenX(),CenY();
  void InitHome(int  num,int colr);
  void FitSize(int x,int y);
  void SetCurBack(int d){brc=d;}
  void Remove();
  void MoveHome(int x,int y);
  void ChangeColor(int newcol);
  void ShowHome();
  int  ChkFill();
  void ResizeHome(float nsz);
};

class Game {
 private:
  Home home;
  long  starttime,endtime;
  Poly  Cards[7];
  int   droped[7];
  int   noh;
  int   curhom;
  int   cc,ccxs,ccys;
  float stp;
  int   drpc,udrpc,padcol,drpds;
  int   gire[7][4];
  int   completed;
  int   GameMode,Langauge,MouSpd;
  Image gb,bg,bb,sb,cd;
 public:
  struct Players curplayer;
  int  PlayerNamed,HowManyPlayers,PlayerNumber;
  int  InitialGame();
  void GameFree();
  int  HighScoresShow();
  void GetPlayerName();
  void AddHome(float *u);
  void GotoSelecting();
  int  CheckFill();
  void Display_Board();
  void GamePad();
  void StartGame();
  void EndGame();
  void DragDrop();
  void TimeUsed(int& m,int& s);
  void ShowTime();
  void ProcessKey();
  void ProcessMouse();
  void Thriumph();
  void Scoring();
  void GamePause();
  void Help();
  void RemoveCard(),PutCard(),ProcessCard();
  void Completed();
};
void Message(char *title,char *msg);
void GetName(int xsize,int mc,char *title,char *str,int l);
int  GetOK(char *title,char *msg);
