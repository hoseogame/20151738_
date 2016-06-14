#include <iostream>

#include "Scene.h"

Scene::Scene()
{
	screen = NULL;

	g_nStage = -1;
	g_nGrade = 0;				// Á¡¼ö 
	g_nTotalGrade = 0;			// ÃÑÁ¡
	g_nGoalCount = 0;
	g_nCount = 0;
	g_nDeadCount = 0;		// Á×Àº ÇÏÆ® °³¼ö

	g_nGoal = false;
	g_nCheck = false;

	g_GameState = INIT;
}

Scene::~Scene()
{

}