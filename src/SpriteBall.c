#include "Banks/SetBank2.h"
#include "main.h"

#include "Keys.h"
#include "SpriteManager.h"
#include "Scroll.h"
#include "Trig.h"
#include "Math.h"
#include "ZGBMain.h"

const UINT8 anim_fall[] = {3, 1, 2, 2};

const UINT8 anglesByIdx[] = {
	  160, 192, 224,
	  128,   0,	  0,
	   96,  64,	 32,
};

const UINT8 player_angles[] = {
	  32,  64,  96,
	   0,   0, 128,
	 224,	192, 160,
};

struct BallInfo {
	INT8 moving;
	UINT8 angle; 
	INT8 speed;
	fixed x,y;
};

UINT8 Angle(UINT8 angle_1, UINT8 angle_2) {
	UINT8 ret_1 = angle_2 - angle_1;
	UINT8 ret_2 = -angle_2 + angle_1;

	return ret_1 < ret_2 ? ret_1 : ret_2;
}

#include "Print.h"
void Start_SpriteBall() {
	struct BallInfo* data = (struct BallInfo*)THIS->custom_data;
	data->moving = 0;
	data->angle = 16;
	data->speed = 5;
	data->x.w = 0;
	data->y.w = 0;

	THIS->lim_x = 1024;
	THIS->lim_y = 1024;
}

UINT8 CheckCollisionWithCollider(struct Sprite* sprite1, UINT8 coll_x, UINT8 coll_y, UINT8 coll_w, UINT8 coll_h, 
	                   struct Sprite* sprite2) {
	if( (sprite1->x + coll_x + coll_w < sprite2->x) ||
	    (sprite2->x + sprite2->coll_w < sprite1->x + coll_x) ||
			(sprite1->y + coll_y + coll_h < sprite2->y ) ||
			(sprite2->y + sprite2->coll_h < sprite1->y + coll_y)
	) {
		return 0;
	} else {
		return 1;
	}
}

extern INT8 angle_idx;
void KillPlayer();
void NextLevel();
void Update_SpriteBall() {
	INT8 inc_x = 0;
	INT8 inc_y = 0;
	INT8 desp;
	INT16 cached_x, cached_y;
	struct BallInfo* data = (struct BallInfo*)THIS->custom_data;

	if(THIS->anim_data) {
		if(THIS->anim_frame == 2) {
			SpriteManagerRemoveSprite(THIS);
			NextLevel();
		}
	} else {
		if(data->moving) {
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

		if(GetScrollTile((THIS->x + 4) >> 3, (THIS->y + 4) >> 3) == 3) {
			THIS->x = (((THIS->x + 4) >> 3) << 3) + 4 - 4;
			THIS->y = (((THIS->y + 4) >> 3) << 3) + 4 - 4;
			SetSpriteAnim(THIS, anim_fall, 8);
			return;
		}

		if(CheckCollision(THIS, scroll_target)) {
			//if(data->moving && scroll_target && Angle(data->angle, player_angles[angle_idx]) > 65) {
			//	KillPlayer();
			//} else {
				data->angle = anglesByIdx[angle_idx];
				TranslateSprite(scroll_target, COS(data->angle + 128) >> 6, SIN(data->angle + 128) >> 6);
			//}

			data->moving = 1;
		}
	}
}

void Destroy_SpriteBall() {
}