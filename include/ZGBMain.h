#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#include "main.h"

#define STATE_DEF_END
#define STATES \
_STATE(STATE_SPLASH) \
_STATE(STATE_GAME) \
_STATE(STATE_WIN) \
_STATE(STATE_LEVEL_INTRO) \
STATE_DEF_END

#define _SPRITE_DMG(SPRITE_ID, DATA, BANK, SIZE, NFRAMES) _SPRITE(SPRITE_ID, DATA, BANK, SIZE, NFRAMES, 0)
#define _SPRITE_COLOR(SPRITE_ID, DATA, BANK, SIZE, NFRAMES) _SPRITE(SPRITE_ID, DATA, BANK, SIZE, NFRAMES, DATA##CGB)
#define _SPRITE(SPRITE_ID, DATA, BANK, SIZE, NFRAMES, PAL_DATA) _SPRITE(SPRITE_ID, DATA, BANK, SIZE, NFRAMES, PAL_DATA)
#define SPRITE_DEF_END
#define SPRITES \
_SPRITE_DMG(SPRITE_PLAYER, player, 3, FRAME_16x16, 9) \
_SPRITE_DMG(SPRITE_BALL, ball, 3, FRAME_8x16, 3) \
SPRITE_DEF_END
#undef _SPRITE



#define _STATE(STATE_ID) STATE_ID,
typedef enum {
	STATES

	N_STATES
} STATE;
#undef _STATE

#define _SPRITE(SPRITE_ID, DATA, BANK, SIZE, NFRAMES, PAL_DATA) SPRITE_ID,
typedef enum {
	SPRITES

	N_SPRITE_TYPES
} SPRITE_TYPE;
#undef _SPRITE

#endif