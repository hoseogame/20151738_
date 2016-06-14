#include <iostream>
#include <conio.h>

#include "FootBall.h"

#include "Object.h"
#include "FBall.h"
#include "FPlayer.h"
#include "FGoalDae.h"
#include "FStage.h"
#include "FScreen.h"

FootBall::FootBall()
{
	
	stage = NULL;
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		object[i] = NULL;
	}
}

FootBall::~FootBall()
{
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		if (object[i] != NULL)
		{
			delete object[i];
			object[i] = NULL;
		}
	}

	if (stage != NULL)delete stage;
	stage = NULL;
	if (screen != NULL)delete screen;
	screen = NULL;
}

void FootBall::Init()
{
	if (g_nStage == -1) 
	{
		g_nStage = 0;	//처음 한번만 초기화

		object[BALL] = new FBall;
		object[PLAYER] = new FPlayer;
		object[GOALDAE] = new FGoalDae;

		stage = new FStage;
		screen = new FScreen;
		screen->ScreenInit();
	}

	FPlayer* player = dynamic_cast<FPlayer*>(object[PLAYER]);
	FBall* ball = dynamic_cast<FBall*>(object[BALL]);
	FGoalDae* goaldae = dynamic_cast<FGoalDae*>(object[GOALDAE]);

	stage->Init(g_nStage);

	ball->Init();
	player->Init();
	goaldae->Init(
		stage->GetGoalDaeX(),
		stage->GetGoalDaeY(),
		stage->GetGoalDaeLength(),
		stage->GetMoveTime(),
		stage->GetDist()
	);

	g_nCount = 0;
	g_nGoal = false;
	g_nCheck = false;
	g_GameState = INIT;
	StayTime = 2000;		// 2초 설정
	g_UpdateOldTime = clock();
	g_LimitTime = stage->GetLimitTime();
	g_nGoalCount = stage->GetGoalBall();
}

bool FootBall::Input()
{
	int nKey = 0;

	if (_kbhit())
	{
		if (g_GameState == RESULT)return false;
		nKey = _getch();
		InputSwitch(nKey);
	}
	return true;
}

void FootBall::Update()
{
	clock_t CurTime = clock();
	UpdateSwitch(CurTime);
}

void FootBall::Render()
{
	char string[100] = { 0, };

	screen->ScreenClear();
	RenderSwitch(string);
	screen->ScreenFlipping();
}

void FootBall::Release()
{
	screen->ScreenRelease();
}


void FootBall::InputSwitch(int key)
{
	int nRemain = 0;
	FPlayer* player = dynamic_cast<FPlayer*>(object[PLAYER]);
	FBall* ball = dynamic_cast<FBall*>(object[BALL]);

	switch (key)
	{
	case 'j':
	case 'l':
		
		player->Update(key, &nRemain);
		break;
	case 'k':
		ball->Update(NULL, player, NULL, NULL, NULL,
			key, g_GameState, RUNNING, NULL, NULL, NULL);
		break;
	case 'y':
	case 'Y':
		if (g_GameState == FAILED)
		{
			Init();
			g_GameState = READY;
		}
		break;
	case 'n':
	case 'N':
		if (g_GameState == FAILED)
		{
			--g_nStage;
			g_GameState = RESULT;
		}
		break;
	case ' ':
		if (g_GameState == INIT && g_nStage == 0)
		{
			g_GameState = READY;
			g_UpdateOldTime = clock();
		}
		break;
	}
}

void FootBall::UpdateSwitch(clock_t CurTime)
{
	FPlayer* player = dynamic_cast<FPlayer*>(object[PLAYER]);
	FBall* ball = dynamic_cast<FBall*>(object[BALL]);
	FGoalDae* goaldae = dynamic_cast<FGoalDae*>(object[GOALDAE]);

	int Length = goaldae->GetLength() * 2 + 1; // Note: 배열의 최대 길이

	switch (g_GameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 2000)  // 2초
		{
			g_GameState = RUNNING;
			g_GameStartTime = CurTime;
		}
		break;
	case RUNNING:
		if (CurTime - g_GameStartTime > g_LimitTime) // Note: 제한 시간
		{
			g_GameState = STOP;
			return;
		}
		else {

			goaldae->Update(CurTime, Length);
			int Breturn = ball->Update(CurTime, player, goaldae,
				&g_nCount, g_nGoalCount, NULL, NULL, NULL,
				Length, &g_nGoal, &g_nCheck);

			if (Breturn == 1)
			{
				g_GameState = STOP;
			}
			else if (Breturn == 2)
			{
				StratTime = CurTime;
			}

			if (g_nCheck == true)
			{
				if (CurTime - StratTime > StayTime)g_nCheck = false;
			}
		}
		break;
	case STOP:
		if (g_nGoal == true)
		{
			g_GameState = SUCCESS;
			g_UpdateOldTime = CurTime;
		}
		else
		{
			g_GameState = FAILED;
		}
		break;
	case SUCCESS:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			++g_nStage;
			g_UpdateOldTime = CurTime;

			Init();
			g_GameState = READY;
		}
		break;
	}
}

void FootBall::RenderSwitch(char string[])
{
	FPlayer* player = dynamic_cast<FPlayer*>(object[PLAYER]);
	FBall* ball = dynamic_cast<FBall*>(object[BALL]);
	FGoalDae* goaldae = dynamic_cast<FGoalDae*>(object[GOALDAE]);

	int Length = 0;

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
		screen->RunningScreen(g_nStage, stage->GetLimitTime(), g_GameStartTime, stage->GetGoalBall(), g_nCount);
		screen->ScreenPrint(goaldae->GetMoveX(), goaldae->GetMoveY(), "□");
		Length = goaldae->GetLength() * 2 + 1;

		for (int i = 0; i < Length; i++)
			screen->ScreenPrint(goaldae->GetLineX(i), goaldae->GetMoveY(), "━");

		screen->ScreenPrint(goaldae->GetLineX(Length - 1) + 2, goaldae->GetMoveY(), "□");

		// Note: 효과 출력  	
		if (g_nCheck == true)
		{
			screen->Effect(10, 10);
		}

		// Note: 2 컬럼씩 클리핑 
		if (player->GetnX() < 2)  //  왼쪽 클리핑 처리
			screen->ScreenPrint(2, player->GetMoveY(), player->GetPlayer((player->GetnX() - 2)*-1)); // 좌표를 배열 인덱스 
		else if (player->GetMoveX() + (player->GetLength() - player->GetCenterX() + 1) > 43) // 오른쪽 클리핑 처리
		{
			strncat(string, player->GetPlayer(), player->GetLength() - ((player->GetMoveX() + player->GetCenterX() + 1) - 43));
			screen->ScreenPrint(player->GetnX(), player->GetMoveY(), string);
		}
		else { // 1 컬럼씩 이동
			screen->ScreenPrint(player->GetnX(), player->GetMoveY(), player->GetPlayer());
		}
		screen->ScreenPrint(ball->GetMoveX(), ball->GetMoveY(), "⊙");
		break;
	case SUCCESS:
		screen->SuccessScreen();
		break;
	case FAILED:
		screen->FailureScreen();
		break;
	case RESULT:
		screen->ResultScreen(g_nStage);
		break;
	}
}
