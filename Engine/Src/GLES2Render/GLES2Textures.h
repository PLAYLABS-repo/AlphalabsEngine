/*********************

GLES2Textures.h
Created by Josh Billena

*********************/

#ifndef GLES2_TEXTURES_H
#define GLES2_TEXTURES_H

#include <GLES2/gl2.h>

namespace Alphalabs
{

// Creates a 2D texture and uploads pixel data.
void GLES2CreateTexture(
    GLuint& Texture,
    GLsizei Width,
    GLsizei Height,
    GLenum Format,
    const void* Data
);

// Binds a texture to a texture unit.
void GLES2BindTexture(
    GLuint Texture,
    GLuint Unit
);

// Sets texture filtering and wrapping.
void GLES2TextureParameters(
    GLenum MinFilter,
    GLenum MagFilter,
    GLenum WrapS,
    GLenum WrapT
);

}

#endif // GLES2_TEXTURES_H
