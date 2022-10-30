#include<time.h>
#include "Screen.h"

#define ROW 9
#define COL 9

using namespace std;





void Utility::DrawMap()
{
    int i = 0, j = 0;
    for (i = 0; i < ROW; i++)
    {
       
        for (j = 0; j < COL; j++)
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
void Utility::MineDeploy()
{
    Utility Util;
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
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            arr[(rh[i])][(rv[i])] = '*';
        }
        totalmine++;
    }
    arr[rand() % 9][rand() % 9] = '*';
    totalmine++;

    Util.CopyField();
}
void Utility::CopyField()
{
    //from arr to MineField
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            MineField[i][j] = arr[i][j];
}
void Utility::Init()
{
    system("cls");
    system("color 0f");
    start = clock();
    totalmine = 0;
    getmine = 0;

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            arr[i][j] = 0;
    overflag = 1;
}
void Utility::GameOver(int code)
{
    Utility Util;

    int sel;

    switch (code)
    {
    case 1:
        finish = clock();

        system("cls");
        system("color cf");
        cout << "\n\t[지뢰를 밟아서 사망하셨습니다.]\n" << endl;
        CalcTime();
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
        break;
    case 0:
        cout << "[게임을 다시 시작합니다...]" << endl;
        Sleep(500);
        Util.Init();
        break;
    }
}
int Utility::CalcMine(int x, int y)
{
    int n_mine = 0;

    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i <= 9 && j >= 0 && j <= 9 && arr[i][j] == '*')
                n_mine++;

    return n_mine;
}
void Utility::OpenField(int x, int y)
{
    Utility Util;

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
        cout << "[이미 탐색한 지역입니다.]" << endl;
        Util.CheckWin();
    }
    //else...
    else
    {
        arr[x][y] = Util.CalcMine(x, y);
        if (arr[x][y] == 0)
            arr[x][y] = 'n';
        cout << "[처리 중...]" << endl;
        Util.CheckWin();
    }
}
void Utility::Flag(int x, int y)
{
    Utility Util;

    //already flag
    if (arr[x][y] == 'P')
    {
        arr[x][y] = MineField[x][y];
        getmine--;
        cout << "[처리 중...]" << endl;
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
        cout << "[처리 중...]" << endl;
    }
    Util.CheckWin();
}
void Utility::CalcTime()
{
    runtime = finish - start;
    cout << "\t[플레이 시간 : " << runtime / CLOCKS_PER_SEC << "초]\n" << endl;
}
void Utility::CheckWin()
{
    Utility Util;
    int matchcount = 0;
    int zerofield = 0;
    int sel;

    //is all field visited?
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (arr[i][j] == 0)
                zerofield++;
        }
    }
    //found every mine?
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            if (arr[i][j] == 'P' && MineField[i][j] == '*')
                matchcount++;

    //condition true
    if (matchcount == totalmine || zerofield == 0)
    {
        finish = clock();
        system("color 2a");
        system("cls");
        printf("\n\t[지뢰밭을 무사히 돌파하였습니다!]\n\n");
        Util.CalcTime();
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

