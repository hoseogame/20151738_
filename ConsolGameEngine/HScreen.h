#ifndef __HSCREEN_H__
#define __HSCREEN_H__

#include <time.h>
#include <Windows.h>

#include "Screen.h"

class HScreen : public Screen
{
public:
	HScreen();
	virtual ~HScreen();

	void InitScreen();
	void ReadyScreen(int stage);
	void RunningScreen(int stage, int heart, int aim, int count, int score);
	void SuccessScreen();
	void FailureScreen();
	void ResultScreen(int score);
};

#endif	//__HSCREEN_H__