#pragma bank 2
#include "SpriteBall.h"
UINT8 bank_SPRITE_BALL = 2;

#include "Keys.h"
#include "SpriteManager.h"

struct BallInfo {
	INT8 vx, vy;
	fixed x,y;
};

void Start_SPRITE_BALL() {
	struct BallInfo* data = (struct BallInfo*)THIS->custom_data;
	data->vx = -32;
	data->vy = 4;

	THIS->coll_y += 8;
	THIS->coll_h -= 8;
}

void Update_SPRITE_BALL() {
	INT8 inc_x = 0;
	INT8 inc_y = 0;
	INT16 cached_x, cached_y;
	struct BallInfo* data = (struct BallInfo*)THIS->custom_data;
	
	data->x.w += data->vx << 4 << delta_time;
	data->y.w += data->vy << 4 << delta_time;
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
			data->vx = -data->vx;
		}
		if(THIS->y != cached_y) {
			data->vy = -data->vy;
		}
	}
}

void Destroy_SPRITE_BALL() {
}