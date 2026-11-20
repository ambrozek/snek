// snek.cpp : Defines the entry point for the application.
//

#include "snek.h"
#include "funkce.h"
#include "Windows.h"

using namespace std;

int main()
{
	bool gameOver = false;

	Setup();

	while (!gameOver) {
		Input();
		Logic();
		system("cls");
		Draw();
		Sleep(120);
	}
	return 0;
}
