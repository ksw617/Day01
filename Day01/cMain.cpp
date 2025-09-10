#include <stdio.h>
#include <Windows.h>  

struct Obj
{
	int x;
	int y;
	const char* shape;
};

void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	Obj player;
	player.x = 10;
	player.y = 10;
	player.shape = "¿Ê";

	Obj enemy;
	enemy.x = 20;
	enemy.y = 20;
	enemy.shape = "º¿";

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


		SetPosition(player.x, player.y);
		printf(player.shape);

		SetPosition(enemy.x , enemy.y);
		printf(enemy.shape);

		Sleep(20);	  

	}
	return 0;
}