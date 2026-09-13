#include "GLES2Buffer.h"

namespace Alphalabs
{

// Creates a VBO and uploads data into it.
void GLES2CreateVBO(
    GLuint& VBO,
    GLenum Target,
    GLsizeiptr Size,
    const void* Data,
    GLenum Usage
)
{
    // Creates the VBO object.
    glGenBuffers(1, &VBO);

    // Binds the VBO to its target.
    glBindBuffer(Target, VBO);

    // Uploads the data to the GPU.
    glBufferData(Target, Size, Data, Usage);
}

// Makes a buffer current for the specified target.
void GLES2UseCurrent(
    GLuint Object,
    GLenum Target
)
{
    // Binds the object to the target.
    glBindBuffer(Target, Object);
}

}
