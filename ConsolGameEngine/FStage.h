#ifndef __FSTAGE_H__
#define __FSTAGE_H__

#include <time.h>

class FStage
{
private:
	int nGoalBall;			// �����ؾ� �� ���� ���� 
	clock_t LimitTime;      // ���� �ð� 

	int nGoalDaeLength;		// ��� ���� 
	int nGoalDaeX;			// ��� �̵� X ��ǥ
	int nGoalDaeY;			// ��� �̵� Y ��ǥ 
	clock_t MoveTime;		// ��� �̵� �ð� ����
	int nDist;				// ��� �̵� �Ÿ�

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