#ifndef __FSCREEN_H__
#define __FSCREEN_H__

#include <time.h>
#include <Windows.h>

#include "Screen.h"

class FScreen : public Screen
{
public:
	FScreen();
	virtual ~FScreen();

	void InitScreen();
	void ReadyScreen(int stage);
	void RunningScreen(int stage, int LimitTime, int GameStartTime, int GoalBall, int BallCount);
	void SuccessScreen();
	void FailureScreen();
	void ResultScreen(int stage);

	void Effect(int nX, int nY);
};

#endif	//__FSCREEN_H__