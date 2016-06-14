#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <time.h>
#include <Windows.h>

class Screen
{
public:
	int g_nScreenIndex;
	HANDLE g_hScreen[2];

	Screen();
	virtual ~Screen();

	void ScreenInit();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint(short x, short y, char *string);
	void SetColor(unsigned short color);

	virtual void InitScreen() = 0;
	virtual void ReadyScreen(int stage) = 0;
	virtual void RunningScreen(int stage, int A, int B, int C, int D) = 0;
	virtual void SuccessScreen() = 0;
	virtual void FailureScreen() = 0;
	virtual void ResultScreen(int stage) = 0;

	virtual void Effect(int x, int y){}
};

#endif	//__SCREEN_H__