#pragma once
#include "Screen.h"
#include <conio.h>
#include "GameObject.h"

class Flag : public GameObject
{


public:
	Flag(int x, int y, Screen& screen) : GameObject('P', x, y, screen) {}
	


};

