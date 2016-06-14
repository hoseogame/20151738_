#ifndef __HSTAGE_H__
#define __HSTAGE_H__

#include <time.h>

class _Stage
{
private:
	int nBasketX;					// Note: 하트 바구니의 x 좌표
	int nBasketY;					// Note: 하트 바구니의 y 좌표	
	int nHeartCount;	            // Note: Stage별 총 하트 수
	int nGoalHeartCount;	        // Note: 목표 하트 수
	int nBarLength;					// Note: 막대기길이
	clock_t BasketMoveTime;			// Note: 하트 바구니가 움직이는 이동 시간 간격
	clock_t BasketDownHeartTime;	// Note: 하트가 떨어지는 시간 간격

public:
	_Stage();
	~_Stage();

	void Init(FILE* fp, _Stage* pStage, int stage);

	int GetBasketX() { return nBasketX; }
	int GetBasketY() { return nBasketY; }
	int GetBarLength() { return nBarLength; }
	int GetHeartCount() { return nHeartCount; }
	int GetGoalHeartCount() { return nGoalHeartCount; }
	clock_t GetBasketMoveTime() { return BasketMoveTime; }
	clock_t GetBasketDownHeartTime() { return BasketDownHeartTime; }
};



class HStage
{
private:
	_Stage* pStage;
	int nStageCount;

public:
	HStage();
	~HStage();

	void Init();
	void Release();

	_Stage GetStage(int idx = 0) { return pStage[idx]; }
	int GetStageCount() { return nStageCount; }
	
};
#endif	//__HSTAGE_H__