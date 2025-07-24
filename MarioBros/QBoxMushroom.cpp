#include "QBoxMushroom.h"

QBoxMushroom::QBoxMushroom(void):BaseObject()
{
}

void QBoxMushroom::Init()
{
	this->position = D3DXVECTOR3(300,170,0);
	this->speed.x = this->speed.y = 1;
	this->index = 0;
	this->width = 15;
	this->height = 23;
	this->type = QBOXMUSHROOM;
	this->bound.left = 0;
	this->bound.top = 0;
	this->bound.right = 15;
	this->bound.bottom = 23;
	this->count = 0;
	this->checkT = false;
}


void QBoxMushroom::Load(Contents* content){
	this->img = content->LoadTexture("./tiledset.png");
	this->img2 = content->LoadTexture("./misc.png");
}
void QBoxMushroom::Update(KeyBoard* keyboard,DWORD dt)
{
	if(checkB == false)
	{
		bound = Animation::GetInstance()->GetRect(1080,index);
	}
	else
	{
		this->position.y -= this->speed.y;
		if(this->position.y <= 160)
		{
			this->speed.y = -1;
		}

	}
	
	


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
void QBoxMushroom::Draw(Graphic*g)
{
	g->DrawTexture(img,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
}

void QBoxMushroom::OnCollisionWith(BaseObject* obj)
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

QBoxMushroom::~QBoxMushroom(void)
{
}