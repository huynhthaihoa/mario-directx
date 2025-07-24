#ifndef ANIMATION_H
#define ANIMATION_H
#include "Contents.h"
#include <list>
using namespace std;

typedef struct SPRITE_INFO{
	int sid;
	int srcX;
	int srcY;
	int width;
	int height;
	int spriteNum;
};


class Animation
{
private:
	static Animation* instance ;
	list<SPRITE_INFO> spriteList;
	Animation();
public:
	
	static Animation* GetInstance();
	list<SPRITE_INFO> AddSpritesFromFile(string filePath);
	
	
	RECT GetRect(int sid,int seq);
	int GetSpriteNum(int sid);
	~Animation();
};

#endif