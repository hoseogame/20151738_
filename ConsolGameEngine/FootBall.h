#ifndef __FOOT_BALL_H__
#define __FOOT_BALL_H__

#define OBJECT_NUM 3

#include "Scene.h"

class FStage;
class Object;

class FootBall : public Scene
{
private:
	Object* object[OBJECT_NUM];
	FStage* stage;

	enum GameObject { BALL, PLAYER, GOALDAE };

public:
	FootBall();
	virtual ~FootBall();

	void Init();
	bool Input();
	void Update();
	void Render();
	void Release();

	void InputSwitch(int key);
	void UpdateSwitch(clock_t CurTime);
	void RenderSwitch(char string[]);
};

#endif	//__FOOT_BALL_H__