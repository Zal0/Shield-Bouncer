#pragma bank 2
#include "StateWin.h"
UINT8 bank_STATE_WIN = 2;

#include "../res/src/splash.h"
#include "../res/src/splashTiles.h"
#include "../res/src/font.h"

#include "Scroll.h"

#include "Print.h"

void Start_STATE_WIN() {
	InitScrollTiles(0, 256, splashTiles, 3);
	InitScroll(splashWidth, splashHeight, splash, 0, 0, 3);
	SHOW_BKG;
	HIDE_WIN;

	INIT_FONT(font, 3, PRINT_BKG);
	PRINT(1, 5, "CONGRATULATIONS!!!");
}

void Update_STATE_WIN() {
}