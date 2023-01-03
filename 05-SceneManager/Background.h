#pragma once
#include "GameObject.h"

#define Background_GRAVITY 0.002f
#define Background_WALKING_SPEED 0.05f


#define Background_BBOX_WIDTH 16
#define Background_BBOX_HEIGHT 14
#define Background_BBOX_HEIGHT_DIE 7

#define Background_DIE_TIMEOUT 500

#define Background_STATE_WALKING 100
#define Background_STATE_DIE 200

#define ID_ANI_Background_WALKING 5000
#define ID_ANI_Background_DIE 5001

class CBackground : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CBackground(float x, float y);
	virtual void SetState(int state);
};