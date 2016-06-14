#include <iostream>

#include "HStage.h"

_Stage::_Stage()
{
	nBasketX = 0; 		// Note: ��Ʈ �ٱ����� x ��ǥ
	nBasketY = 0; 		// Note: ��Ʈ �ٱ����� y ��ǥ	
	nHeartCount = 0;       // Note: Stage�� �� ��Ʈ ��
	nGoalHeartCount = 0;       // Note: ��ǥ ��Ʈ ��
	nBarLength = 0; 			// Note: ��������
}
_Stage::~_Stage()
{

}

void _Stage::Init(FILE* fp, _Stage* pStage, int stage)
{
	for (int i = 0; i < stage; i++)
	{
		fscanf(fp, "%d %d %d %d %d %d %d\n",
			&pStage[i].BasketMoveTime,
			&pStage[i].BasketDownHeartTime,
			&pStage[i].nBasketX,
			&pStage[i].nBasketY,
			&pStage[i].nHeartCount,
			&pStage[i].nGoalHeartCount,
			&pStage[i].nBarLength
		);
	}
}



HStage::HStage()
{
	pStage = NULL;
	nStageCount = 0;
}

HStage::~HStage()
{

}

void HStage::Init()
{
	FILE* fp;
	
	fp = fopen("stage.txt", "r");
	fscanf(fp, "%d\n", &nStageCount);
	pStage = (_Stage*)malloc(sizeof(_Stage) * nStageCount);

	pStage->Init(fp, pStage, nStageCount);

	fclose(fp);
}

void HStage::Release()
{
	if (pStage != NULL)free(pStage);
}