#include "Mario.h"


Mario::Mario(void):BaseObject()
{
}
void Mario::Init(){
	this->type = MARIO;
	this->position = D3DXVECTOR3(250-50,210,0);
	this->speed.x = this->speed.y = 0;
	this->index = 0;
	this->width = 16;
	this->height = 32;
	this->bound.left = 0;
	this->bound.top = 0;
	this->bound.right = 16;
	this->bound.bottom = 32;
	this->checkDie = false;
	this->v = -1;
}
void Mario::Load(Contents* content){

	this->img = content->LoadTexture("./mario.png");
}
void Mario::Update(KeyBoard* keyboard,DWORD dt)
{
	//Camera::GetInstance()->UpdateViewPort(position.x,600);
	if(this->checkDie == false)
	{
		speed.x=speed.y=0;

		if(keyboard->IsKeyDown(DIK_RIGHT))
			this->speed.x += 0.2f;

		if(keyboard->IsKeyDown(DIK_LEFT))
			this->speed.x -= 0.2f;;

		if(keyboard->IsKeyDown(DIK_DOWN))
			this->speed.y += 0.2f;;

		if(keyboard->IsKeyDown(DIK_UP))
			this->speed.y -= 0.2f;;

		speed.x*=dt;
		speed.y*=dt;


		bound = Animation::GetInstance()->GetRect(1001,index);
		if(index >= Animation::GetInstance()->GetSpriteNum(1001))
			index = 0;
		else
			index++;
	}
	else
	{
		speed.x=speed.y=0;
		if(this->position.y == 180)
			v = 1;
		this->speed.y = v;
		bound = Animation::GetInstance()->GetRect(1010,0);
	}

}
void Mario::Draw(Graphic*g){
	g->DrawTexture(img,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
}
void Mario::OnCollisionWith(BaseObject* obj)
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
			//MessageBox(0,"Co va cham","Article",MB_OK);
			//MessageBox(0,"Co va cham","Article",MB_OK);
		
			if(obj->GetType() == GOMBA)
			{
				//CHET	
			}
			if(obj->GetType() == PIPE)
			{
			
				if(normalX == -1)
				{
					this->position.x = obj->GetPosition().x+obj->GetWidth() + 1;
				}
				else if(normalX == 1)
				{
					this->position.x = obj->GetPosition().x-this->width-1;
				}

				if(normalY ==  1)
				{
					this->position.y = obj->GetPosition().y - this->height-1;
				}
				else if(normalY == -1)
				{
					this->position.y = obj->GetPosition().y+obj->GetHeight() + 1;
				}
			}
			if(obj->GetType() == TURTLE)
			{
				if(normalX == 1)
				{
					//MessageBox(0,"Co va cham voi rua","Article",MB_OK);
					obj->checkLR = true;
					this->checkDie = true;				
					this->position.x = obj->GetPosition().x - this->width - 1;
					
				}else if (normalX == -1)
				{
					//MessageBox(0,"Co va cham voi rua","Article",MB_OK);
					obj->checkLR = true;
					this->checkDie = true;
					this->position.x = obj->GetPosition().x + obj->GetWidth() + 1 ;
				}

				if(normalY  ==  1)
				{
					obj->checkT = true;
					this->position.y = obj->GetPosition().y - this->height-1;
				}
				else if(normalY == -1)
				{
					this->position.y = obj->GetPosition().y+obj->GetHeight()+1;
				}
				
			}
			if(obj->GetType() == BRICK)
			{
				
				if(normalY == -1)
				{

					//MessageBox(0,"Co va cham voi gach","Article",MB_OK);
					obj->checkB = true;
					obj->CreateMushroom = true;
					this->position.y = obj->GetPosition().y + obj->GetHeight() + 1;
					//this->speed.y = 0;
				}
			}
		}	
		else
		{
			/*
			this->position.x += this->speed.x;
			this->position.y += this->speed.y;

			this->speed = D3DXVECTOR3(0,0,0);
			*/
		}
	}
	else
	{	
		this->position.x += this->speed.x;
		this->position.y += this->speed.y;
		this->speed = D3DXVECTOR3(0,0,0);	
	}
	
	
	
}
Mario::~Mario(void)
{
}
