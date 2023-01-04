#include "Block.h"

CBlock::CBlock(float x, float y, int ani_id) : CGameObject(x, y) {
	this->ani_id = ani_id;
}

void CBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ani_id)->Render(x, y);
	RenderBoundingBox();
}

void CBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BLOCK_BBOX_WIDTH / 2;
	t = y - BLOCK_BBOX_HEIGHT / 2;
	r = l + BLOCK_BBOX_WIDTH;
	b = t + BLOCK_BBOX_HEIGHT;
}