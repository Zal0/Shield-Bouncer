#pragma bank 2
#include "StateSplash.h"
UINT8 bank_STATE_SPLASH = 2;

#include "../res/src/splash.h"
#include "../res/src/splashTiles.h"

#include "Scroll.h"
#include "Keys.h"
#include "ZGBMain.h"
#include "StateGame.h"

void Start_STATE_SPLASH() {
	InitScrollTiles(0, 256, splashTiles, 3);
	InitScroll(splashWidth, splashHeight, splash, 0, 0, 3);
	SHOW_BKG;
	HIDE_WIN;
}

void Update_STATE_SPLASH() {
	if(keys) {
		NextLevel();
	}
}