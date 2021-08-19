#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateSplash)\
_STATE(StateGame)\
_STATE(StateWin)\
_STATE(StateLevelIntro)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteBall,     ball)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif