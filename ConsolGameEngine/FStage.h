#ifndef __FSTAGE_H__
#define __FSTAGE_H__

#include <time.h>

class FStage
{
private:
	int nGoalBall;			// 골인해야 할 볼의 개수 
	clock_t LimitTime;      // 제한 시간 

	int nGoalDaeLength;		// 골대 길이 
	int nGoalDaeX;			// 골대 이동 X 좌표
	int nGoalDaeY;			// 골대 이동 Y 좌표 
	clock_t MoveTime;		// 골대 이동 시간 간격
	int nDist;				// 골대 이동 거리

public:
	FStage();
	~FStage();

	void Init(int stage);

	int GetDist() { return nDist; }
	int GetGoalDaeX() { return nGoalDaeX; }
	int GetGoalDaeY() { return nGoalDaeY; }
	int GetGoalBall() { return nGoalBall; }
	int GetGoalDaeLength() { return nGoalDaeLength; }
	
	clock_t GetMoveTime() { return MoveTime; }
	clock_t GetLimitTime() { return LimitTime; }
};

#endif	//__FSTAGE_H__