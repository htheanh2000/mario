#include "Background.h"

CBackground::CBackground(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = Background_GRAVITY;
	die_start = -1;
	SetState(Background_STATE_WALKING);
}

void CBackground::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == Background_STATE_DIE)
	{
		left = x - Background_BBOX_WIDTH / 2;
		top = y - Background_BBOX_HEIGHT_DIE / 2;
		right = left + Background_BBOX_WIDTH;
		bottom = top + Background_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - Background_BBOX_WIDTH / 2;
		top = y - Background_BBOX_HEIGHT / 2;
		right = left + Background_BBOX_WIDTH;
		bottom = top + Background_BBOX_HEIGHT;
	}
}

void CBackground::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CBackground::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CBackground*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CBackground::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;

	if ((state == Background_STATE_DIE) && (GetTickCount64() - die_start > Background_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CBackground::Render()
{
	int aniId = ID_ANI_Background_WALKING;
	if (state == Background_STATE_DIE)
	{
		aniId = ID_ANI_Background_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CBackground::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case Background_STATE_DIE:
		die_start = GetTickCount64();
		y += (Background_BBOX_HEIGHT - Background_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case Background_STATE_WALKING:
		vx = 0;
		break;
	}
}
