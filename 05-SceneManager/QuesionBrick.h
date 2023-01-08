#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"
#include "Coin.h"
#include "PlayScene.h"

#define ID_ANI_QUESTION_BRICK 100000
#define BRICK_WIDTH 16
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16
#define ID_ANI_COIN 11000

class CQuestionBrick : public CGameObject {
	int ani_id;
public:
	CQuestionBrick(float x, float y);
	void ActivateEffect();
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	
};