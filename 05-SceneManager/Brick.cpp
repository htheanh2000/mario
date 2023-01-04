#include "Brick.h"


CBrick::CBrick(float x, float y, int ani_id) : CGameObject(x, y) {
	this->ani_id = ani_id;
}


void CBrick::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ani_id)->Render(x, y);
	//RenderBoundingBox();
}

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x - BRICK_BBOX_WIDTH/2;
	t = y - BRICK_BBOX_HEIGHT/2;
	r = l + BRICK_BBOX_WIDTH;
	b = t + BRICK_BBOX_HEIGHT;
}