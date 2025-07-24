#ifndef CONTENTS_H
#define CONTENTS_H
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
using namespace std;
class Contents
{
private:
	LPDIRECT3DDEVICE9 d3ddv;
public:
	Contents(LPDIRECT3DDEVICE9 d3ddv);
	LPDIRECT3DTEXTURE9 LoadTexture(string filePath);
	LPDIRECT3DSURFACE9 LoadSurface(string filePath);
	~Contents(void);
};

#endif