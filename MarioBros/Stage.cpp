#include "Stage.h"

Stage* Stage::instance = NULL;
Stage::Stage()
{
	Init("./tiledset_16_16.txt",16,16); // read file .txt and load data from file to tilelist
}
Stage* Stage::GetInstance()
{
	if(instance == NULL)
		instance = new Stage();
	return instance;
}
void Stage::Init(string tilePath,int tileW,int tileH)
{
	//load tileset from file txt to game
	this->tileWidth = tileW;
	this->tileHeight = tileH;
	//read tiledset
	//*******************************tileset_16_16.txt***************************
	FILE *f = fopen(tilePath.c_str(),"rt");
	char temp;
	while(!feof(f)){
		ATILE t;
		RECT src;
		fscanf(f,"%d",&t.tid);
		fscanf(f,"%c",&temp);
		fscanf(f,"%d",&src.left);
		fscanf(f,"%c",&temp);
		fscanf(f,"%d",&src.top);
		fscanf(f,"%c",&temp);
		src.right = src.left  + tileW;
		src.bottom = src.top + tileH;
		t.srcRect = src;
		originTileList.push_back(t);
	}
	fclose(f);
}

void Stage::SetCurrentMap(MAP_LEVEL level)
{
	
	//to change map and build map 
	switch(level){
	case LEVEL1:
		this->currMap = new Map(LEVEL1,"./map11_4.txt");
		//this->currMap = new Map(LEVEL1,"./map1_1.txt");
			break;
	default:
		this->currMap = NULL;
		break;
	}
	if(currMap == NULL)
		return;
	//********************* build map here **********************
	this->currMap->Init(this->tileWidth,this->tileHeight); // tileW,tileH are param to custom position and rect of virtual objs
	//********************* build currtilelist ******************
	int** temp = this->currMap->GetData();
	int	sc = this->currMap->GetMapWidth();
	int sd = this->currMap->GetMapHeight();
	currTileList = new ATILE*[sd];
	for(int i=0;i<sd;i++)
		currTileList[i] = new ATILE[sc];

	for(int i=0;i<sd;i++)
		for(int j=0;j<sc;j++){
			ATILE tile ;
			tile.tid = temp[i][j];
			tile.srcRect = GetRect(temp[i][j]);
			currTileList[i][j] = tile;
		}
}



ATILE Stage::GetTile(int tid){
	//get a tile by tid
	for each(const ATILE &t in originTileList) {
		if (t.tid==tid){
			return t;
		}
	}
	ATILE e ;
	e.tid = -1;
	return e;
}
RECT Stage::GetRect(int tid)
{
	RECT e ;
	e.left=e.right=e.bottom=e.top = -1;
	if(tid <= 0)
		return e;
	for each(const ATILE &t in originTileList) {
		if (t.tid==tid){
			return t.srcRect;
		}
	}
	
	return e;
}
void Stage::Load(Contents* content)
{
	//load tileset.png
	this->img =  content->LoadTexture("./tiledset.png");
	
}
void Stage::DrawMap(Graphic* g)
{
	/*
	int** temp = this->currMap->GetData();
	int	sc = this->currMap->GetMapWidth();
	int sd = this->currMap->GetMapHeight();

	for(int i=0;i<sd;i++){
		for(int j=0;j<sc;j++){	
			if(temp[i][j] != 0)
			{
				RECT src = this->GetRect(temp[i][j]);
				g->DrawTexture(img,&src,D3DXVECTOR3(j*tileWidth,i*tileHeight,0),D3DCOLOR_XRGB(255,255,255));

			}
		}
	}*/
	// DRAW THROUGH VIEW PORT
	
	int	sc = this->currMap->GetMapWidth();
	int sd = this->currMap->GetMapHeight();

	for(int i=0;i<sd;i++){
		for(int j=0;j<sc;j++){	
			if(currTileList[i][j].tid >0)
			{
				//D3DXVECTOR3 realPos(j*tileWidth+8,i*tileHeight+8,0);
				D3DXVECTOR3 realPos(j*tileWidth,i*tileHeight,0);
				//D3DXVECTOR3 vpPos = Camera::GetInstance()->GetPosInViewPort(realPos.x,realPos.y);
				g->DrawTexture(img,&currTileList[i][j].srcRect,realPos,D3DCOLOR_XRGB(255,255,255));
			}
		}
	}
	
}
Map* Stage::GetCurrentMap()
{
	return this->currMap;
}
Stage::~Stage(void)
{
	int	sc = this->currMap->GetMapWidth();
	int sd = this->currMap->GetMapHeight();
	for(int i=0;i<sd;i++)
		delete[] currTileList[i];
	delete[]currTileList;
	currTileList = NULL;
}
