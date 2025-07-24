#include "Monster.h"


Monster::Monster(void)
{
}
void Monster::Init(){
	this->position = D3DXVECTOR3(250+50+150,210,1);
	this->speed.x = -1;//(1,1,0);
	this->speed.y = 0;
	this->index = 0;
	this->type = GOMBA;
	this->width = 15;
	this->height = 15;
	this->bound.left = 100;
	this->bound.top = 100;
	this->bound.right = 16;
	this->bound.bottom = 16;
	
}
void Monster::Load(Contents* content){
	this->img = content->LoadTexture("./Monster.png");
}
void Monster::Update(KeyBoard* keyboard,DWORD dt)
{
	
	/*if(position.x == 400)
		speed.x = -1;
	if(position.x == 100)
		speed.x = 1;
		*/
	//position.x+=speed.x;
	//Camera::GetInstance()->UpdateViewPort(position.x,position.y);
	bound = Animation::GetInstance()->GetRect(1072,index);
	if(index >= Animation::GetInstance()->GetSpriteNum(1072))
		index = 0;
	else
		index++;
}
void Monster::Draw(Graphic*g)
{
	g->DrawTexture(img,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
}
void Monster::OnCollisionWith(BaseObject* col)
{
	
	float normalX=0,normalY=0;
	float colTime = CheckCollision(col,normalX,normalY);
	this->position.x += this->speed.x * colTime;
	this->position.y += this->speed.y * colTime;
	if(colTime <1)
	{
		float remainTime = 1 - colTime;
		this->speed.x *= remainTime;
		this->speed.y *= remainTime;
		if(abs(normalX > 0.0001f))
		{
				this->speed.x = -this->speed.x;
		}
		if(abs(normalY > 0.0001f))
		{
				this->speed.y = -this->speed.y;
		}
		if(normalX == 1)
		{
			
			
			this->position.x = col->GetPosition().x-16;
			
		}
		if(normalX == -1)
		{
			this->position.x = col->GetPosition().x+ col->GetWidth();
		}
	}
}
Monster::~Monster(void)
{
}
