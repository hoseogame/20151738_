#include <iostream>

#include "ConsolGameEngine.h"
#include "Scene.h"

#include "FootBall.h"
#include "Heart.h"

ConsolGameEngine::ConsolGameEngine()
{
	Game = -1;
	for (int i = 0; i < GAME_NUM; i++)
	{
		scene[i] = NULL;
	}
}

ConsolGameEngine::~ConsolGameEngine()
{

}


void ConsolGameEngine::Init()
{
	scene[Game]->Init();
}

bool ConsolGameEngine::Input()
{
	return scene[Game]->Input();
}

void ConsolGameEngine::Update()
{
	scene[Game]->Update();
}

void ConsolGameEngine::Render()
{
	scene[Game]->Render();
}

void ConsolGameEngine::Release()
{
	scene[Game]->Release();
}



void ConsolGameEngine::MakeGame()
{
	scene[FOOTBALL] = new FootBall;
	scene[HEART] = new Heart;
}

bool ConsolGameEngine::SelectGame()
{
	bool check = true;
	while (check)
	{
		std::cout << "게임을 선택해 주세요. \nFootBall = 1 / Heart = 2 / 종료 = 0: ";
		std::cin >> Game;
		if (Game < 0 || Game > GAME_NUM)
		{
			std::cout << "다시입력하시오" << std::endl;
		}
		else check = false;
	}
	system("cls");
	if (Game != 0) { Game -= 1; }
	else return false;

	return true;
}

void ConsolGameEngine::DeleteGame()
{
	for (int i = 0; i < GAME_NUM; i++)
	{
		delete scene[i];
		scene[i] = NULL;
	}
}