#include <iostream>
#include <cstring>
#include <string>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"
using namespace std;

int main()
{
    int over, reset = 1;
    Screen screen;
    InputSystem input;

    while (reset)
    {
        over = 0;
        screen.settingMine();

        while (!over)
        {
            Borland::GotoXY(0, 0);
            
            screen.DrawMap();
            input.readEveryFrame();
           
            
            if (input.getMouseButtonDown(0)) //when input left mouse button
            {
                auto mousePos = input.getMousePosition();
                Borland::GotoXY(0, 15);
                printf("mouse position [%03d, %03d]\n", mousePos.x, mousePos.y);
                if (mousePos.y < 1 || mousePos.y>9 || mousePos.x < 1 || mousePos.x>9)
                {
                    Borland::GotoXY(0, 14);
                    printf("You input wrong place do it again\n");
                    Sleep(500);
                    system("cls");
                    break;
                }
                screen.Open(mousePos.y, mousePos.x);
            }
            if (input.getMouseButtonDown(1)) //when input right mouse button
            {
                auto mousePos = input.getMousePosition();
                Borland::GotoXY(0, 15);
                printf("mouse position [%03d, %03d]\n", mousePos.x, mousePos.y);
                if (mousePos.y < 1 || mousePos.y>9 || mousePos.x < 1 || mousePos.x>9)
                {
                    Borland::GotoXY(0, 14);
                    printf("You input wrong place do it again\n");
                    Sleep(500);
                    system("cls");
                    break;
                }
                screen.Flag(mousePos.y, mousePos.x);
            }
            //switch (input.)
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
