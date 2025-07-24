#ifndef MARIO_H
#define MARIO_H
#include "BaseObject.h"
#include "Utils.h"

class Mario : public BaseObject
{
private:
	int index ;
	bool checkDie;
	int v;
public:
	Mario(void);
	void Init();
	void Load(Contents*);
	void Update(KeyBoard*,DWORD);
	void Draw(Graphic*);
	void OnCollisionWith(BaseObject* obj);
	~Mario(void);
};

#endif