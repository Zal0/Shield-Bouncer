#pragma bank 1
#include "ZGBMain.h"
UINT8 init_bank = 1;
UINT8 next_state = STATE_SPLASH;

#define _STATE(STATE_ID) DECLARE_STATE(STATE_ID);
STATES
#undef _STATE

UINT8 stateBanks[N_STATES];

#define _STATE(STATE_ID) Start_##STATE_ID,
Void_Func_Void startFuncs[] = {STATES};
#undef _STATE

#define _STATE(STATE_ID) Update_##STATE_ID,
Void_Func_Void updateFuncs[] = {STATES};
#undef _STATE

#define _STATE(STATE_ID) stateBanks[STATE_ID] = bank_##STATE_ID;
void InitStates() {
	STATES
}
#undef _STATE

#define _SPRITE(SPRITE_ID, DATA, BANK, SIZE, NFRAMES, PAL_DATA) DECLARE_SPRITE(SPRITE_ID);
SPRITES
#undef _SPRITE

#define _SPRITE(SPRITE_ID, DATA, BANK, SIZE, NFRAMES, PAL_DATA) extern unsigned char DATA[];
SPRITES
#undef _SPRITE

SET_N_SPRITE_TYPES(N_SPRITE_TYPES);

#define _SPRITE(SPRITE_ID, DATA, BANK, SIZE, NFRAMES, PAL_DATA) InitSpriteInfo(SPRITE_ID, bank_##SPRITE_ID, Start_##SPRITE_ID, Update_##SPRITE_ID, Destroy_##SPRITE_ID, DATA, BANK, SIZE, NFRAMES, PAL_DATA);
void InitSprites() {
	SPRITES
}
#undef _SPRITE