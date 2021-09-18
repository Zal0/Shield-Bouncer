#include "Banks/SetAutoBank.h"
#include "main.h"

IMPORT_MAP(map);
IMPORT_MAP(map1);
IMPORT_MAP(map2);
IMPORT_MAP(map3);

struct MapInfoBanked {
	UINT8 bank;
	struct MapInfo* map;
};

#define BANKED_MAP(MAP) {BANK(MAP), &MAP}

const struct MapInfoBanked levels[] = {	
	BANKED_MAP(map1),
	BANKED_MAP(map2),
	BANKED_MAP(map),
	BANKED_MAP(map3)
};

UINT8 current_level = 0;

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

#include "Print.h"
IMPORT_TILES(font);

UINT8 collision_tiles[] = {1, 2, 0};

void START() {
	const struct MapInfoBanked* level = &levels[current_level];
	InitScroll(level->bank, level->map, collision_tiles, 0);

	INIT_CONSOLE(font, 3, 2);
}

void UPDATE() {
}

void NextLevel() {
	current_level ++;
	if(levels[current_level].map) {
		SetState(StateLevelIntro);
	} else {
		SetState(StateWin);
	}
}