#include <iostream>
#include <cstring>
#include <string>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"

#define ROW 9
#define COL 9

using namespace std;

int main()
{
    int x, y, sel = 0;


    int overflag, resetflag = 1;
    Utility Util;
    InputSystem input;

    while (resetflag)
    {
        overflag = 0;
        Util.MineDeploy();

        while (!overflag)
        {
            Borland::GotoXY(0, 0);
            
            Util.DrawMap();
            input.readEveryFrame();
           
            
            if (input.getMouseButtonDown(0))
            {
                auto mousePos = input.getMousePosition();
                Borland::GotoXY(0, 28);
                printf("mouse position [%03d, %03d]\n", mousePos.x, mousePos.y);
                Util.OpenField(mousePos.y, mousePos.x);
            }
            //switch (sel)
            //{
            //case 1:       //open
            //    
            //    break;
            //case 2:        //flag
            //    Util.Flag(x - 1, y - 1);
            //    break;
            //case 3:        //reset
            //    Util.GameOver(0);
            //    break;
            //default:    //input error
            //    cout << "[잘못 입력하였습니다. 다시 입력하세요.]" << endl;
            //    break;
            //}
        }
    }
    return 0;
}
