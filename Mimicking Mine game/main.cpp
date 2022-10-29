#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "InputSystem.h"

//4428

using namespace std;

int main()
{
	Screen screen(20, 81);
	InputSystem input;

	Player player{ 2, 4, screen, input };
	

	while (1)
	{
		screen.clear();
		input.readEveryFrame();

		player.draw();


		screen.render();

		player.update();
		
	}

	return 0;
}