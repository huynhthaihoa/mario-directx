#include "KeyBoard.h"


KeyBoard::KeyBoard(HINSTANCE hIns,HWND hwnd)
{
	this->di8 = 0;
	this->did8 = 0;
	this->hInstance = hIns;
	this->hWnd = hwnd;
	//create 
}
bool KeyBoard::Init()
{
	HRESULT hr= DirectInput8Create(
		this->hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&this->di8,
		NULL);
	if(FAILED(hr))
		return false;
	hr = this->di8->CreateDevice(GUID_SysKeyboard,&this->did8,NULL);
	if(FAILED(hr))
		return false;
	hr = this->did8->SetDataFormat(&c_dfDIKeyboard);
	if(FAILED(hr))
		return false;
	hr = this->did8->SetCooperativeLevel(this->hWnd,DISCL_FOREGROUND| DISCL_NONEXCLUSIVE);
	if(FAILED(hr))
		return false;	
	hr = this->did8->Acquire();
	if(FAILED(hr))
		return false;
	return true;
}
void KeyBoard::GetState()
{
	HRESULT hr = this->did8->GetDeviceState(sizeof(this->key_buffer),(LPVOID)&this->key_buffer);
	if(FAILED(hr))
	{
		while (this->did8->Acquire() == DIERR_INPUTLOST);				
	}
}

bool KeyBoard::IsKeyDown(int Key)
{
	return key_buffer[Key] && 0x80;
}

KeyBoard::~KeyBoard(void)
{
}
