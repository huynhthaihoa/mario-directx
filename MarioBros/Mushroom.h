#include "BaseObject.h"
#include"Brick.h"
#include "Utils.h"
class Mushroom : public BaseObject
{
private:
	int index ;
	BaseObject* basebrick;//xac dinh vien gach chua nam
	bool onTop;
public:
	Mushroom(void);
	Mushroom(BaseObject* basebrick);
	void Init();
	void Load(Contents*);
	void Update(KeyBoard*,DWORD);
	void Draw(Graphic*);
	void OnCollisionWith(BaseObject* obj);
	~Mushroom(void);
};
