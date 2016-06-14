#ifndef __SCENE_H__
#define __SCENE_H__

#include <time.h>

class Screen;

class Scene
{
private:

protected:
	Screen* screen;

	int	g_nStage;			// ���罺������
	int	g_nGrade;			// ���� 
	int	g_nTotalGrade;		// ����
	int	g_nGoalCount;		// ��ǥ ����
	int	g_nCount;			// ������ ����
	int g_nDeadCount;		// ���� ����

	bool g_nGoal;			// �������� �Ϸ� ����
	bool g_nCheck;			// ������ �Ǿ����� �Ǵ�

	clock_t StratTime;		// ȿ�� �߻� �ð�
	clock_t StayTime;		// ȿ�� ���� �ð�	

	clock_t g_LimitTime;	//�����ð�
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