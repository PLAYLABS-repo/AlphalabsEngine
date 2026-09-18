#ifndef D2D1COLOREFFECT_H
#define D2D1COLOREFFECT_H

#ifdef _WIN32

#include "D2D1State.h"

namespace Alphalabs
{
    bool D2D1ColorEffect(
        D2D1Texture& Texture,
        float Red,
        float Green,
        float Blue,
        float Alpha = 1.0f
    );
}

#endif

#endif
