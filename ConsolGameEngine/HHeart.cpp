#include <iostream>

#include "HHeart.h"

#include "HBasket.h"
#include "HBar.h"

HHeart::HHeart()
{
	nLife = 0;
	nMoveX = 0;
	nMoveY = 0;
	nDist = 0;
}

HHeart::~HHeart()
{

}

bool HHeart::Update(HHeart*	g_sHeart, HBasket* g_sBasket, HBar*	g_Bar, clock_t CurTime, int& HeartDownCount, int& HeartCount, int& g_nGrade, int& g_nDeadHeartCount, int nLength, bool& time)
{
	if (time != false)
	{
		g_sHeart[HeartDownCount].nLife = 1;
		g_sHeart[HeartDownCount].nDist = 1;
		g_sHeart[HeartDownCount].nMoveX = g_sBasket->GetMoveX();
		g_sHeart[HeartDownCount].nMoveY = g_sBasket->GetMoveY() + 1;
		g_sHeart[HeartDownCount].OldTime = CurTime;
		// �ּ� 100, �ִ� 399 �и�������
		g_sHeart[HeartDownCount].MoveTime = rand() % 300 + 100;
		HeartDownCount++;
		time = false;
	}

	for (int i = 0; i < HeartDownCount; i++)
	{
		if (g_sHeart[i].nLife == 1)
		{
			if (CurTime - g_sHeart[i].OldTime > g_sHeart[i].MoveTime)
			{
				g_sHeart[i].OldTime = CurTime;
				g_sHeart[i].nMoveY += g_sHeart[i].nDist;

				// Note: ������ ��Ʈ�� �浹 üũ 
				if (g_sHeart[i].nMoveY >= g_Bar->GetMoveY())
				{
					if ((g_sHeart[i].nMoveX >= g_Bar->GetX(0) && g_sHeart[i].nMoveX <= (g_Bar->GetX(nLength - 1) + 1))
						|| ((g_sHeart[i].nMoveX + 1) >= g_Bar->GetX(0) && (g_sHeart[i].nMoveX + 1) <= (g_Bar->GetX(nLength - 1) + 1)))
					{
						g_sHeart[i].nLife = 0;

						//������ ����
						g_nGrade += 10;
						HeartCount++;
						g_nDeadHeartCount++;
					}
					else if (g_sHeart[i].nMoveY > 22) // �ϴ��� ��� ������ �浹
					{
						g_sHeart[i].nLife = 0;
						g_nDeadHeartCount++;
					}
				}
			}
		}
	}
	return true;
}