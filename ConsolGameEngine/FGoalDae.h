#ifndef __FGOALDAE_H__
#define __FGOALDAE_H__

#include <time.h>

#include "Object.h"

class FGoalDae : public Object
{
private:
	int nLength;			// ∞Ò¥Î ±Ê¿Ã	
	int nLineX[7];			// ∞Ò¿Œ ∂Û¿Œ x ¡¬«• (7∞≥)
	int	nDist;				// ¿Ãµø ∞≈∏Æ
	
public:
	FGoalDae();
	virtual ~FGoalDae();

	void Init(int x, int y, int len, int time, int dist);
	bool Update(clock_t CurTime, int length);

	int GetLength() { return nLength; }
	int GetDist() { return nDist; }
	int GetLineX(int idx) { return nLineX[idx]; }

	void SetMoveX_P() { nMoveX += nDist; };
	void SetDist_Reverse() { nDist = nDist * -1; }
	void SetLineX_idx(int idx) { nLineX[idx] = nMoveX + 2 * (idx + 1); }

};

#endif // __FGOALDAE_H__
