#ifndef QBOXMUSHROOM_H
#define QBOXMUSHROOM_H
#include "BaseObject.h"
class QBoxMushroom : public BaseObject
{
private:
	int index ;
	int count;
	LPDIRECT3DTEXTURE9 img2;
	D3DXVECTOR3 speed2;
public:
	QBoxMushroom(void);
    void Init();
	void Load(Contents*);
	void Update(KeyBoard*,DWORD);
	void Draw(Graphic*);
	void OnCollisionWith(BaseObject* obj);
	~QBoxMushroom(void);
};
#endif