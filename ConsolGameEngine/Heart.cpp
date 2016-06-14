#include <iostream>
#include <conio.h>

#include "Heart.h"

#include "Object.h"
#include "HBar.h"
#include "HBasket.h"
#include "HHeart.h"
#include "HStage.h"
#include "HScreen.h"

Heart::Heart()
{
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		object[i] = NULL;
	}
	g_sStageInfo = NULL;
}

Heart::~Heart()
{
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		if (object[i] != NULL)
		{
			if (i == HEART)
			{
				delete[] object[i];
				object[i] = NULL;
			}
			else
			{
				delete object[i];
				object[i] = NULL;
			}
		}
	}
	if (g_sStageInfo != NULL)delete g_sStageInfo;
	g_sStageInfo = NULL;

	if (screen != NULL)delete screen;
	screen = NULL;
}

void Heart::Init()
{
	if (g_nStage == -1) // 1번만 초기화가 되는 부분에 대한 처리 사항
	{
		object[BAR] = new HBar;
		object[BASKET] = new HBasket;
		object[HEART] = new HHeart[HEART_NUM];

		g_sStageInfo = new HStage;
		screen = new HScreen;

		g_nStage = 0;
		g_sStageInfo->Init();
		screen->ScreenInit();
	}
	g_nGrade = 0;
	g_nCount = 0;
	g_nGoalCount = 0;
	g_nDeadCount = 0;
	g_GameState = INIT;

	HBar* g_Bar = dynamic_cast<HBar*>(object[BAR]);
	HBasket* g_sBasket = dynamic_cast<HBasket*>(object[BASKET]);

	g_Bar->Init(g_sStageInfo, g_nStage);
	g_sBasket->Init(g_sStageInfo, g_nStage);
}

bool Heart::Input()
{
	int nKey;

	clock_t CurTime = clock();
	if (_kbhit())
	{
		if (g_GameState == RESULT)return false;
		nKey = _getch();
		InputSwitch(CurTime, nKey);
	}
	return true;
}

void Heart::Update()
{
	clock_t CurTime = clock();

	UpdateSwitch(CurTime);
}

void Heart::Render()
{
	char string[100];

	screen->ScreenClear();
	RenderSwitch(string);
	screen->ScreenFlipping();
}

void Heart::Release()
{
	g_sStageInfo->Release();
	screen->ScreenRelease();
}


void Heart::InputSwitch(clock_t CurTime, int key)
{
	HBar* g_Bar;

	switch (key)
	{
	case ' ':
		if (g_GameState == INIT && g_nStage == 0)
		{
			g_GameState = READY;
			g_UpdateOldTime = clock();  // ready를 일정시간 지속해 주기 위해 							
		}
		break;
	case 'j':
	case 'l':
		if (g_GameState == RUNNING)
		{
			g_Bar = dynamic_cast<HBar*>(object[BAR]);
			g_Bar->Update(CurTime, key);
		}
		break;
	case 'y':
	case 'Y':
		if (g_GameState == FAILED)
		{
			Init();
			g_GameState = READY;
			g_UpdateOldTime = clock();
		}
		break;
	case 'n':
	case 'N':
		if (g_GameState == FAILED)
		{
			g_GameState = RESULT;
		}
		break;
	}
}

void Heart::UpdateSwitch(clock_t CurTime)
{
	int Length = 0;

	HBar* g_Bar;
	HBasket* g_sBasket;
	HHeart* g_sHeart;

	switch (g_GameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 3000)  // 2초
		{
			g_GameState = RUNNING;
			g_GameStartTime = CurTime;
		}
		break;

	case RUNNING:
		if (g_nDeadCount == g_sStageInfo->GetStage(g_nStage).GetHeartCount())
		{
			g_GameState = STOP;
			return;
		}
		Length = g_sStageInfo->GetStage(g_nStage).GetBarLength();

		g_Bar = dynamic_cast<HBar*>(object[BAR]);
		g_sBasket = dynamic_cast<HBasket*>(object[BASKET]);
		g_sHeart = dynamic_cast<HHeart*>(object[HEART]);

		g_nCheck = g_sBasket->Updata(CurTime, g_nGoalCount,
			g_sStageInfo->GetStage(g_nStage).GetHeartCount());

		g_sHeart->Update(g_sHeart, g_sBasket, g_Bar, CurTime,
			g_nGoalCount, g_nCount, g_nGrade,
			g_nDeadCount, Length, g_nCheck);

		break;
	case STOP:
		if (g_nCount >= g_sStageInfo->GetStage(g_nStage).GetGoalHeartCount())
		{
			g_UpdateOldTime = CurTime;
			g_GameState = SUCCESS;
			g_nTotalGrade += g_nGrade;
		}
		else {
			g_GameState = FAILED;
		}
		break;
	case SUCCESS:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			if (g_nStage + 1 > 4)
			{
				g_GameState = RESULT;
			}
			else
			{
				g_UpdateOldTime = CurTime;
				++g_nStage;
				Init();
				g_GameState = READY;
			}
		}
		break;
	}
}

void Heart::RenderSwitch(char string[])
{
	HBar* g_Bar;
	HBasket* g_sBasket;
	HHeart* g_sHeart;

	switch (g_GameState)
	{
	case INIT:
		if (g_nStage == 0)
			screen->InitScreen();
		break;

	case READY:
		screen->ReadyScreen(g_nStage);
		break;
	case RUNNING:
		g_sBasket = dynamic_cast<HBasket*>(object[BASKET]);
		g_sHeart = dynamic_cast<HHeart*>(object[HEART]);
		g_Bar = dynamic_cast<HBar*>(object[BAR]);

		screen->RunningScreen(g_nStage, g_sStageInfo->GetStage(g_nStage).GetHeartCount(),
			g_sStageInfo->GetStage(g_nStage).GetGoalHeartCount(), g_nCount, g_nGrade);
		
		screen->ScreenPrint(g_sBasket->GetMoveX(), g_sBasket->GetMoveY(), "▦");

		for (int i = 0; i < g_nGoalCount; i++)
		{
			if (g_sHeart[i].GetLife() == 1)
				screen->ScreenPrint(g_sHeart[i].GetMoveX(), g_sHeart[i].GetMoveY(), "♡");
		}

		for (int i = 0; i < g_Bar->GetBarLength(); i++)
			screen->ScreenPrint(g_Bar->GetX(i), g_Bar->GetMoveY(), "▣");

		break;
	case SUCCESS:
		screen->SuccessScreen();
		sprintf(string, "%d", g_nStage + 1);
		screen->ScreenPrint(19, 7, string);
		sprintf(string, "총점: %d", g_nTotalGrade);
		screen->ScreenPrint(18, 17, string);
		break;
	case FAILED:
		screen->FailureScreen();
		sprintf(string, "%d", g_nStage + 1);
		screen->ScreenPrint(20, 9, string);
		break;

	case RESULT:
		screen->ResultScreen(g_nTotalGrade);
		break;
	}
}