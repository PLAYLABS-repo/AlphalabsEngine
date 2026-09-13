#include "GLES2Framebuffer.h"

namespace Alphalabs
{

// Stores the current logical render layer used by the renderer.
static GLint CurrentLayer = 0;

// Creates a framebuffer object.
void GLES2CreateFramebuffer(GLuint& Framebuffer)
{
    // Creates the framebuffer.
    glGenFramebuffers(1, &Framebuffer);
}

// Begins a logical render-order layer.
void GLES2BeginFramebufferLayer(GLint Layer)
{
    // Selects the requested logical layer.
    CurrentLayer = Layer;
}

// Selects a logical render-order layer.
void GLES2Layer(GLint Layer)
{
    // Stores the current logical layer.
    CurrentLayer = Layer;
}

// Checks whether the current framebuffer is complete.
bool GLES2CheckFramebuffer()
{
    // Gets the framebuffer status.
    GLenum Status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

    // Returns true when the framebuffer is complete.
    return Status == GL_FRAMEBUFFER_COMPLETE;
}

// Binds a framebuffer.
void GLES2BindFramebuffer(GLuint Framebuffer)
{
    // Binds the framebuffer.
    glBindFramebuffer(GL_FRAMEBUFFER, Framebuffer);
}

// Binds the default framebuffer.
void GLES2BindDefaultFramebuffer()
{
    // Zero represents the default framebuffer.
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// Attaches a 2D texture as the color attachment of the current framebuffer.
void GLES2AttachTexture(GLuint Texture)
{
    // Attaches the texture to color attachment 0.
    glFramebufferTexture2D(
        GL_FRAMEBUFFER,
        GL_COLOR_ATTACHMENT0,
        GL_TEXTURE_2D,
        Texture,
        0
    );
}

// Creates an 8-bit stencil renderbuffer.
void GLES2CreateStencilBuffer(
    GLuint& StencilBuffer,
    GLsizei Width,
    GLsizei Height
)
{
    // Creates the stencil renderbuffer.
    glGenRenderbuffers(1, &StencilBuffer);

    // Binds the stencil renderbuffer.
    glBindRenderbuffer(GL_RENDERBUFFER, StencilBuffer);

    // Allocates 8 stencil bits per pixel.
    glRenderbufferStorage(
        GL_RENDERBUFFER,
        GL_STENCIL_INDEX8,
        Width,
        Height
    );
}

// Attaches a stencil renderbuffer to the current framebuffer.
void GLES2AttachStencilBuffer(GLuint StencilBuffer)
{
    // Attaches the renderbuffer as the stencil attachment.
    glFramebufferRenderbuffer(
        GL_FRAMEBUFFER,
        GL_STENCIL_ATTACHMENT,
        GL_RENDERBUFFER,
        StencilBuffer
    );
}

}
