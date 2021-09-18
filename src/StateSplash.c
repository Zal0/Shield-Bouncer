#include "Banks/SetAutoBank.h"
#include "main.h"

IMPORT_MAP(splash);
IMPORT_TILES(font);

#include "Scroll.h"
#include "Keys.h"
#include "ZGBMain.h"

#include "Print.h"

void START() {
	InitScroll(BANK(splash), &splash, 0, 0);

	INIT_FONT(font, PRINT_BKG);
	PRINT(3, 5, "Shield Bouncer");
	PRINT(6, 15, "by Zal0");
	PRINT(4, 16, "2018 zgbjam");
}

extern UINT8 current_level;
void NextLevel();
void UPDATE() {
	if(keys) {
		current_level = 0;

		current_level--;
		NextLevel();
	}
}