#ifndef __FBALL_H__
#define __FBALL_H__

#include <time.h>

#include "Object.h"

class FPlayer;
class FGoalDae;

class FBall : public Object
{
private:
	int nIsReady;        // 준비 상태(1), 슛상태(0)

public:
	FBall();
	virtual ~FBall();

	virtual void Init();
	int Update(clock_t CurTime, FPlayer* player, FGoalDae* goaldae,
		int* g_nBallCount, int g_nGoalBallCount, int key, int gamestate, 
		int state, int nLength, bool* g_nGoal, bool* g_nIsGoal);

	int GetReady() { return nIsReady; }

	void SetReady_TRUE() { nIsReady = 1; }
	void SetReady_FALSE() { nIsReady = 0; }
};

#endif // __FBALL_H__

