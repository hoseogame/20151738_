#include <iostream>

#include "FStage.h"

FStage::FStage()
{

}

FStage::~FStage()
{

}

void FStage::Init(int stage)
{
	//�������� �Ӽ� ����
	nGoalBall = 3 + stage + 1;
	LimitTime = 1000 * (30 - stage);
	if (LimitTime < 1000)LimitTime = 1000;	//�ּ� 1��
	nGoalDaeLength = 1;
	nGoalDaeX = 20;
	nGoalDaeY = 3;
	MoveTime = 300 - (stage * 30);
	if (MoveTime < 10)MoveTime = 10;		//�ּ� �ð����� 10
	nDist = 1;
}