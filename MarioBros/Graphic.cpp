#include "Graphic.h"

Graphic::Graphic(HWND hWnd,int W,int H){
	this->hWnd = hWnd;
	this->Width = W;
	this->Height = H;
	this->d3d = NULL;
	this->d3ddev = NULL;
	this->d3dxSprite = NULL;	
}
bool Graphic::InitD3D()
{
	
	this->d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if(!this->d3d)
		return false;
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp,sizeof(d3dpp));
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferWidth = this->Width;
	d3dpp.BackBufferHeight = this->Height;
	d3dpp.hDeviceWindow = this->hWnd;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = true;
	HRESULT hr = this->d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		this->hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&this->d3ddev);
	if(FAILED(hr))
	{		
		return false;
	}
	hr = D3DXCreateSprite(this->d3ddev,&this->d3dxSprite);
	if(FAILED(hr))
		return false;	
	return true;
}

void Graphic::Begin()
{
	//9290FD
	d3ddev->Clear(1,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(92,90,164),1,NULL);
	d3ddev->BeginScene();
	d3dxSprite->Begin(D3DXSPRITE_ALPHABLEND);
}
void Graphic::End()
{
	d3dxSprite->End();
	d3ddev->EndScene();
	d3ddev->Present(NULL,NULL,NULL,NULL);
}
void Graphic::DrawTexture(LPDIRECT3DTEXTURE9 texture,D3DXVECTOR3 position,D3DCOLOR color,bool isDrawnOnCam)
{
	if(isDrawnOnCam)
		d3dxSprite->Draw(texture,
					NULL,
					NULL,
					&Camera::GetInstance()->GetPosInViewPort(position.x,position.y),
					color
					);
	else
		d3dxSprite->Draw(texture,
					NULL,
					NULL,
					&D3DXVECTOR3(position.x,position.y,0),
					color);

}


void Graphic::DrawTexture(LPDIRECT3DTEXTURE9 texture,RECT* src, D3DXVECTOR3 position,D3DCOLOR color,bool isDrawnOnCam)
{
	if(isDrawnOnCam)
		d3dxSprite->Draw(texture,
					src,
					NULL,
					&Camera::GetInstance()->GetPosInViewPort(position.x,position.y),
					color
					);
	else
		d3dxSprite->Draw(texture,
					src,
					NULL,
					&D3DXVECTOR3(position.x,position.y,0),
					color);
}
/*
void Graphic::DrawTexture(LPDIRECT3DTEXTURE9 texture,RECT* src, D3DXVECTOR3 position,D3DCOLOR color,D3DXVECTOR2 center = D3DXVECTOR2(0,0),float angle=0,SPRITE_EFFECT effect= NONE )
{
	
}*/
	
LPDIRECT3DDEVICE9 Graphic::GetDevice()
{
	return this->d3ddev;
}
Graphic::~Graphic(void)
{
}
