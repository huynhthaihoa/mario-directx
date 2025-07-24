#ifndef GRAPHIC_H
#define GRAPHIC_H
#include "Utils.h"
class Graphic
{
private:
	//doi tuong direct x
	LPDIRECT3D9 d3d;
	//thiet bi ve
	LPDIRECT3DDEVICE9 d3ddev;
	//Ve texture
	LPD3DXSPRITE d3dxSprite;
	//ve text
	
	//hwnd cua cua so ve
	HWND hWnd;
	int Width;
	int Height;
public:
	bool InitD3D();
	Graphic(HWND,int,int);
	~Graphic();
	void Begin();
	void End();
	void DrawTexture(LPDIRECT3DTEXTURE9 texture,D3DXVECTOR3 position,D3DCOLOR color,bool isDrawnOnCam=true);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture,RECT* src, D3DXVECTOR3 position,D3DCOLOR color,bool isDrawnOnCam=true);
	//void DrawTexture(LPDIRECT3DTEXTURE9 texture,RECT* src, D3DXVECTOR3 position,D3DCOLOR color,D3DXVECTOR2 center = D3DXVECTOR2(0,0),float angle=0,SPRITE_EFFECT effect= NONE );
	void DrawString(char* str);
	void DrawSurface();
	LPDIRECT3DDEVICE9 GetDevice();	
};

#endif
/*Cuong's dialog
*	16/11/2015 - DrawTexture() them tham so bool isDrawnOnCam = true
*		       
*/