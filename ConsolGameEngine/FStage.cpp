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
	//스테이지 속성 셋팅
	nGoalBall = 3 + stage + 1;
	LimitTime = 1000 * (30 - stage);
	if (LimitTime < 1000)LimitTime = 1000;	//최소 1초
	nGoalDaeLength = 1;
	nGoalDaeX = 20;
	nGoalDaeY = 3;
	MoveTime = 300 - (stage * 30);
	if (MoveTime < 10)MoveTime = 10;		//최소 시간간격 10
	nDist = 1;
}