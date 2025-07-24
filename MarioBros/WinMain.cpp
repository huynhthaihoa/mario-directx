#include <windows.h>
#include "Game.h"
#define FRAME_RATE 60
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
 LPTSTR lpCmdLine, int nCmdShow )
 {
	
	MSG msg;
	Game game(hInstance,800,600,"Mario Bros");
	if(!game.InitWindow())
		return 0;
	game.Init();
	game.Load();

	DWORD frame_start = GetTickCount();
	DWORD tick_per_frame = 1000 / FRAME_RATE;
	DWORD deltaTime =0;
	ZeroMemory(&msg,sizeof(msg));
	while( msg.message!=WM_QUIT )
	{
		// Kiểm tra các sự kiện được gửi tới trong hàng đợi của ứng dụng
		if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
		{
			TranslateMessage ( &msg );
			DispatchMessage ( &msg );
		}
		DWORD now = GetTickCount();
		deltaTime = now - frame_start;
		
		if(deltaTime >= tick_per_frame){
			frame_start = now;
			game.Update(deltaTime);
			game.Draw(deltaTime);
		}
		
	}
	return (int) msg.wParam;
 }

 