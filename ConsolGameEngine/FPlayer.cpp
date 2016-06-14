#include <iostream>

#include "FPlayer.h"

FPlayer::FPlayer()
{

}

FPlayer::~FPlayer()
{

}

void FPlayer::Init()
{
	nCenterX = 4;
	nMoveX = 20;
	nMoveY = 22;
	nX = nMoveX - nCenterX;
	g_nLength = strlen(g_strPlayer);
}

bool FPlayer::Update(int key,int* nRemain)
{
	if (key == 'j' && GetMoveX() > 2) // ���� �浹 ��� ��ǥ üũ
	{
		SetMoveX_M();
		*nRemain = GetLength() - GetCenterX() + 1;
		if (GetMoveX() - GetCenterX() < 2 || GetMoveX() + *nRemain > 43)
			SetMoveX_M();

		SetnX();
	}
	else if (key =='l' && GetMoveX() + 1 < 43) // ������ �浹 ��� ��ǥ üũ
	{
		SetMoveX_P();
		*nRemain = GetLength() - GetCenterX() + 1;
		if (GetMoveX() + *nRemain > 43 || (GetMoveX() - GetCenterX() < 2))
			SetMoveX_P();

		SetnX();
	}

	return true;
}
