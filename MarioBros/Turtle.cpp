#include "Turtle.h"

Turtle::Turtle(void):BaseObject()
{
}

void Turtle::Init()
{
	this->position = D3DXVECTOR3(400,210,0);
	this->speed.x = this->speed.y = 0;
	this->index = 0;
	this->width = 16;
	this->height = 24;
	this->type = TURTLE;
	this->bound.left = 0;
	this->bound.top = 0;
	this->bound.right = 16;
	this->bound.bottom = 24;
	this->count = 0;
	this->checkLR = false;
	this->checkT = false;
}


void Turtle::Load(Contents* content){
	this->img = content->LoadTexture("./Monster.png");
}
void Turtle::Update(KeyBoard* keyboard,DWORD dt)
{
	if(checkLR == false)
	{
		if(position.x  >= 300)
			this->speed.x = -0.5f;
		if(position.x  <= 150)
			this->speed.x = 0.5f;
	}
	else
		this->speed.x = 0;
	if(checkT == false)
	{
		bound = Animation::GetInstance()->GetRect(1074,index);
		if(index >= Animation::GetInstance()->GetSpriteNum(1074))
			index = 0;
		else
			index++;
	}
	else
	{
		this->speed.x = 0;
		bound = Animation::GetInstance()->GetRect(1075,0);
	}
	this->position.x += this->speed.x ;
	
	


	/*if(position.x  <= a1)
	{
		
		bound = Animation::GetInstance()->GetRect(1074,index);
		if(index >= Animation::GetInstance()->GetSpriteNum(1074))
			index = 0;
		else
			index++;
	}
	else 
	{
		speed = 0;

		bound = Animation::GetInstance()->GetRect(1075,index);
		if(index >= Animation::GetInstance()->GetSpriteNum(1075))
			index = 0;
		else
			index++;
	}
	position.x += speed;*/
}
void Turtle::Draw(Graphic*g)
{
	g->DrawTexture(img,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
}

void Turtle::OnCollisionWith(BaseObject* obj)
{
	//xu li va cham o day
	if(/*BaseObject::*/AABBCheck(GetSweptBroadPhaseBox(this),obj))
	{//co kha nang xay ra va cham
		//MessageBox(0,"22222","Article",MB_OK);
		float normalX=0;
		float normalY=0;

		float colTime = CheckCollision(obj,normalX,normalY);

		//this->position.x += this->speed.x * colTime;
		//this->position.y += this->speed.y * colTime;
		if(colTime <1.0f)
		{
			if(normalX == 1)
			{
				this->position.x = obj->GetPosition().x - this->width - 1;
			}
			else if(normalX == -1)
			{
				this->position.x = obj->GetPosition().x + obj->GetWidth() ;
			}

			if(normalY == -1)
			{
				//MessageBox(0,"22222","Article",MB_OK);
				//checkT = true;
			}

		}
	}
	else
	{
		this->position.x += this->speed.x;
	}
}

Turtle::~Turtle(void)
{
}