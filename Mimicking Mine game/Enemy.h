#pragma once
#include <conio.h>

#include "GameObject.h"
class Enemy : public GameObject
{
public:
    Enemy(int x, int y, Screen& screen) : GameObject('*', x, y, screen) {}

    void update() override
    {
        processInput();
    }

 

    void processInput()
    {
        int key;

        if (!_kbhit()) return;

        Borland::GotoXY(0, 21);
        key = _getch();

        Borland::GotoXY(1, 24);
        printf("enemy key is %c %x %d\n", key, key, key);

        Position pos = getPos();
     

        setPos(pos);

    }


};

