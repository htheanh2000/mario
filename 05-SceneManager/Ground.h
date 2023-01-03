#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_GROUND 70000
#define GROUND_WIDTH 256
#define GROUND_BBOX_WIDTH 256
#define GROUND_BBOX_HEIGHT 36

class CGround : public CGameObject {
public:
	CGround(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);


	class Ground
	{
	};
};