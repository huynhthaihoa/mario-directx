#include "Brick.h"


Brick::Brick(void):BaseObject()
{
}
void Brick::Init(){
	this->position = D3DXVECTOR3(300,170,0);
	this->speed.y  = 1;
	this->speed1.y = 1;
	this->speed2.y = 1;
	this->width = 16;
	this->height = 16;
	this->index = 0;
	this->bound.left = 0;
	this->bound.top = 0;
	this->bound.right = 16;
	this->bound.bottom = 16;
	D3DXVECTOR3 p = D3DXVECTOR3(300,160,0);
	this->p2 = p;
	this->p3 = p;
    this->p4 = p;
	this->p5 = p;
	int a;
	this->checkB = false;
	this->type = BRICK;
	this->isDie = false;
	this->CreateMushroom = false;
}

void Brick::Load(Contents* content){
	this->img = content->LoadTexture("./tiledset.png");
	this->img1 = content->LoadTexture("./misc.png");
	this->img2 = content->LoadTexture("./misc.png");
	this->img3 = content->LoadTexture("./misc.png");
	this->img4 = content->LoadTexture("./misc.png");
	this->img5 = content->LoadTexture("./misc.png");
}

void Brick::Update(KeyBoard* keyboard,DWORD dt){
	if(!this->CreateMushroom)
		bound = Animation::GetInstance()->GetRect(1080,index);
	else
		bound = Animation::GetInstance()->GetRect(1081,index);
	/*if(this->checkB == false)
	{
		bound = Animation::GetInstance()->GetRect(1080,index);
	    this->speed.y = 0;
	}*/
	//else
	//{
	//	position.x = 300;
	//	position.y -= speed.y;
	//	if((position.y < 170) && (position.y >= 160) )
	//		this->bound = Animation::GetInstance()->GetRect(1117,index);
	//	else 
	//	{
	//		if(this->p2.y == 150)
	//			this->speed1.y = -1;
	//		this->p2.x -= this->speed2.y; this->p2.y -= this->speed1.y;
	//        this->p3.x += this->speed2.y; this->p3.y -= this->speed1.y;
	//		this->p4.x -= this->speed2.y; this->p4.y += this->speed2.y;
	//		this->p5.x += this->speed2.y; this->p5.y += this->speed2.y;
	//		this->bound = Animation::GetInstance()->GetRect(1118,index);
	//		this->bound = Animation::GetInstance()->GetRect(1119,index);
	//		this->bound = Animation::GetInstance()->GetRect(1120,index);
	//		this->bound = Animation::GetInstance()->GetRect(1121,index);
	//		
	//	}
	//}
}

void Brick::OnCollisionWith(BaseObject* obj)
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

		}
	}
}

void Brick::Draw(Graphic*g){
	g->DrawTexture(img,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
	//if(this->checkB == false)
	//	g->DrawTexture(img,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
	//else
	//{
	//	//if((position.y < 170) && (position.y >= 160) )
	//		g->DrawTexture(img1,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
	//	/*else
	//	{
	//		if((p2.x >= 270) && (p3.x <= 330))
	//		{			
	//			g->DrawTexture(img2,&bound,this->p2,D3DCOLOR_XRGB(255,255,255));		
	//			g->DrawTexture(img3,&bound,this->p3,D3DCOLOR_XRGB(255,255,255));			
	//			g->DrawTexture(img4,&bound,this->p4,D3DCOLOR_XRGB(255,255,255));
	//			g->DrawTexture(img5,&bound,this->p5,D3DCOLOR_XRGB(255,255,255));
	//		}*/
	//	}
	//}
	/*if(position.y > 400)
	    g->DrawTexture(img,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
	else
	{
		if((position.y < 400) && (position.y > 350) )
			g->DrawTexture(img1,&bound,this->position,D3DCOLOR_XRGB(255,255,255));
		else
		{
			if((p2.x >= 450) && (p3.x <= 550))
			{		
				g->DrawTexture(img2,&bound,this->p2,D3DCOLOR_XRGB(255,255,255));		
				g->DrawTexture(img3,&bound,this->p3,D3DCOLOR_XRGB(255,255,255));			
				g->DrawTexture(img4,&bound,this->p4,D3DCOLOR_XRGB(255,255,255));
				g->DrawTexture(img5,&bound,this->p5,D3DCOLOR_XRGB(255,255,255));
			}
		}
	}*/
}

Brick::~Brick(void)
{

}