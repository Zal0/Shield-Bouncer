#pragma bank 2
#include "StateGame.h"
UINT8 bank_STATE_GAME = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\map.h"
#include "..\res\src\map1.h"

typedef struct LevelInfo {
	UINT16 w;
	UINT16 h;
	UINT8* map;
	UINT8 bank;
};

#define LEVEL(A, BANK) A##Width, A##Height, A, BANK
const struct LevelInfo levels[] = {
	{LEVEL(map1,3)},
	{LEVEL(map,3)},

	{0, 0, 0, 0}
};

UINT8 current_level = 0;

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

UINT8 collision_tiles[] = {1, 2, 0};

extern UINT8 n_sprite_types;
void Start_STATE_GAME() {
	UINT8 i;
	const struct LevelInfo* level = &levels[current_level];

	SPRITES_8x16;
	for(i = 0; i != n_sprite_types; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	InitScrollTiles(0, 6, tiles, 3);
	InitScroll(level->w, level->h, level->map, collision_tiles, 0, level->bank);
	SHOW_BKG;
}

void Update_STATE_GAME() {
}

void NextLevel() {
	current_level ++;
	SetState(STATE_GAME);
}