#ifndef __HSTAGE_H__
#define __HSTAGE_H__

#include <time.h>

class _Stage
{
private:
	int nBasketX;					// Note: ��Ʈ �ٱ����� x ��ǥ
	int nBasketY;					// Note: ��Ʈ �ٱ����� y ��ǥ	
	int nHeartCount;	            // Note: Stage�� �� ��Ʈ ��
	int nGoalHeartCount;	        // Note: ��ǥ ��Ʈ ��
	int nBarLength;					// Note: ��������
	clock_t BasketMoveTime;			// Note: ��Ʈ �ٱ��ϰ� �����̴� �̵� �ð� ����
	clock_t BasketDownHeartTime;	// Note: ��Ʈ�� �������� �ð� ����

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