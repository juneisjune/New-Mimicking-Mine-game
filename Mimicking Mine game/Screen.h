#pragma once
#include <iostream>
#include <Windows.h>
#include "Utils.h"

using namespace std;
#define n_rows 9
#define n_cols 9

class Screen
{
private:
    int arr[n_rows][n_cols]={0,};
    int MineField[n_rows][n_cols]{ 0, };
    int totalmine = rand() %20;
    int getmine = 0;
    int  flag = 1;
    int overflag=1;
    char UserName[50]="null";
    clock_t start, finish, runtime;

public:
     
  
    void settingMine();
    void Copy();

    void DrawMap();
    void Init();
    
    void GameOver(int code);
    void CheckWin();
    void Flag(int x, int y);
    void Open(int x, int y);
    int CalcMine(int x, int y);
  
};