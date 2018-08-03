#pragma bank 2
#include "main.h"
UINT8 bank_STATE_LEVEL_INTRO = 2;

#include "../res/src/splash.h"
#include "../res/src/splashTiles.h"
#include "../res/src/font.h"

#include "Scroll.h"
#include "Keys.h"
#include "ZGBMain.h"

#include "Print.h"

extern UINT8 current_level;
void Start_STATE_LEVEL_INTRO() {
	InitScrollTiles(0, 256, splashTiles, 3);
	InitScroll(splashWidth, splashHeight, splash, 0, 0, 3);
	SHOW_BKG;
	HIDE_WIN;

	INIT_FONT(font, 3, PRINT_BKG);
	PRINT_POS(5, 5);
	Printf(" Level %d ", (current_level + 1));
}

void Update_STATE_LEVEL_INTRO() {
	if(keys) {
		SetState(STATE_GAME);
	}
}