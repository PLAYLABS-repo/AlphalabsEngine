/*********************

GLES2Render.h
Created by Josh Billena

*********************/

#ifndef GLES2_RENDER_H
#define GLES2_RENDER_H

#include <GLES2/gl2.h>

namespace Alphalabs
{

// Draws non-indexed geometry.
void GLES2DrawType(
    GLenum Type,
    GLint First,
    GLsizei Vertices
);

// Draws indexed geometry.
void GLES2DrawIndexed(
    GLenum Type,
    GLsizei Count,
    GLenum IndexType,
    const void* Indices
);

// Enables or disables face culling.
void GLES2SetCullFace(GLboolean Enabled);

// Sets the blend source and destination factors.
void GLES2SetBlendFunction(
    GLenum Source,
    GLenum Destination
);

// Enables or disables depth testing.
void GLES2SetDepthTest(GLboolean Enabled);

}

#endif // GLES2_RENDER_H
