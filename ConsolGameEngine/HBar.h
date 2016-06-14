#ifndef __HBAR_H__
#define __HBAR_H__

#include <time.h>

#include "Object.h"

class HStage;

class HBar : public Object
{
private:
	int nBarLength;
	int nX[7];

public:
	HBar();
	~HBar();

	void Init(HStage* pStage, int g_nStage);
	bool Update(clock_t CurTime,int nKey);

	int GetX(int idx) { return nX[idx]; }
	int GetBarLength() { return nBarLength; }

	void SetX_P(int idx) { nX[idx] += 1; }
	void SetX_M(int idx) { nX[idx] -= 1; }
};

#endif	//__HBAR_H__