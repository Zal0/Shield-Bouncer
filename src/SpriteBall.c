#pragma bank 2
#include "SpriteBall.h"
UINT8 bank_SPRITE_BALL = 2;

#include "Keys.h"
#include "SpriteManager.h"
#include "Scroll.h"
#include "Trig.h"
#include "Math.h"

const UINT8 anglesByIdx[] = {
	224, 192,  160,
	  0,   0,  128,
	 32,  64,   96,
};

struct BallInfo {
	INT8 angle, speed;
	fixed x,y;
};

void Start_SPRITE_BALL() {
	struct BallInfo* data = (struct BallInfo*)THIS->custom_data;
	data->angle = 16;
	data->speed = 5;

	THIS->coll_y += 8;
	THIS->coll_h -= 8;
}

UINT8 CheckCollisionWithCollider(struct Sprite* sprite1, UINT8 coll_x, UINT8 coll_y, UINT8 coll_w, UINT8 coll_h, 
	                   struct Sprite* sprite2) {
	if( (sprite1->x + coll_x + coll_w < sprite2->x + sprite2->coll_x) ||
	    (sprite2->x + sprite2->coll_x + sprite2->coll_w < sprite1->x + coll_x) ||
			(sprite1->y + coll_y + coll_h < sprite2->y + sprite2->coll_y) ||
			(sprite2->y + sprite2->coll_y + sprite2->coll_h < sprite1->y + coll_y)
	) {
		return 0;
	} else {
		return 1;
	}
}

extern INT8 angle_idx;
void Update_SPRITE_BALL() {
	INT8 inc_x = 0;
	INT8 inc_y = 0;
	INT8 desp;
	INT16 cached_x, cached_y;
	struct BallInfo* data = (struct BallInfo*)THIS->custom_data;
	
	desp = -4 + data->speed + delta_time;
	if(desp < 0) {
		desp = -desp;
		data->x.w += COS(data->angle) >> desp;
		data->y.w += SIN(data->angle) >> desp;
	} else {
		data->x.w += COS(data->angle) << desp;
		data->y.w += SIN(data->angle) << desp;
	}

	if(data->x.b.h > 0) {
		inc_x = data->x.b.h;
		data->x.b.h = 0;
	}
	if(data->y.b.h > 0) {
		inc_y = data->y.b.h;
		data->y.b.h = 0;
	}

	cached_x = THIS->x + inc_x; 
	cached_y = THIS->y + inc_y; 
	if(TranslateSprite(THIS, inc_x, inc_y)) {
		if(THIS->x != cached_x) {
			data->angle = 128 - data->angle;
		}
		if(THIS->y != cached_y) {
			data->angle = -data->angle;
		}
	}

	if(CheckCollision(THIS, scroll_target)) {
		data->angle = anglesByIdx[angle_idx];
		if(scroll_target && CheckCollisionWithCollider(scroll_target, 6, 6, 4, 4, THIS)) {
			SpriteManagerRemoveSprite(scroll_target);
		}
	}
}

void Destroy_SPRITE_BALL() {
}