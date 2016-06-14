#include <iostream>

#include "HBasket.h"
#include "HStage.h"

HBasket::HBasket()
{
	nMoveX = 0;
	nMoveY = 0;
	nDist = 0;
}

HBasket::~HBasket()
{

}

void HBasket::Init(HStage* pStage, int g_nStage)
{
	
	nMoveX = pStage->GetStage(g_nStage).GetBasketX();
	nMoveY = pStage->GetStage(g_nStage).GetBasketY();
	OldTime = clock();
	MoveTime = pStage->GetStage(g_nStage).GetBasketMoveTime();
	DownHeartTime = pStage->GetStage(g_nStage).GetBasketDownHeartTime();
	OldDownHeartTime = clock();
	nDist = 1;
}

bool HBasket::Updata(clock_t CurTime, int g_nHeartDownCount, int nHeartCount)
{
	if ((CurTime - OldTime) > MoveTime)
	{
		OldTime = CurTime;
		nMoveX += nDist;

		if (nMoveX == BOUNDARY_MIN || nMoveX + 1 == BOUNDARY_MAX)
			nDist = -1 * nDist;
	}

	if (g_nHeartDownCount < nHeartCount)
	{
		if ((CurTime - OldDownHeartTime) > DownHeartTime)
		{
			OldDownHeartTime = CurTime;
			return true;
		}
	}
	else 
	{ 
		nDist = 0; 
	}

	return false;
}