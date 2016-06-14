#ifndef __HHEART_H__
#define __HHEART_H__

#include <time.h>
#include "Object.h"

class HBasket;
class HBar;

class HHeart : public Object
{
private:
	int nLife;				// 생명
	int nDist;				// 이동거리

public:
	HHeart();
	~HHeart();

	bool Update(HHeart*	g_sHeart, HBasket* g_sBasket, HBar*	g_Bar,
		clock_t CurTime, int& HeartDownCount, int& HeartCount,
		int& g_nGrade, int& g_nDeadHeartCount, int nLength, bool& time);

	int GetLife() { return nLife; }
};

#endif	//__HHEART_H__