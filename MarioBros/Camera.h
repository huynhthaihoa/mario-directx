#ifndef CAMERA_H
#define CAMREA_H
#include <d3dx9.h>
class Camera
{
private :
	D3DXMATRIX  transformMatrix;
	Camera(void);

	//D3DXVECTOR3 viewport;
	static Camera* instance;
public:
	static Camera* GetInstance();
	void UpdateViewPort(int vpx, int vpy);
	D3DXVECTOR3 GetPosInViewPort(int realPosX,int realPosY);
	
	~Camera(void);
};
#endif
