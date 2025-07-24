#include "BaseObject.h"


BaseObject::BaseObject(void){
	//this->id =0 ;
	this->name = "";
	//this->speed(0,0,0);
	this->type = NOTHING;
	this->width = this->height = 15;
	this->speed = D3DXVECTOR3(0,0,0);

}
BaseObject::BaseObject(char* name,D3DXVECTOR3 pos,int w,int h,OBJECT_TYPE type,RECT srcRect,D3DXVECTOR3 speed)
{
	this->name = name;
	this->position = pos;
	this->width = w;
	this->height = h;
	this->type = type;
	this->bound = srcRect;
	this->speed = speed;
}
BaseObject::BaseObject(const BaseObject& obj){
	//this->id = obj.id;
	this->name = obj.name;
	this->img = obj.img;
	this->width = obj.width;
	this->height = obj.height;
	this->bound = obj.bound;
	this->position = obj.position;
	this->speed = obj.speed;
	this->type = obj.type;
	
}
BaseObject& BaseObject::operator=(const BaseObject& obj){
	//this->id = obj.id;
	this->name = obj.name;
	this->width = obj.width;
	this->height = obj.height;
	this->img = obj.img;
	this->bound = obj.bound;
	this->position = obj.position;
	this->speed = obj.speed;
	this->type = obj.type;
	return *this;
}

void BaseObject::Init(){

}
void BaseObject::Load(Contents* contents){
	//this->img = contents->LoadTexture("./test.png");
}
void BaseObject::Update(KeyBoard* keyboard,DWORD dt){

}
void BaseObject::SetWidth(int value)
{
	this->width = value;
}
void BaseObject::SetHeight(int value)
{
	this->height = value;
}
int BaseObject::GetWidth()
{
	return this->width;
}
int BaseObject::GetHeight()
{
	return this->height;
}
D3DXVECTOR3 BaseObject::GetSpeed()
{
	return this->speed;
}
void BaseObject::OnCollisionWith(BaseObject* obj)
{
}

float BaseObject::CheckCollision(BaseObject* obj,float& normalx,float& normaly)
{
	D3DXVECTOR3 b1 = this->position;
	int b1Width = this->width;
	int b1Height = this->height;
	float b1vx =  this->speed.x - obj->speed.x;
	float b1vy = this->speed.y - obj->speed.y;
	
	D3DXVECTOR3 b2 = obj->position;
	int b2Width = obj->width;
	int b2Height = obj->height;
	
	float xInvEntry, yInvEntry;
    float xInvExit, yInvExit;

    if (b1vx > 0.0f)
    {
        xInvEntry = b2.x - (b1.x + b1Width);
        xInvExit = (b2.x + b2Width) - b1.x;
    }
    else 
    {
        xInvEntry = (b2.x + b2Width) - b1.x;
        xInvExit = b2.x - (b1.x + b1Width);
    }

    if (b1vy > 0.0f)
    {
        yInvEntry = b2.y - (b1.y + b1Height);//duong
        yInvExit = (b2.y + b2Height) - b1.y;//duong
    }
    else
    {
        yInvEntry = (b2.y + b2Height) - b1.y;
        yInvExit = b2.y - (b1.y + b1Height);
    }
	
    float xEntry, yEntry;
    float xExit, yExit;

    if (b1vx == 0.0f)
    {
        xEntry = -std::numeric_limits<float>::infinity();
        xExit = std::numeric_limits<float>::infinity();
    }
    else
    {
        xEntry = xInvEntry / b1vx;
        xExit = xInvExit / b1vx;
    }

    if (b1vy == 0.0f)
    {
        yEntry = -std::numeric_limits<float>::infinity();
        yExit = std::numeric_limits<float>::infinity();
    }
    else
    {
        yEntry = yInvEntry / b1vy;
        yExit = yInvExit / b1vy;
    }

	float entryTime = xEntry>yEntry ? xEntry:yEntry;
	float exitTime = xExit<yExit ? xExit:yExit;
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
    {
        normalx = 0.0f;
        normaly = 0.0f;
        return 1.0f;
    }
    else
    {        		//MessageBox(0,"channn!", "Article", MB_OK);
		if (xEntry > yEntry)
        {
			if (b1.x<b2.x+b2Width)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (b1.y<b2.y+b2Height)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

        return entryTime;
    }

}
BaseObject * BaseObject::GetSweptBroadPhaseBox(BaseObject *obj)
{
	BaseObject *broadphaseobject = new BaseObject();
	broadphaseobject->position.x = (obj->speed.x > 0) ? obj->position.x : obj->position.x + obj->speed.x;
	broadphaseobject->position.y = (obj->speed.y > 0) ? obj->position.y : obj->position.y + obj->speed.y;
	broadphaseobject->width = (obj->speed.x > 0) ? obj->speed.x + obj->width : obj->width - obj->speed.x;
	broadphaseobject->height = (obj->speed.y > 0) ? obj->speed.y + obj->height/*width*/ : obj->height - obj->speed.y;

	return broadphaseobject;
}
bool BaseObject::AABBCheck(BaseObject *a,BaseObject *b)
{
	return !(a->position.x +a->width <  b->position.x || a->position.x > b->position.x + b->width
		 || a->position.y + a->height < b->position.y || a->position.y > b->position.y + b->height );
}
void BaseObject::Draw(Graphic*g){
		/*g->DrawTexture(img,
			this->position,
			D3DCOLOR_XRGB(255,255,255));*/
	/*g->DrawTexture(img,
			this->position,
			D3DCOLOR_XRGB(255,255,255));*/
}
/*
int  BaseObject::GetId(){
	return this->id;
}*/
char*  BaseObject::GetName(){
	return this->name;
}
OBJECT_TYPE  BaseObject::GetType(){
	return this->type;
}
RECT  BaseObject::GetBound(){
	return this->bound;
}
D3DXVECTOR3  BaseObject::GetPosition(){
	return this->position;
}
void  BaseObject::SetName(char* name){
	//char* temp = this->name;
	//delete temp;
	this->name = new char[strlen(name)];
	strcpy(this->name,name);
}
/*
void  BaseObject::SetId(int id){
	this->id = id;
}*/
void  BaseObject::SetType(OBJECT_TYPE type){
	this->type = type;
}
void  BaseObject::SetBound(RECT bound){
	this->bound  = bound;
}
void  BaseObject::SetPosition(D3DXVECTOR3 pos){
	this->position = pos;
}
void BaseObject::SetSpeed(D3DXVECTOR3 value){
	this->speed = value;	
}
void BaseObject::ToString(){
	//printf("\nID   : %d",this->id);
	printf("\nNAME : %s",this->name);
	printf("\TYPE  : %s",this->type);
	printf("\nX	   : %d",this->position.x);
	printf("\nY	   : %d",this->position.y);
	printf("\nZ    : %d",this->position.z);

}


BaseObject::~BaseObject(void){

}
