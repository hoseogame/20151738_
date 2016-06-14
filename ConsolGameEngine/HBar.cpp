#include <iostream>

#include "HBar.h"
#include "HStage.h"

HBar::HBar()
{
	nBarLength = 0;

	for (int i = 0; i < 7; i++)
	{
		nX[i] = 0;
	}
	nMoveY = 0;
}

HBar::~HBar()
{

}

void HBar::Init(HStage* pStage, int g_nStage)
{
	nMoveY = 22;
	
	nBarLength = pStage->GetStage(g_nStage).GetBarLength(); // 막대기의 길이 
	OldTime = clock();
	MoveTime = 40;

	for (int i = 0; i < nBarLength; i++)
	{
		nX[i] = 10 + 2 * (i + 1); // 15 컬럼부터		
	}
}

bool HBar::Update(clock_t CurTime,int nKey)
{
	if (CurTime - GetOldTime() > GetMoveTime())
	{
		OldTime = CurTime;
		if (nKey == 'j' && GetX(0) - 1 >= BOUNDARY_MIN)   // 경계 영역 처리 충돌 처리
		{
			for (int i = 0; i < nBarLength; i++)
				SetX_M(i);
		}
		if (nKey == 'l' &&GetX(GetBarLength() - 1) + 2 <= BOUNDARY_MAX) // 경계 영역 충돌 처리
		{
			for (int i = 0; i < GetBarLength(); i++)
				SetX_P(i);
		}
	}
	return true;
}