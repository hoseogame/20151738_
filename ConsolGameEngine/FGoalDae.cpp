#include <iostream>

#include "FGoalDae.h"

FGoalDae::FGoalDae()
{

}

FGoalDae::~FGoalDae()
{

}

void FGoalDae::Init(int x, int y, int len, int time, int dist)
{
	int Length = 0;

	nMoveX = x;
	nMoveY = y;
	nLength = len;
	MoveTime = time;
	OldTime = clock();
	nDist = dist;
	Length = nLength * 2 + 1; // Note: �迭�� �ִ� ����

	for (int i = 0; i < Length; i++)
	{
		nLineX[i] = nMoveX + 2 * (i + 1);
	}
}

bool FGoalDae::Update(clock_t CurTime,int length)
{
	if (CurTime - GetOldTime() > GetMoveTime())
	{
		SetOldTime() = CurTime;
		if (GetMoveX() + GetDist() >= 2 && ((GetLineX(length - 1) + 3) + GetDist()) <= 43)
		{
			SetMoveX_P();
			for (int i = 0; i < length; i++)
			{
				SetLineX_idx(i);
			}
		}
		else
		{
			SetDist_Reverse(); // -1 �� ������ �ٲپ� ��.
		}
	}
	return true;
}