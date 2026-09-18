#ifndef D2D1RENDER_H
#define D2D1RENDER_H

#ifdef _WIN32

#include "D2D1State.h"

namespace Alphalabs
{
    bool D2D1Render(
        const D2D1Texture& Texture,
        float X,
        float Y,
        float Width,
        float Height,
        float Opacity = 1.0f
    );
}

#endif

#endif
