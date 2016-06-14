#ifndef __FPLAYER_H__
#define __FPLAYER_H__

#include "Object.h"

class FPlayer : public Object
{
private:
	int nX;
	int nCenterX;

	int g_nLength;
	char g_strPlayer[11] = "¦±¦¬¡Ü¦¬¦°";

public:
	FPlayer();
	virtual ~FPlayer();

	virtual void Init();
	bool Update(int key,int* nRemain);

	int GetnX() { return nX; }
	int GetLength() { return g_nLength; }
	int GetCenterX() { return nCenterX; }
	char* GetPlayer() { return g_strPlayer; }
	char* GetPlayer(int x) { return &(g_strPlayer[x]); }

	void SetnX() { nX = nMoveX - nCenterX; }
	void SetMoveX_P() { nMoveX += 1; }
	void SetMoveX_M() { nMoveX -= 1; }
};

#endif	//__FPLAYER_H__
