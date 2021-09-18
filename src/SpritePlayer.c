#include "Banks/SetAutoBank.h"
#include "main.h"

#include "Keys.h"
#include "SpriteManager.h"
#include "Scroll.h"
#include "ZGBMain.h"

void START() {
	scroll_target = THIS;
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

void UPDATE() {
	INT8 angle;
	INT8 translate = 1;
	
	if(scroll_target) {
		if(0xF & keys) {
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
				THIS->mirror = V_MIRROR;
				angle = -angle;
			} else {
				THIS->mirror = NO_MIRROR;
			}

			SetFrame(THIS, angle); 
		}
	} else {
		if(THIS->anim_frame == 9) {
			SpriteManagerRemoveSprite(THIS);
			SetState(StateGame);
		}
	}
}

const UINT8 anim_dying[] = {10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 8};
void KillPlayer() {
	SetSpriteAnim(scroll_target, anim_dying, 15);
	scroll_target = 0;
}

void DESTROY() {
}