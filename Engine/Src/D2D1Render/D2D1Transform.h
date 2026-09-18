#ifndef D2D1TRANSFORM_H
#define D2D1TRANSFORM_H

#ifdef _WIN32

namespace Alphalabs
{
    void D2D1Transform(
        float X,
        float Y,
        float Rotation,
        float ScaleX,
        float ScaleY,
        float OriginX,
        float OriginY
    );

    void D2D1ResetTransform();
}

#endif

#endif
