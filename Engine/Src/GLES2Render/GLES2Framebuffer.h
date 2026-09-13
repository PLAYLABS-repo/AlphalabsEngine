/*********************

GLES2Framebuffer.h
Created by Josh Billena

*********************/

#ifndef GLES2_FRAMEBUFFER_H
#define GLES2_FRAMEBUFFER_H

#include <GLES2/gl2.h>

namespace Alphalabs
{

// Creates a framebuffer object.
void GLES2CreateFramebuffer(GLuint& Framebuffer);

// Begins a logical render-order layer.
void GLES2BeginFramebufferLayer(GLint Layer);

// Selects a logical render-order layer.
void GLES2Layer(GLint Layer);

// Checks whether the current framebuffer is complete.
bool GLES2CheckFramebuffer();

// Binds a framebuffer.
void GLES2BindFramebuffer(GLuint Framebuffer);

// Binds the default framebuffer.
void GLES2BindDefaultFramebuffer();

// Creates an 8-bit stencil renderbuffer.
void GLES2CreateStencilBuffer(
    GLuint& StencilBuffer,
    GLsizei Width,
    GLsizei Height
);

// Attaches a stencil renderbuffer to the current framebuffer.
void GLES2AttachStencilBuffer(GLuint StencilBuffer);

// Attaches a 2D texture as the color attachment of the current framebuffer.
void GLES2AttachTexture(GLuint Texture);

}

#endif // GLES2_FRAMEBUFFER_H
