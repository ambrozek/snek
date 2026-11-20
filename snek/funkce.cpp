
#include "funkce.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

bool GameOver;
const int width = 40;
const int height = 20;
int score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

struct Point {
	int x;
	int y;
};

Point food;
Point head;
std::vector<Point> snake;

void Setup()
{
	GameOver = false;
	dir = STOP;
	head.x = width / 2;
	head.y = height / 2;
	snake.push_back(head);
	food.x = rand() % width;
	food.y = rand() % height;
	dir = STOP;
	score = 0;
}


void Draw(){
	
	for (int r = 0; r < height; r++)
	{
		for (int k = 0; k < width; k++)
		{
			if (r == 0 || r == height - 1 || k == 0 || k == width - 1) {
				cout << "#";
			}
			else if (k == food.x && r == food.y) {
				cout << "@";
			}
			else if (k == snake[0].x && r == snake[0].y) {
				cout << "e";
			}
			else {
				cout << ' ';
			}     //Constructs grid with freespace
		}
		cout << endl;
	}
}

void Input() {

	if (_kbhit()) {
		int ch = _getch();

		if (ch == 224) {
			int arrow = _getch();

			switch (arrow) {
			case 72:
				dir = UP;
				break;
			case 80:
				dir = DOWN;
				break;
			case 75:
				dir = LEFT;
				break;
			case 77:
				dir = RIGHT;
				break;
			}
		}
	}

}

void Logic() {

	switch (dir) {
	case UP:
		snake[0].x = snake[0].x;
		snake[0].y = snake[0].y - 1;
		break;
	case DOWN:
		snake[0].x = snake[0].x;
		snake[0].y = snake[0].y + 1;
		break;
	case LEFT:
		snake[0].x = snake[0].x - 2;
		snake[0].y = snake[0].y;
		break;
	case RIGHT:
		snake[0].x = snake[0].x + 2;
		snake[0].y = snake[0].y;
		break;
	}

}