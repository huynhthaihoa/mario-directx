#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H
#include "Utils.h"

class BaseObject
{
protected:
	//int id;
	char* name;
	int width;
	int height;
	OBJECT_TYPE type;
	LPDIRECT3DTEXTURE9 img;
	RECT bound;
	D3DXVECTOR3 position;
	D3DXVECTOR3 speed;
	
	//int speed;
public:
	bool CreateMushroom;
	bool checkLR;
	bool checkT;
	bool checkB;
	bool isDie;
	BaseObject(void);
	BaseObject(char*,D3DXVECTOR3 pos,int,int,OBJECT_TYPE,RECT,D3DXVECTOR3 speed);
	BaseObject(const BaseObject& obj);
	//int GetId();
	char* GetName();
	int GetWidth();
	int GetHeight();
	OBJECT_TYPE GetType();
	RECT GetBound();
	D3DXVECTOR3 GetSpeed();
	D3DXVECTOR3 GetPosition();
	BaseObject& operator=(const BaseObject& u);
	void SetName(char* name);
	//void SetId(int id);
	void SetType(OBJECT_TYPE type);
	void SetBound(RECT bound);
	void SetWidth(int value);
	void SetHeight(int value);
	void SetPosition(D3DXVECTOR3);
	void SetSpeed(D3DXVECTOR3);
	virtual void ToString();
	virtual void Init();								//khoi tao thong so
	virtual void Load(Contents*);						//load hinh
	virtual void Update(KeyBoard* keyboard,DWORD dt);	//xu ly logic
	virtual void Draw(Graphic*g);				//ve
	virtual void OnCollisionWith(BaseObject* obj);
	static bool AABBCheck(BaseObject *a,BaseObject *b);
	float CheckCollision(BaseObject* obj,float& normalX,float& normalY);		//kt va cham (AABB)
	BaseObject* GetSweptBroadPhaseBox(BaseObject *);

	~BaseObject(void);
};

#endif
/*Cuong's dialog
*	23/11/2015	 - Cap nhat cac ham va cham sweptAABB cua Huy
*	15/11/2015	 - Tam dong thuoc tinh id  (li do la name co the thay the duoc)
				 - Xoa param DWORD deltaTime cua Draw()
				 - Tich hop va sua doi ham CheckCollision,AABB,GetSweptBroadPhaseBox cua Hoa
				 - Sua thuoc tinh int speed thanh D3DXVECTOR3 speed
				 - Them ham OnCollisionWith voi muc dich xu li sau va cham
*	12/11/2015	 - Them thuoc tinh OBJECT_TYPE type
				 - Them phuong thuc Get ,Set va ToString de test tren output
*/