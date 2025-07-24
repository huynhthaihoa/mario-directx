#include "Camera.h"

Camera* Camera::instance = NULL;
Camera* Camera::GetInstance()
{
	if(instance == NULL)
		instance = new Camera();
	return instance;
}

Camera::Camera(void)
{
	/*viewport.x = 0;
	viewport.y = 0;
	viewport.z = 0;*/
	D3DXMatrixIdentity(&transformMatrix);
	
}

void Camera::UpdateViewPort(int vpx, int vpy)
{
	/*viewport.x = vpx;
	viewport.y = vpy;
	viewport.z = 0;
	transformMatrix._41 = -viewport.x;
	transformMatrix._42 = viewport.y-500;*/
	//transformMatrix._11=-1;
	//transformMatrix._22= -1.0f;
	transformMatrix._41 = -vpx;
	transformMatrix._42 = vpy-400;
	
}
D3DXVECTOR3 Camera::GetPosInViewPort(int realPosX,int realPosY)
{
	//create FlipY-Translate Matrix
	/*D3DXMatrixIdentity(&transformMatrix);
	transformMatrix._22= -1.0f;
	transformMatrix._41 = -viewport.x;
	transformMatrix._42 = viewport.y;
	//creat FlipX-Translate Matrix
	D3DXMatrixIdentity(&transformMatrix);
	transformMatrix._11=-1;
	transformMatrix._41 = -viewport.x;
	transformMatrix._42 = viewport.y;*/
	
	D3DXVECTOR4 vp_pos;
	D3DXVECTOR3 realPosition(realPosX,realPosY,0);
	D3DXVec3Transform(&vp_pos,&realPosition,&transformMatrix);

	return D3DXVECTOR3(vp_pos.x,vp_pos.y,0);
}
Camera::~Camera(void)
{
}
