#include<time.h>
#include "Screen.h"
#define n_rows 9
#define n_cols 9
using namespace std;


void Screen::DrawMap()
{
 
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            if (arr[i][j] == '*')                //지뢰이면
                cout << "-";
            //cout << " X "; //for debug:shows mine :)
            else if (arr[i][j] == 'P')
                cout << "P";
            else if (arr[i][j] == 'n')            //빈칸이면
                cout << "N";
            else if (arr[i][j] == 0)
                cout << "-";
            else
                cout << " " << arr[i][j] << " ";
        }
        cout << "\n";
    }
   
}
void Screen::settingMine()
{
    Screen screen;
    int rh[10], rv[10];

    srand((unsigned)time(NULL));

    //calculate random coordinate
    for (int i = 0; i < 10; i++)
    {
        rh[i] = i;

        rv[i] = rand() % 9;
        if (rv[i] == 9)
            rv[i]--;
    }
    //deploying mine
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            arr[(rh[i])][(rv[i])] = '*';
        }
        totalmine++;
    }
    arr[rand() % 9][rand() % 9] = '*';
    totalmine++;

    screen.Copy();
}
void Screen::Copy()
{
    //from arr to MineField
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            MineField[i][j] = arr[i][j];
            cout << arr[i][j];
        }
        cout << endl;
    }
}
void Screen::Init()
{
    system("cls");
   
    totalmine = 0;
    getmine = 0;

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            arr[i][j] = 0;
        } 
    }
    overflag = 1;
}
void Screen::GameOver(int code)
{
    Screen Util;

    int sel;

    switch (code)
    {
    case 1:

        Borland::GotoXY(30, 15);
        cout << "\n\t[You lose ]\n" << endl;
 
  
    }
}
int Screen::CalcMine(int x, int y)
{
    int n_mine = 0;

    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i >= 0 && i <= 9 && j >= 0 && j <= 9 && arr[i][j] == '*')
                n_mine++;
        }
    }
    return n_mine;
}
void Screen::Open(int x, int y)
{
    Screen Util;

    //open mine
    if (MineField[x][y] == '*' && arr[x][y] != 'P')
    {
        Util.GameOver(1);
    }
    //try to open flagged
    else if (arr[x][y] == 'P')
    {
        cout << "[깃발을 설치한 지점은 열 수 없습니다. 열려면 우선 깃발을 해제하세요.]" << endl;
        Util.CheckWin();
    }
    //already open
    else if (arr[x][y] != 0)
    {
        //cout << "[이미 탐색한 지역입니다.]" << endl;
        Util.CheckWin();
    }
    //else...
    else
    {
        arr[x][y] = Util.CalcMine(x, y);
        if (arr[x][y] == 0)
            arr[x][y] = 'n';
        //cout << "[처리 중...]" << endl;
        Util.CheckWin();
    }
}
void Screen::Flag(int x, int y)
{
    Screen Util;

    //already flag
    if (arr[x][y] == 'P')
    {
        arr[x][y] = MineField[x][y];
        getmine--;
     
    }
    //already open
    else if (arr[x][y] == 'n' || arr[x][y] > 0 && arr[x][y] < 9)
    {
        cout << "[열어본 지점에 깃발을 설치할 수 없습니다.]" << endl;
    }
    //flag!
    else
    {
        arr[x][y] = 'P';
        getmine++;
      
    }
    Util.CheckWin();
}

void Screen::CheckWin()
{
    Screen Util;
    int matchcount = 0;
    int zerofield = 0;
    int sel;

    //is all field visited?
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            if (arr[i][j] == 0)
                zerofield++;
        }
    }
    //found every mine?
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            if (arr[i][j] == 'P' && MineField[i][j] == '*')
                matchcount++;
        }
    }
    //condition true
    if (matchcount == totalmine || zerofield == 0)
    {
       
        Borland::GotoXY(15, 15);
        printf("\n\t[You Win!]\n\n");
     
        cout << "게임을 다시 시작하시려면 1을 입력하세요. 이외의 키를 입력시 종료됩니다. : ";
        cin >> sel;
        switch (sel)
        {
        case 1:
            system("cls");
            Util.Init();
            break;
        default:
            exit(1);
        }
    }
}

