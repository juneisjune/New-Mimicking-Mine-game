#pragma once
#include <conio.h>
#include "GameObject.h"

class Player :
	public GameObject
{

	auto processInput()
	{
		auto pos = getPos();
		if (input.getKeyDown(0x57)) {
			pos.y--;
		}
		else if (input.getKeyDown(0x41)) {
			pos.x--;
		}
		else if (input.getKeyDown(0x53)) {
			pos.y++;
		}
		else if (input.getKeyDown(0x44)) {
			pos.x++;
		}
		setPos(pos);
	}

public:
	Player(int x, int y, Screen& screen, InputSystem& input)
		: GameObject('>', x, y, screen, input)
	{}


	void update() override
	{
		processInput();
	}

	void draw() override
	{
		GameObject::draw();
		//screen.draw(getPos() + Position{ 0, -1 }, 'P');
	}


};

