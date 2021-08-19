#include "Banks/SetBank2.h"
#include "main.h"

IMPORT_MAP(splash);
IMPORT_TILES(font);

#include "Scroll.h"
#include "Keys.h"
#include "ZGBMain.h"

#include "Print.h"

void Start_StateSplash() {
	InitScroll(BANK(splash), &splash, 0, 0);
	SHOW_BKG;
	HIDE_WIN;

	INIT_FONT(font, PRINT_BKG);
	PRINT(3, 5, "Shield Bouncer");
	PRINT(6, 15, "by Zal0");
	PRINT(4, 16, "2018 zgbjam");
}

extern UINT8 current_level;
void NextLevel();
void Update_StateSplash() {
	if(keys) {
		current_level = 0;

		current_level--;
		NextLevel();
	}
}