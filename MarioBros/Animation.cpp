#include "Animation.h"
Animation* Animation::instance = NULL;
list<SPRITE_INFO> Animation::AddSpritesFromFile(string filepath){
	list<SPRITE_INFO> spritelist;
	FILE *f = fopen(filepath.c_str(),"rt");
	char temp;
	while(!feof(f)){
		SPRITE_INFO sinfo;
		fscanf(f,"%d",&sinfo.sid);
		fscanf(f,"%c",&temp);
		fscanf(f,"%d",&sinfo.srcX);
		fscanf(f,"%c",&temp);
		fscanf(f,"%d",&sinfo.srcY);
		fscanf(f,"%c",&temp);
		fscanf(f,"%d",&sinfo.width);
		fscanf(f,"%c",&temp);
		fscanf(f,"%d",&sinfo.height);
		fscanf(f,"%c",&temp);
		fscanf(f,"%d",&sinfo.spriteNum);
		fscanf(f,"%c",&temp);
		spritelist.push_back(sinfo);
	}
	fclose(f);
	return spritelist;
}

Animation::Animation(void)
{
	//add all sprites from file here
	this->spriteList =  this->AddSpritesFromFile("./Toado.txt");
	
}

Animation* Animation::GetInstance(){
	if(instance == NULL)
		instance = new Animation();
	return instance;
}

Animation::~Animation(void)
{
}
RECT Animation::GetRect(int sid,int seq){
	RECT src;
	src.left = src.right = src.top = src.bottom = 0;
	for each(const SPRITE_INFO &s in spriteList) {
		if (s.sid==sid){
			src.left = s.srcX + seq * s.width;
			src.right = src.left + s.width;
			src.top = s.srcY;
			src.bottom = src.top + s.height;
			return src;
		}
	}
	return src;
}
int Animation::GetSpriteNum(int sid){
	for each(const SPRITE_INFO &s in spriteList) {
		if (s.sid==sid){
			return s.spriteNum - 1;
		}
	}
	return -1;
}
