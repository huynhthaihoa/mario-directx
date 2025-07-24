#include "Contents.h"


Contents::Contents(LPDIRECT3DDEVICE9 d3ddv){
	this->d3ddv = d3ddv;

}

LPDIRECT3DTEXTURE9 Contents::LoadTexture(string filePath){
	LPDIRECT3DTEXTURE9 texture = NULL;
	D3DXIMAGE_INFO info;
	HRESULT hr;
	ZeroMemory(&info,sizeof(info));
	hr = D3DXGetImageInfoFromFile(filePath.c_str(),&info); 
	if(hr != D3D_OK)
		return NULL;
	hr = D3DXCreateTextureFromFileEx(this->d3ddv,
		filePath.c_str(),
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255,255,255),
		&info,
		NULL,&texture);

	if(hr != D3D_OK)
		return 0;
	return texture;
}

LPDIRECT3DSURFACE9 Contents::LoadSurface(string filePath){
	LPDIRECT3DSURFACE9 surface = NULL;
	D3DXIMAGE_INFO info;
	HRESULT hr;
	ZeroMemory(&info,sizeof(info));
	hr = D3DXGetImageInfoFromFile(filePath.c_str(),&info); 
	if(hr != D3D_OK)
		return NULL;
	hr = this->d3ddv->CreateOffscreenPlainSurface(
		info.Width,
		info.Height,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		&surface,
		NULL);
	if(hr != D3D_OK)
		return 0;
	hr = D3DXLoadSurfaceFromFile(surface,NULL,NULL,filePath.c_str(),NULL,D3DX_DEFAULT,D3DCOLOR_XRGB(255,255,255),&info);
	if(hr != D3D_OK)
		return 0;
	return surface;
}

Contents::~Contents(void)
{
}
