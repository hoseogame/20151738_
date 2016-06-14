#ifndef __HBASKET_H__
#define __HBASKET_H__

#include <time.h>
#include "Object.h"

class HStage;
class HBar;

class HBasket :public Object
{
private:
	int nDist;
	clock_t OldDownHeartTime;
	clock_t DownHeartTime;

public:
	HBasket();
	~HBasket();

	void Init(HStage* pStage, int g_nStage);
	bool Updata(clock_t CurTime, int g_nHeartDownCount, int nHeartCount);


	clock_t GetDownHeartTime() { return DownHeartTime; }
	void SetX_Dist() { nMoveX += nDist; }

};

#endif	//__HBASKET_H__