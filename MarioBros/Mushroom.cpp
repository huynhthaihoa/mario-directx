#include "Mushroom.h"

Mushroom::Mushroom(void)
{

}
Mushroom::Mushroom(BaseObject *basebrick)
{
	this->basebrick = basebrick;
}
void Mushroom::Init()
{
	this->position = D3DXVECTOR3(300,170,0);
	this->speed.x = this->speed.y = 0;
	this->width = 16;
	this->height = 16;
	this->index = 0;
	this->bound.left = 0;
	this->bound.top = 0;
	this->bound.right = 16;
	this->bound.bottom = 16;
	D3DXVECTOR3 p = D3DXVECTOR3(300,160,0);
	int a;
	this->checkB = false;
	this->type = MUSHROOM;
	this->isDie = false;
	this->onTop = false;
}
void Mushroom::Load(Contents *content)
{
	this->img = content->LoadTexture("./misc.png");
}
void Mushroom::Update(KeyBoard* keyboard,DWORD dt)
{
	if(basebrick->CreateMushroom && !this->isDie)
	{
		if(!checkLR && !checkT)
			speed.x = 0.5f;
		speed.y = (onTop) ? -0.5f : 0.5f;
		position.x += speed.x;
		position.y += speed.y;
		if(this->position.y <= 154)
		{
			this->position.y = 154;
			onTop = true;
		}
		this->bound = Animation::GetInstance()->GetRect(1113,index);
	}
}
void Mushroom::Draw(Graphic *graphics)
{
	if(this->basebrick->CreateMushroom && !this->isDie)
		graphics->DrawTexture(img,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
}
void Mushroom::OnCollisionWith(BaseObject *obj)
{
	if(AABBCheck(GetSweptBroadPhaseBox(this),obj))
	{
		float normalX=0;
		float normalY=0;
		float colTime = CheckCollision(obj,normalX,normalY);
		if(colTime <1.0f)
		{
			if(obj->GetType() == MARIO)
			{
				MessageBox(0,"Co va cham voi mario!","Article",MB_OK);
				this->isDie = true;
			}
			else
			{
				if(normalX == -1)
				{
					this->position.x = obj->GetPosition().x+obj->GetWidth() + 1;
					this->speed.x = -1 * this->speed.x;
				}
				else if(normalX == 1)
				{
					this->position.x = obj->GetPosition().x-this->width-1;
					this->speed.x = -1 * this->speed.x;
				}
				else if(normalY == 1)
				{
					obj->checkT = true;
					this->position.y = obj->GetPosition().y - this->height-1;
				}
				else if(normalY == -1)
				{
					obj->checkB = true;
					this->position.y = obj->GetPosition().y+obj->GetHeight()+1;
				}
			}
		}
	}
	else
		{	
			this->position.x += this->speed.x;
			this->position.y += this->speed.y;
		}
}
