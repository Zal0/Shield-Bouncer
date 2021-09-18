#include "Banks/SetAutoBank.h"
#include "main.h"

IMPORT_MAP(splash);
IMPORT_TILES(font);

#include "Scroll.h"
#include "ZGBMain.h"
#include "Print.h"
#include "Keys.h"

void START() {
	InitScroll(BANK(splash), &splash, 0, 0);

	INIT_FONT(font, PRINT_BKG);
	PRINT(1, 5, "CONGRATULATIONS!!!");
}

void UPDATE() {
	if(keys) {
		SetState(StateSplash);
	}
}