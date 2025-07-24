#ifndef GAME_H
#define GAME_H
#include <Windows.h>
#include "Utils.h"
#include "Contents.h"
#include "Graphic.h"
#include "Mario.h"
#include "Monster.h"
#include "Stage.h"
#include "Turtle.h"
#include "Brick.h"
#include "Turtle1.h"
#include"Mushroom.h"

class Game
{
private:
	HINSTANCE hInstance;
	int Width;
	int Height;
	HWND hWnd;
	char winName[256];
	static HRESULT CALLBACK WndProc(HWND hWWnd,UINT message,WPARAM wParam,LPARAM lParam);
	Contents* content;
	Graphic* graphic;
	KeyBoard* keyboard;
	BaseObject* mario;
	BaseObject* gomba;
	BaseObject* cong;
	BaseObject* virObjects;
	BaseObject* turtle;
	BaseObject* brick;
	BaseObject* turtle1;
	BaseObject *mushroom;
	int length;
	
public:
	Game(HINSTANCE hInstance,int Width,int Height,char* winName);
	bool InitWindow();
	void Init();
	void Load();
	void Update(DWORD);
	void Draw(DWORD);
	~Game(void);
};

#endif