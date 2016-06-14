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
	
	nBarLength = pStage->GetStage(g_nStage).GetBarLength(); // ������� ���� 
	OldTime = clock();
	MoveTime = 40;

	for (int i = 0; i < nBarLength; i++)
	{
		nX[i] = 10 + 2 * (i + 1); // 15 �÷�����		
	}
}

bool HBar::Update(clock_t CurTime,int nKey)
{
	if (CurTime - GetOldTime() > GetMoveTime())
	{
		OldTime = CurTime;
		if (nKey == 'j' && GetX(0) - 1 >= BOUNDARY_MIN)   // ��� ���� ó�� �浹 ó��
		{
			for (int i = 0; i < nBarLength; i++)
				SetX_M(i);
		}
		if (nKey == 'l' &&GetX(GetBarLength() - 1) + 2 <= BOUNDARY_MAX) // ��� ���� �浹 ó��
		{
			for (int i = 0; i < GetBarLength(); i++)
				SetX_P(i);
		}
	}
	return true;
}