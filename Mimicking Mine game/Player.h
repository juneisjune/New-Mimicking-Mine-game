#pragma once
#include <conio.h>
#include "GameObject.h"
#include"Flag.h"


class Player : public GameObject
{
public:
	Player(int x, int y, Screen& screen) : GameObject('>', x, y, screen) {}

	void processInput()
	{
		int key;
		int minor;

		if (!_kbhit()) return;

		Borland::GotoXY(0, 21);
		key = _getch();

		Borland::GotoXY(1, 23);
		printf("player key is %c   %x %d\n", key, key, key);

		Position pos = getPos();

		switch (key) {
		case 224:
			minor = _getch();
			printf("player minor key is %c   %x %d\n", minor, minor, minor);
			switch (minor) {
			case 'a':
				pos.x--;
				break;
			case 'd':
				pos.x++;
				break;
			case 'w':
				pos.y++;
				break;
			case 's':
				pos.y--;
				break;
			}
			break;
		case 'w':
			pos.y--;
			break;
		case 'a':
			pos.x--;
			break;
		case 's':
			pos.y++;
			break;
		case 'd':
			pos.x++;
			break;
		case'p':
			setFlagPos(pos);
			

		}

		setPos(pos);

	}

	void update() override
	{
		processInput();
	}


};

