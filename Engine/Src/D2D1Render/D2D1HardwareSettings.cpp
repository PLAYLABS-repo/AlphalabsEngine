#include "D2D1HardwareSettings.h"
#include "D2D1State.h"

#ifdef _WIN32

namespace Alphalabs
{
    void D2D1HardwareSettings(
        D2D1_RENDER_TARGET_TYPE Type,
        D2D1_RENDER_TARGET_USAGE Usage,
        D2D1_FEATURE_LEVEL MinLevel
    )
    {
        D2DRenderTargetProperties.type = Type;
        D2DRenderTargetProperties.usage = Usage;
        D2DRenderTargetProperties.minLevel = MinLevel;
    }
}

#endif
