#pragma once
#include <iostream>
#include <Windows.h>
#include "Utils.h"

using namespace std;

class Screen
{
	char* lines;
	int n_rows;
	int n_cols;
	int countOfFlag;
	char* flag;

	int pos2offset(int x, int y, int n_cols) const
	{
		return y * n_cols + x;
	}

public:
	Screen(int n_rows, int n_cols)
		: n_rows(n_rows), n_cols(n_cols), lines(new char[n_rows * n_cols + 1]) , countOfFlag(0), flag(new char[30])
	{
		Borland::Initialize();
		clear();
	}

	virtual ~Screen() { delete[] lines; }

	void clear()
	{
		memset(lines, ' ', sizeof(char) * (n_rows * n_cols));
	}
	void flagDraw(const Position& pos, char shape)
	{
		int i = 0;
		countOfFlag++;
		flag[i] = pos2offset(pos.x, pos.y, n_cols);
		int offset = flag[i];
		lines[offset] = 'P';
		i++;
	}
	

	void draw(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);
		lines[offset] = shape; //플레이어 움직임

		printf("%s\n", lines);
		printf("If you want to Open press 'o' and if you want to put your flag press 'p'\n");

		Sleep(100);
	}

	void render()
	{
		Borland::GotoXY(0, 0);
		int firstLine = 0;
		while (firstLine < 12) // 1th line of map
		{
			lines[firstLine] = '=';
			firstLine++;
		}

		for (int i = 1; i < n_rows - 2; i++)
		{
			int spaceOfPlaying = 2;
			lines[i * n_rows] = '\n';
			lines[i * n_rows + 1] = ']';
			while (spaceOfPlaying < 12)
			{
				lines[i * n_rows + spaceOfPlaying] = '~';
				spaceOfPlaying++;
			}
			lines[i * n_rows + 12] = '[';
			if (i == 10)
			{
				int lastLine = 0;
				while (lastLine < 12) // this is lines line of map
				{
					lines[i * n_rows] = '\n';
					lines[i * n_rows + lastLine + 1] = '='; // 13th line of map
					lastLine++;
				}
			}
		}
		lines[n_rows * n_cols] = '\0';


	}



	bool checkValidPos(const Position& pos) const
	{
		return (pos.x >= 2 && pos.x < n_cols - 1 //pos.x<c_cols 는 오른쪽 벽면 막기
			&& pos.y >= 1 && pos.y < n_rows - 3);
	}
};

