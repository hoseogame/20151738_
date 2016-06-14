#ifndef __OBJECT_H__
#define __OBJECT_H__

#define BOUNDARY_MIN 2
#define BOUNDARY_MAX 43

#include <time.h>
class HStage;

class Object
{
protected:
	int nMoveX, nMoveY;
	clock_t	MoveTime;
	clock_t	OldTime;

public:
	Object();
	virtual ~Object();

	virtual void Init();
	virtual void Init(HStage* pStage, int g_nStage){}

	int GetMoveX() { return nMoveX; }
	int GetMoveY() { return nMoveY; }
	clock_t GetOldTime() { return OldTime; }
	clock_t GetMoveTime() { return MoveTime; }

	virtual void SetMoveX_P() { }
	virtual void SetMoveX_M() { }
	int& SetMoveX() { return nMoveX; }
	int& SetMoveY() { return nMoveY; }
	clock_t& SetOldTime() { return OldTime; }
};

#endif	//__OBJECT_H__