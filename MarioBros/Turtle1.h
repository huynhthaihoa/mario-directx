#ifndef TURTLE1_H
#define TURTLE1_H
#include "BaseObject.h"
class Turtle1 : public BaseObject
{
private:
	int index ;
	int count;
public:
	Turtle1(void);
    void Init();
	void Load(Contents*);
	void Update(KeyBoard*,DWORD);
	void Draw(Graphic*);
	void OnCollisionWith(BaseObject* obj);
	~Turtle1(void);
};
#endif