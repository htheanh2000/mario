#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_BACKGROUND 60000

#define	COIN_WIDTH 10
#define COIN_BBOX_WIDTH 10
#define COIN_BBOX_HEIGHT 16

class CBackground : public CGameObject {
	int state;
public:
	CBackground(float x, float y, float id) : CGameObject(x, y) {
		state = id;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};