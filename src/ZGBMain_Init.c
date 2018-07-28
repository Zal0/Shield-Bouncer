#pragma bank 1
#include "ZGBMain.h"
UINT8 init_bank = 1;


#include "StateGame.h"

#include "SpritePlayer.h"
#include "SpriteBall.h"

#include "../res/src/player.h"
#include "../res/src/ball.h"

UINT8 next_state = STATE_GAME;

SET_N_STATES(N_STATES);
SET_N_SPRITE_TYPES(N_SPRITE_TYPES);

void InitStates() {
	INIT_STATE(STATE_GAME);
}

void InitSprites() {
	INIT_SPRITE(SPRITE_PLAYER, player, 3, FRAME_16x16, 5);
	INIT_SPRITE(SPRITE_BALL, ball, 3, FRAME_8x16, 1);
}