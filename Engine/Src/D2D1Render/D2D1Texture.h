#ifndef D2D1TEXTURE_H
#define D2D1TEXTURE_H

#ifdef _WIN32

#include "D2D1State.h"

namespace Alphalabs
{
    bool D2D1CreateTexture(const char* Path, D2D1Texture& Texture);
    void D2D1ReleaseTexture(D2D1Texture& Texture);
}

#endif

#endif
