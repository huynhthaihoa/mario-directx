#include "Game.h"
Game::Game(HINSTANCE hInstance,int Width,int Height,char* winName)
{
	this->hInstance = hInstance;
	this->Width = Width;
	this->Height = Height;
	strcpy(this->winName,winName);
	virObjects = NULL;
	length = 0;
}
LRESULT CALLBACK Game::WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	if(message == WM_DESTROY)
	{
		PostQuitMessage(0);
	}
	return DefWindowProc(hWnd,message,wParam,lParam);
}

bool Game::InitWindow()
{
	//khoi tao cac doi tuong cua he thong
	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hIconSm = 0;
	wndclass.hIcon = 0;
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndclass.hInstance = this->hInstance;
	wndclass.lpfnWndProc = (WNDPROC)WndProc;
	wndclass.lpszClassName = "Game";
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClassEx(&wndclass))
	{
		return false;
	}
	this->hWnd = CreateWindow("Game",
		this->winName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		this->Width,
		this->Height,
		NULL,
		NULL,
		this->hInstance,
		NULL);
	if(!this->hWnd)
		return false;
	ShowWindow(this->hWnd,SW_NORMAL);
	UpdateWindow(this->hWnd);

	graphic = new Graphic(this->hWnd,Width,Height);

	if(!graphic->InitD3D())
		return false;	
	content = new Contents(graphic->GetDevice());
	

	return true;
}
void Game::Init(){
	//Khoi tao cac doi tuong o day nhe :D
	CGameTimeDx9::getInstance()->InitGameTime();
	keyboard = new KeyBoard(hInstance,hWnd);
	keyboard->Init();
	mario = new Mario();
	mario->Init();
	brick = new Brick();
	brick->Init();
	mushroom = new Mushroom(brick);
	mushroom->Init();
	Camera::GetInstance()->UpdateViewPort(0,600);
	Stage::GetInstance()->SetCurrentMap(LEVEL1);
	//int temp = Stage::GetInstance()->GetCurrentMap()->GetVirtualObjectList().size();
	virObjects  = Stage::GetInstance()->GetCurrentMap()->GetVirtualObjects(length);
	//Camera::GetInstance()->UpdateViewPort(20,600);
}
void Game::Load(){
	Stage::GetInstance()->Load(content);// load tileset.png
	mario->Load(content);
	brick->Load(content);
	mushroom->Load(content);
}
Game::~Game(void)
{
}
void Game::Update(DWORD deltaTime){
	//update Game Time
	CGameTimeDx9::getInstance()->UpdateGameTime();
	//lay trang thai ban phim
	keyboard->GetState();
	//update cac baseObj o day

	mario->Update(keyboard,deltaTime);
    brick->Update(keyboard,deltaTime);
	mushroom->Update(keyboard,deltaTime);
	mario->OnCollisionWith(brick);
	mushroom->OnCollisionWith(mario);
	//mario->OnCollisionWith(turtle1);
	
	
	


	////xu li va cham o day
	//if(BaseObject::AABBCheck(mario->GetSweptBroadPhaseBox(mario),gomba))
	//{//co kha nang xay ra va cham
	//	
	//	mario->OnCollisionWith(gomba);
	//}
	//else
	//{
	//	float x = mario->GetPosition().x + mario->GetSpeed().x;
	//	mario->SetPosition(D3DXVECTOR3(x,mario->GetPosition().y,0));
	//}
}
void Game::Draw(DWORD deltaTime){
	graphic->Begin();	
	Stage::GetInstance()->DrawMap(graphic);
	//**************************** TEST VIRTUAL OBJECT LIST ************************************************************
	// fucking bad performance :( because of list :(
	/*list<BaseObject> virObjList = Stage::GetInstance()->GetCurrentMap()->GetVirtualObjectList();
	graphic->DrawTexture(
		content->LoadTexture("./test.png"),
		&virObjList.begin()->GetBound(),
		virObjList.begin()->GetPosition(),
		D3DCOLOR_XRGB(255,255,255)
		);*/
	//*****************************TEST VIRTUAL OBJECTS***********************************************************
	/*for(int i=0;i<length;i*/
	/*graphic->DrawTexture(
		content->LoadTexture("./test.png"),
		&virObjects[4].GetBound(),
		virObjects[4].GetPosition(),
		D3DCOLOR_XRGB(255,255,255)
		);*/
	//graphic->DrawTexture(
		//content->LoadTexture("./test.png"),
		//&cong->GetBound(),
		//cong->GetPosition(),
		//D3DCOLOR_XRGB(255,255,255)
		//);
	//cong->Draw(graphic);
	//**********************************************************************************************************
	//Draw cac baseObj o day
	mario->Draw(graphic);
	//turtle->Draw(graphic);
	//turtle1->Draw(graphic);
    brick->Draw(graphic);
	mushroom->Draw(graphic);
	//gomba->Draw(graphic);
	graphic->End();
}