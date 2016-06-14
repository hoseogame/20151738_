#include <iostream>

#include "FBall.h"
#include "FPlayer.h"
#include "FGoalDae.h"

FBall::FBall()
{

}

FBall::~FBall()
{

}

void FBall::Init()
{
	nIsReady = 1;
	nMoveX = 20;
	nMoveY = 22 - 1;
	MoveTime = 100;
}

int FBall::Update(clock_t CurTime, FPlayer* player, FGoalDae* goaldae, int* g_nBallCount, int g_nGoalBallCount, int key, int gamestate, int state, int nLength, bool* g_nGoal, bool* g_nIsGoal)
{
	if (key == 'k' && GetReady() && gamestate == state)
	{
		SetMoveX() = player->GetMoveX();
		SetMoveY() = player->GetMoveY() - 1;
		SetOldTime() = clock();
		SetReady_FALSE();
	}
	else if (GetReady() == 0) // �̵� ���� �� 
	{	// �̵� �ð� ���ݿ� ���� �̵�
		if ((CurTime - GetOldTime()) > GetMoveTime())
		{
			if (GetMoveY() - 1 > 0)
			{
				SetMoveY() -= 1;
				SetOldTime() = CurTime; // ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����
											  // ��� ���� �浹
				if (GetMoveX() >= goaldae->GetLineX(0) && GetMoveX() + 1 <= goaldae->GetLineX(nLength - 1) + 1)
				{
					if (GetMoveY() <= goaldae->GetMoveY())
					{   // �� �ʱ�ȭ
						SetReady_TRUE();
						SetMoveX() = player->GetMoveX();
						SetMoveY() = player->GetMoveY() - 1;
						*g_nBallCount += 1;  // ������ ���� ����										

						if (*g_nBallCount == g_nGoalBallCount) // ���� ��ǥ ������ ������ ������ SUCCESS g_nGoal = 1
						{
							*g_nGoal = true;
							return 1;
						}
						// ȿ�� ���
						if (*g_nIsGoal == false)
						{
							*g_nIsGoal = true;
							return 2;
						}
					}
					// ��� �浹 
				}
				else if ((GetMoveX() >= goaldae->GetLineX(0) - 2 && GetMoveX() <= goaldae->GetLineX(0) - 1) ||
					(GetMoveX() + 1 >= goaldae->GetLineX(0) - 2 && GetMoveX() + 1 <= goaldae->GetLineX(0) - 1) ||
					(GetMoveX() >= goaldae->GetLineX(nLength - 1) + 2 && GetMoveX() <= goaldae->GetLineX(nLength - 1) + 3) ||
					(GetMoveX() + 1 >= goaldae->GetLineX(nLength - 1) + 2 && GetMoveX() + 1 <= goaldae->GetLineX(nLength - 1) + 3))
				{
					if (GetMoveY() <= goaldae->GetMoveY())
					{   // �� �ʱ�ȭ
						SetReady_TRUE();
						SetMoveX() = player->GetMoveX();
						SetMoveY() = player->GetMoveY() - 1;
					}
				}
			}
			else // �� �ʱ�ȭ
			{
				SetReady_TRUE();
				SetMoveX() = player->GetMoveX();
				SetMoveY() = player->GetMoveY() - 1;
			}
		}
	}
	else
	{
		SetMoveX() = player->GetMoveX();
	}

	return 0;
}