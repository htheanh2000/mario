#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI 90000
#define WIDTH 16
#define BBOX_WIDTH 16
#define BBOX_HEIGHT 16

class CPipe : public CGameObject {
	int ani_id;
public:
	CPipe(float x, float y, int ani_id);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
};