#include <stdio.h>
#include <Windows.h>  

#define Black		0
#define DarkBlue	1
#define DarkGreen	2
#define DarkCyan	3
#define DarkRed		4
#define DarkMagenta	5
#define DarkYellow	6
#define Gray		7
#define DarkGray	8
#define Blue		9
#define Green		10
#define Cyan		11
#define Red			12
#define Magenta		13
#define Yellow		14
#define White		15


struct Obj
{
	int x;
	int y;
	const char* shape;
};

void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void ChangeColor(int color)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	Obj player;
	player.x = 10;
	player.y = 10;
	player.shape = "¿Ê";

	HideCursor();

	while (true)
	{
		system("cls");

		if (GetAsyncKeyState(VK_LEFT))
		{
			player.x--;
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			player.x++;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			player.y--;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			player.y++;
		}

		SetPosition(player.x, player.y);
		ChangeColor(Yellow);
		printf(player.shape);


		Sleep(20);

	}
	return 0;
}