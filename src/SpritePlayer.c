#pragma bank 2
#include "SpritePlayer.h"
UINT8 bank_SPRITE_PLAYER = 2;

#include "Keys.h"
#include "SpriteManager.h"
#include "Scroll.h"

void Start_SPRITE_PLAYER() {
}

INT8 angle_idx;
const INT8 angle_matrix[] = {
	-1, 0, 1, 
	-2, 0, 2, 
	-3, 4, 3
};

void Translate(INT8 translate, INT8 x, INT8 y) {
	if(translate) {
		TranslateSprite(THIS, x, y);
	}
}

void Update_SPRITE_PLAYER() {
	INT8 angle;
	INT8 translate = 1;

	if(keys) {
		angle_idx = 4;
		translate = !KEY_PRESSED(J_A);

		if(KEY_PRESSED(J_UP)) {
			angle_idx -= 3;
			Translate(translate, 0, -1);
		} 
		if(KEY_PRESSED(J_DOWN)) {
			angle_idx += 3;
			Translate(translate, 0, 1);
		}
		if(KEY_PRESSED(J_LEFT)) {
			angle_idx --;
			Translate(translate, -1, 0);
		}
		if(KEY_PRESSED(J_RIGHT)) {
			angle_idx ++;
			Translate(translate,  1, 0);
		}

		angle = angle_matrix[angle_idx];
		if(angle < 0) {
			SPRITE_SET_VMIRROR(THIS);
			angle = -angle;
		} else {
			SPRITE_UNSET_VMIRROR(THIS);
		}

		THIS->current_frame = angle;
	}
}

void Destroy_SPRITE_PLAYER() {
	scroll_target = 0;
}