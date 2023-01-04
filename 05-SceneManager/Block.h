#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BLOCK 80000
#define BLOCK_WIDTH 16
#define BLOCK_BBOX_WIDTH 16
#define BLOCK_BBOX_HEIGHT 16

class CBlock : public CGameObject {
	int ani_id;
public:
	CBlock(float x, float y, int ani_id);
	void Render();
	void Update(DWORD dt) {}
	int IsBlocking() { 
		return 1;
	}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};