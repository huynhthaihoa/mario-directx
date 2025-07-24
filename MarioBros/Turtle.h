#ifndef TURTLE_H
#define TURTLE_H
#include "BaseObject.h"
class Turtle : public BaseObject
{
private:
	int index ;
	int count;
public:
	Turtle(void);
    void Init();
	void Load(Contents*);
	void Update(KeyBoard*,DWORD);
	void Draw(Graphic*);
	void OnCollisionWith(BaseObject* obj);
	~Turtle(void);
};
#endif