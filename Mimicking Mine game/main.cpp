#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	Screen screen(13, 13); // 게임  공간이 10 10 첫번째가 y축 두번째가 x축

	Player player{ 2, 4, screen };
	Flag flag{ 0,-1,screen };

	//Enemy enemy1{ rand() % 10, rand() % 10, screen };

	while (1)
	{
		//screen.clear();
		// 
		// 
		//screen.draw(enemy1.getPos(), enemy1.getShape());
		screen.render();
		screen.draw(player.getPos(), player.getShape());
		//screen.flagDraw(flag.getPos(), flag.getShape());
	

		player.update();
		//enemy1.update();
	}

	return 0;
}