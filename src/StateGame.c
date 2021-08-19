#include "Banks/SetBank2.h"
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

void Start_StateGame() {
	UINT8 i;
	const struct MapInfoBanked* level = &levels[current_level];

	SPRITES_8x16;
	for(i = 0; i != N_SPRITE_TYPES; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	InitScroll(level->bank, level->map, collision_tiles, 0);
	SHOW_BKG;

	INIT_CONSOLE(font, 3, 2);
}

void Update_StateGame() {
}

void NextLevel() {
	current_level ++;
	if(levels[current_level].map) {
		SetState(StateLevelIntro);
	} else {
		SetState(StateWin);
	}
}