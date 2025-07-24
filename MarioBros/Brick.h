#ifndef BRICK_H
#define BRICK_H
#include "BaseObject.h"
#include "Utils.h"

class Brick : public BaseObject
{
private:
	int index ;
	LPDIRECT3DTEXTURE9 img1;
	LPDIRECT3DTEXTURE9 img2;
    LPDIRECT3DTEXTURE9 img3;
	LPDIRECT3DTEXTURE9 img4;
    LPDIRECT3DTEXTURE9 img5;
	D3DXVECTOR3 p2;
	D3DXVECTOR3 p3;
	D3DXVECTOR3 p4;
	D3DXVECTOR3 p5;
	D3DXVECTOR3 speed1;
	D3DXVECTOR3 speed2;
public:
	
	Brick(void);
	void Init();
	void Load(Contents*);
	void Update(KeyBoard*,DWORD);
	void Draw(Graphic*);
	void OnCollisionWith(BaseObject* obj);
	~Brick(void);
};

#endif