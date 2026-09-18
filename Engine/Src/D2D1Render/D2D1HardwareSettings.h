#ifndef D2D1HARDWARESETTINGS_H
#define D2D1HARDWARESETTINGS_H

#ifdef _WIN32

#include <d2d1.h>

namespace Alphalabs
{
    void D2D1HardwareSettings(
        D2D1_RENDER_TARGET_TYPE Type,
        D2D1_RENDER_TARGET_USAGE Usage,
        D2D1_FEATURE_LEVEL MinLevel = D2D1_FEATURE_LEVEL_DEFAULT
    );
}

#endif

#endif
