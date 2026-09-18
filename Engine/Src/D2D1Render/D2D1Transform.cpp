#include "D2D1Transform.h"
#include "D2D1State.h"

#include <cmath>

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
    )
    {
        if (!D2DRenderTarget)
        {
            return;
        }

        const float Pi =
            3.14159265358979323846f;

        const float Radians =
            Rotation * Pi / 180.0f;

        const float Cosine =
            std::cos(Radians);

        const float Sine =
            std::sin(Radians);

        D2D1_MATRIX_3X2_F Matrix =
        {
            Cosine * ScaleX,
            Sine * ScaleX,
            -Sine * ScaleY,
            Cosine * ScaleY,
            X - (OriginX * Cosine * ScaleX) + (OriginY * Sine * ScaleY),
            Y - (OriginX * Sine * ScaleX) - (OriginY * Cosine * ScaleY)
        };

        D2DRenderTarget->SetTransform(
            &Matrix
        );
    }

    void D2D1ResetTransform()
    {
        if (!D2DRenderTarget)
        {
            return;
        }

        D2D1_MATRIX_3X2_F Matrix =
        {
            1.0f,
            0.0f,
            0.0f,
            1.0f,
            0.0f,
            0.0f
        };

        D2DRenderTarget->SetTransform(
            &Matrix
        );
    }
}

#endif
