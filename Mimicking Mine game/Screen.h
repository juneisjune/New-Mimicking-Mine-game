#pragma once
#include <iostream>
#include <Windows.h>

#include "Utils.h"

using namespace std;
#define ROW 9
#define COL 9

class Utility
{
private:
    int arr[ROW][COL]={0,};
    int MineField[ROW][COL]{ 0, };
    int totalmine = 80;
    int getmine = 0;
    int  flag = 1;
    int overflag=1;
    char UserName[50]="null";
    clock_t start, finish, runtime;

public:
     
   
    void MineDeploy();
    void DrawMap();
    void CopyField();
    void Init();
    void GameOver(int code);
    void CalcTime();
    void CheckWin();
    void Flag(int x, int y);
    void OpenField(int x, int y);
    int CalcMine(int x, int y);
};