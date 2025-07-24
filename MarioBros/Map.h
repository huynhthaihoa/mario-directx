#pragma once
#ifndef MAP_H
#define MAP_H
#include "BaseObject.h"
#include <iostream>
#include <list>
using namespace std;

//I DONT TAKE TILE WIDTH ,HEIGHT TO STRUCT TILE AS ITS DUPLICATED , SO ON I TRY TO SAVE DATA BY
//WIDTH AND HEIGHT OF A TILE ARE LIED IN NAME OF PATH FILE
//<NAME_MAP>_<W>_<H>.TXT
class Map
{
private:
	string dataPath;//path of map1_1.txt
	int mid;		//map id
	int width;		//map width   = columns
	int height;		//map height  = lines
	int** data;	
	list<BaseObject> virObjList;
	int length;
public:
	static const int MAX_OBJECTS = 100;
	Map(int mid,string dataPath );
	void Init(int,int);
	int** GetData();
	int GetMapWidth();
	int GetMapHeight();
	list<BaseObject> GetVirtualObjectList();
	BaseObject* GetVirtualObjects(int&);
	~Map(void);
};
#endif