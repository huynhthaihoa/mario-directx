#ifndef KEY_BOARD_H
#define KEY_BOARD_H
#include <dinput.h>
class KeyBoard
{
private:
	LPDIRECTINPUT8 di8;
	LPDIRECTINPUTDEVICE8 did8;
	char key_buffer[256];
	HINSTANCE hInstance;
	HWND hWnd;
public:
	bool Init();
	KeyBoard(HINSTANCE hInstance,HWND hwnd);
	void GetState();
	bool IsKeyDown(int key);
	bool IsPreKeyDown(int key);
	KeyBoard(void);
	~KeyBoard(void);
};

#endif