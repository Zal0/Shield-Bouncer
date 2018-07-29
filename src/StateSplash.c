#pragma bank 2
#include "StateSplash.h"
UINT8 bank_STATE_SPLASH = 2;

#include "../res/src/splash.h"
#include "../res/src/splashTiles.h"
#include "../res/src/font.h"

#include "Scroll.h"
#include "Keys.h"
#include "ZGBMain.h"
#include "StateGame.h"

#include "Print.h"

void Start_STATE_SPLASH() {
	InitScrollTiles(0, 256, splashTiles, 3);
	InitScroll(splashWidth, splashHeight, splash, 0, 0, 3);
	SHOW_BKG;
	HIDE_WIN;

	INIT_FONT(font, 3, PRINT_BKG);
	PRINT(3, 5, "Shield Bouncer");
	PRINT(6, 15, "by Zal0");
	PRINT(4, 16, "2018 zgbjam");
}

extern UINT8 current_level;
void Update_STATE_SPLASH() {
	if(keys) {
		current_level = 0;
#ifndef NDEBUG
		current_level = 3;
#endif

		current_level--;
		NextLevel();
	}
}