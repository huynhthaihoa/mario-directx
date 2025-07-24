#ifndef MONSTER_H
#define MONSTER_H
#include "BaseObject.h"
class Monster :
	public BaseObject
{
protected:
	int index ;
public:
	Monster(void);
	void Init();
	void Load(Contents*);
	void Update(KeyBoard*,DWORD);
	void Draw(Graphic*);
	void OnCollisionWith(BaseObject* obj);
	~Monster(void);
};
#endif

