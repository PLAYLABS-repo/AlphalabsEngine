#include "GLES2Textures.h"

namespace Alphalabs
{

// Creates a 2D texture and uploads pixel data.
void GLES2CreateTexture(
    GLuint& Texture,
    GLsizei Width,
    GLsizei Height,
    GLenum Format,
    const void* Data
)
{
    // Creates the texture object.
    glGenTextures(1, &Texture);

    // Binds the texture.
    glBindTexture(GL_TEXTURE_2D, Texture);

    // Uploads the pixel data.
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        Format,
        Width,
        Height,
        0,
        Format,
        GL_UNSIGNED_BYTE,
        Data
    );
}

// Binds a texture to a texture unit.
void GLES2BindTexture(
    GLuint Texture,
    GLuint Unit
)
{
    // Selects the texture unit.
    glActiveTexture(GL_TEXTURE0 + Unit);

    // Binds the texture to GL_TEXTURE_2D.
    glBindTexture(GL_TEXTURE_2D, Texture);
}

// Sets texture filtering and wrapping.
void GLES2TextureParameters(
    GLenum MinFilter,
    GLenum MagFilter,
    GLenum WrapS,
    GLenum WrapT
)
{
    // Sets minification filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MinFilter);

    // Sets magnification filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MagFilter);

    // Sets horizontal wrapping.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WrapS);

    // Sets vertical wrapping.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WrapT);
}

}
