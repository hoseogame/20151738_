#ifndef __CONSOL_GAME_ENGINE_H__
#define __CONSOL_GAME_ENGINE_H__

#define GAME_NUM 2

class Scene;

class ConsolGameEngine
{
private:
	int Game;
	Scene* scene[GAME_NUM];
	enum GameList { FOOTBALL, HEART };

public:
	ConsolGameEngine();
	~ConsolGameEngine();

	void Init();
	bool Input();
	void Update();
	void Render();
	void Release();

	void MakeGame();
	bool SelectGame();
	void DeleteGame();

};

#endif	//__CONSOL_GAME_ENGINE_H__