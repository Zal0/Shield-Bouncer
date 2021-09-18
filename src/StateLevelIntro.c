#include "Banks/SetAutoBank.h"
#include "main.h"

IMPORT_MAP(splash);
IMPORT_TILES(font);

#include "Scroll.h"
#include "Keys.h"
#include "ZGBMain.h"

#include "Print.h"

extern UINT8 current_level;
void START() {
	InitScroll(BANK(splash), &splash, 0, 0);

	INIT_FONT(font, PRINT_BKG);
	PRINT_POS(5, 5);
	Printf(" Level %d ", (current_level + 1));
}

void UPDATE() {
	if(keys) {
		SetState(StateGame);
	}
}