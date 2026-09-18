#include "D2D1Transform.h"
#include "D2D1State.h"

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

        D2D1_POINT_2F Origin = D2D1::Point2F(OriginX, OriginY);

        D2D1::Matrix3x2F Transform =
            D2D1::Matrix3x2F::Scale(ScaleX, ScaleY, Origin) *
            D2D1::Matrix3x2F::Rotation(Rotation, Origin) *
            D2D1::Matrix3x2F::Translation(X, Y);

        D2DRenderTarget->SetTransform(Transform);
    }

    void D2D1ResetTransform()
    {
        if (!D2DRenderTarget)
        {
            return;
        }

        D2DRenderTarget->SetTransform(
            D2D1::Matrix3x2F::Identity()
        );
    }
}

#endif
