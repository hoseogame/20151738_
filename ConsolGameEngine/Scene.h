#ifndef __SCENE_H__
#define __SCENE_H__

#include <time.h>

class Screen;

class Scene
{
private:

protected:
	Screen* screen;

	int	g_nStage;			// 현재스테이지
	int	g_nGrade;			// 점수 
	int	g_nTotalGrade;		// 총점
	int	g_nGoalCount;		// 목표 개수
	int	g_nCount;			// 골인한 개수
	int g_nDeadCount;		// 죽은 개수

	bool g_nGoal;			// 스테이지 완료 변수
	bool g_nCheck;			// 골인이 되었는지 판단

	clock_t StratTime;		// 효과 발생 시각
	clock_t StayTime;		// 효과 지속 시간	

	clock_t g_LimitTime;	//남은시간
	clock_t	g_GameStartTime;
	clock_t	g_UpdateOldTime;

	using GAME_STATE = enum {
		INIT,
		READY,
		RUNNING,
		STOP,
		SUCCESS,
		FAILED,
		RESULT
	};
	GAME_STATE g_GameState;

public:
	Scene();
	virtual ~Scene();

	virtual void Init() = 0;
	virtual bool Input() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};


#endif	//__SCENE_H__