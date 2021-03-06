#pragma bank 2
#include "main.h"
UINT8 bank_STATE_WIN = 2;

#include "../res/src/splash.h"
#include "../res/src/splashTiles.h"
#include "../res/src/font.h"

#include "Scroll.h"
#include "ZGBMain.h"
#include "Print.h"
#include "Keys.h"

void Start_STATE_WIN() {
	InitScrollTiles(0, &splashTiles);
	InitScroll(&splash, 0, 0);
	SHOW_BKG;
	HIDE_WIN;

	INIT_FONT(font, PRINT_BKG);
	PRINT(1, 5, "CONGRATULATIONS!!!");
}

void Update_STATE_WIN() {
	if(keys) {
		SetState(STATE_SPLASH);
	}
}