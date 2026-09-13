/*********************

GLES2Renderer.h
Created by Josh Billena

*********************/

#ifndef GLES2_RENDERER_H
#define GLES2_RENDERER_H

#include <GLES2/gl2.h>

namespace Alphalabs
{

// Sets the viewport.
void GLES2Viewport(
    GLint X,
    GLint Y,
    GLsizei Width,
    GLsizei Height
);

// Clears the color buffer using the specified color.
void GLES2ClearScreen(
    GLfloat R,
    GLfloat G,
    GLfloat B,
    GLfloat A
);

// Clears color, stencil, and depth buffers.
void GLES2ClearBuffer();

}

#endif // GLES2_RENDERER_H
