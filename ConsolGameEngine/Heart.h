#ifndef __HEART_H__
#define __HEART_H__

#define OBJECT_NUM 3
#define HEART_NUM 100

#include "Scene.h"

class HStage;
class Object;

class Heart : public Scene
{
private:
	Object* object[OBJECT_NUM];
	HStage*	g_sStageInfo;

	enum GameObject { BAR, BASKET, HEART };
public:
	Heart();
	virtual ~Heart();

	void Init();
	bool Input();
	void Update();
	void Render();
	void Release();

	void InputSwitch(clock_t CurTime, int key);
	void UpdateSwitch(clock_t CurTime);
	void RenderSwitch(char string[]);
};
#endif	//__HEART_H__