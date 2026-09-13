#include "GLES2Renderer.h"

namespace Alphalabs
{

// Sets the viewport.
void GLES2Viewport(
    GLint X,
    GLint Y,
    GLsizei Width,
    GLsizei Height
)
{
    // Sets the viewport rectangle.
    glViewport(X, Y, Width, Height);
}

// Clears the color buffer using the specified color.
void GLES2ClearScreen(
    GLfloat R,
    GLfloat G,
    GLfloat B,
    GLfloat A
)
{
    // Sets the clear color.
    glClearColor(R, G, B, A);

    // Clears the color buffer.
    glClear(GL_COLOR_BUFFER_BIT);
}

// Clears color, stencil, and depth buffers.
void GLES2ClearBuffer()
{
    // Clears all three buffers.
    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_STENCIL_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );
}

}
