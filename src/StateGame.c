#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\map.h"
#include "..\res\src\map1.h"
#include "..\res\src\map2.h"
#include "..\res\src\map3.h"

typedef struct LevelInfo {
	UINT16 w;
	UINT16 h;
	struct MapInfo* map;
};

#define LEVEL(A) A##Width, A##Height, &A
const struct LevelInfo levels[] = {
	{LEVEL(map1)},
	{LEVEL(map2)},
	{LEVEL(map)},
	{LEVEL(map3)},

	{0, 0, 0}
};

UINT8 current_level = 0;

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

#include "Print.h"
#include "../res/src/font.h"

UINT8 collision_tiles[] = {1, 2, 0};

void Start_STATE_GAME() {
	UINT8 i;
	const struct LevelInfo* level = &levels[current_level];

	SPRITES_8x16;
	for(i = 0; i != N_SPRITE_TYPES; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	InitScrollTiles(0, &tiles);
	InitScroll(level->map, collision_tiles, 0);
	SHOW_BKG;

	INIT_CONSOLE(font, 3, 2);
}

void Update_STATE_GAME() {
}

void NextLevel() {
	current_level ++;
	if(levels[current_level].map) {
		SetState(STATE_LEVEL_INTRO);
	} else {
		SetState(STATE_WIN);
	}
}