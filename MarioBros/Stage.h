#ifndef STAGE_H
#define STAGE_H

#include "Utils.h"
#include "Map.h"
class Stage
{
private:
	LPDIRECT3DTEXTURE9 img;		//img in file "tiledset.png"
	string tilePath;			//path foward to "tiledset_16_16.txt"
	list<ATILE> originTileList;//keep origin tiles in list
	ATILE** currTileList;
	Map* currMap;
	int tileWidth;				//16
	int tileHeight;				//16
	Stage();				
	static Stage* instance;
public:
	~Stage(void);
	static Stage* GetInstance();
	void Init(string tilePath,int tileW,int tileH); //get tiled RECT set  
	void Load(Contents*);
	Map* GetCurrentMap();
	void SetCurrentMap(MAP_LEVEL);
	void DrawMap(Graphic*);

	ATILE GetTile(int tid);
	RECT GetRect(int tid);
};

#endif