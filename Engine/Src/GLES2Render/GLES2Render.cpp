#include "GLES2Render.h"

namespace Alphalabs
{

// Draws non-indexed geometry.
void GLES2DrawType(
    GLenum Type,
    GLint First,
    GLsizei Vertices
)
{
    // Draws the requested vertices.
    glDrawArrays(Type, First, Vertices);
}

// Draws indexed geometry.
void GLES2DrawIndexed(
    GLenum Type,
    GLsizei Count,
    GLenum IndexType,
    const void* Indices
)
{
    // Draws using the currently bound index buffer.
    glDrawElements(Type, Count, IndexType, Indices);
}

// Enables or disables face culling.
void GLES2SetCullFace(GLboolean Enabled)
{
    // Enables face culling when requested.
    if (Enabled)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);
}

// Sets the blend source and destination factors.
void GLES2SetBlendFunction(
    GLenum Source,
    GLenum Destination
)
{
    // Sets the blending factors.
    glBlendFunc(Source, Destination);
}

// Enables or disables depth testing.
void GLES2SetDepthTest(GLboolean Enabled)
{
    // Enables depth testing when requested.
    if (Enabled)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
}

}
