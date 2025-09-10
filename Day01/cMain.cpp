#include <stdio.h>
#include <Windows.h>  


#pragma region Enum
enum Color
{
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkMagenta,
	DarkYellow,
	Gray,
	DarkGray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White,
};
#pragma endregion
#pragma region Struct
struct Obj
{
	int x;
	int y;
	Color color;
	const char* shape;
};
#pragma endregion
#pragma region WINAPI
void SetPosition(int x, int y);
void HideCursor();
void ChangeColor(Color color);
#pragma endregion


#pragma region GAME
Obj* player = nullptr; //24byte -> 8byte

void Init();
void Update();
void Release();

#pragma endregion

int main()
{

	HideCursor();
	Init();

	while (true)
	{
		system("cls");

		Update();


		Sleep(20);

	}

	Release();
	return 0;
}

#pragma region GAME
void Init()
{
	player = (Obj*)malloc(sizeof(Obj));
	player->x = 10;
	player->y = 10;
	player->color = Yellow;
	player->shape = "¿Ê";

}
void Update()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		player->x--;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		player->x++;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		player->y--;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		player->y++;
	}

	SetPosition(player->x, player->y);
	ChangeColor(player->color);
	printf(player->shape);
}
void Release()
{
	if (player != nullptr)
	{
		free(player);
		player = nullptr;
	}
}
#pragma endregion


#pragma region WINAPI

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

void ChangeColor(Color color)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#pragma endregion


