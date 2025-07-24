#include "Map.h"

Map::Map(int mid,string dataPath)
{
	this->mid = mid;
	this->dataPath = dataPath;
	this->width = 0;
	this->height = 0;
	
	
}

Map::~Map(void)
{
	if(data != NULL)
		delete[] data;
	data = NULL;
}
list<BaseObject> Map::GetVirtualObjectList(){
	return virObjList;
}
void Map::Init(int tileW,int tileH){
	length = 0;
	//get tid from file map1_1.txt
	FILE *f = fopen(dataPath.c_str(),"rt");
	//READ FILE MAP1_1.TXT
	//****************************MAP11_4.TXT*************************
	fscanf(f,"%d",&width);
	fscanf(f,"%d",&height);
	data = new int*[height];
	for(int i=0;i<height;i++)
		data[i] = new int[width];
	int i=0;
	int j=0;
	char temp;
	/*while(i< height){
		if(j>= width)
		{
			j=0;
			i++;
		}
		fscanf(f,"%d",&data[i][j]);
		fscanf(f,"%c",&temp);
		j++;
	}*/
	for(i=0;i<height;i++)
	{
		for(j =0 ;j<width;j++)
		{
			fscanf(f,"%d",&data[i][j]);
			fscanf(f,"%c",&temp);
		}
	}
	//finish data map
	//read virtual object
	size_t read;
	size_t len = 0;
	char buffer[20];
	char* ret;
	do{
		
		BaseObject virObj;
		
		ret	=fgets(buffer,sizeof(buffer),f);
		if(ret != NULL)
			virObj.SetName(buffer);				//NAME
		ret	=fgets(buffer,sizeof(buffer),f);
		if(ret != NULL)
		{
			
			string kq = buffer;
			kq.pop_back(); // remove ''			//TYPE
			if(kq.compare("CONVEX")==0)
				virObj.SetType(CONVEX);
			else if(kq.compare("BRICK")==0)
				virObj.SetType(BRICK);
			else if(kq.compare("BOX")==0)
				virObj.SetType(BOX);
			else if(kq.compare("COIN")==0)
				virObj.SetType(COIN);
			else if(kq.compare("PIPE")==0)
				virObj.SetType(PIPE);
			else if(kq.compare("POLE")==0)
				virObj.SetType(POLE);

			D3DXVECTOR3 tempVec;					
			int param;
			fscanf(f,"%d",&param);
			tempVec.x = param * tileW;
			fscanf(f,"%c",&temp);
			fscanf(f,"%d",&param);
			tempVec.y = param * tileH;
			fscanf(f,"%c",&temp);
			tempVec.z = 0;
			virObj.SetPosition(tempVec);		//POSITION
			 
			RECT tempRect;
			
			tempRect.left = tempVec.x ;
			tempRect.top = tempVec.y ;
			fscanf(f,"%d",&param);
			tempRect.right = tempRect.left + param*tileW;
			virObj.SetWidth(param*tileW-1);		//WIDTH
			fscanf(f,"%c",&temp);
			fscanf(f,"%d",&param);
			fscanf(f,"%c",&temp);
			tempRect.bottom = tempRect.top + param*tileH;
			virObj.SetHeight(param*tileH-1);	//HEIGHT
			virObj.SetBound(tempRect);			//BOUND
			virObj.SetSpeed(D3DXVECTOR3(0,0,0));//SPEED
			length++;
			virObjList.push_back(virObj);
			//virObjects[index++] = virObj;
			//virObjList.insert(virObjList.end(),*virObj);
		}
		
	}while(ret != NULL);
	fclose(f);
	
}

int** Map::GetData(){
	return this->data;
}
int Map::GetMapWidth(){
	return this->width;
}
int Map::GetMapHeight(){
	return this->height;
}

BaseObject* Map::GetVirtualObjects(int& length){
	BaseObject* ret = new BaseObject[this->virObjList.size()];
	//int length=0;
	for(list<BaseObject>::const_iterator iterator = virObjList.begin();iterator != virObjList.end();++iterator )
		ret[length++] = *iterator; 
	return ret;//this->virObjects;
}