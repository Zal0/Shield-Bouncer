#pragma bank 2
#include "main.h"
UINT8 bank_STATE_SPLASH = 2;

#include "../res/src/splash.h"
#include "../res/src/splashTiles.h"
#include "../res/src/font.h"

#include "Scroll.h"
#include "Keys.h"
#include "ZGBMain.h"

#include "Print.h"

void Start_STATE_SPLASH() {
	InitScrollTiles(0, &splashTiles, bank_splashTiles);
	InitScroll(splashWidth, splashHeight, splash, 0, 0, 3);
	SHOW_BKG;
	HIDE_WIN;

	INIT_FONT(font, PRINT_BKG);
	PRINT(3, 5, "Shield Bouncer");
	PRINT(6, 15, "by Zal0");
	PRINT(4, 16, "2018 zgbjam");
}

extern UINT8 current_level;
void NextLevel();
void Update_STATE_SPLASH() {
	if(keys) {
		current_level = 0;

		current_level--;
		NextLevel();
	}
}