/*********************

GLES2Buffer.h
Created by Josh Billena

*********************/

#ifndef GLES2_BUFFER_H
#define GLES2_BUFFER_H

#include <GLES2/gl2.h>

namespace Alphalabs
{

// Creates a VBO and uploads data into it.
void GLES2CreateVBO(
    GLuint& VBO,                    // Receives the created VBO.
    GLenum Target,                  // Buffer target.
    GLsizeiptr Size,                // Data size in bytes.
    const void* Data,               // Data to upload.
    GLenum Usage                    // Intended usage.
);

// Makes a buffer current for the specified target.
void GLES2UseCurrent(
    GLuint Object,                  // Buffer to bind.
    GLenum Target                   // Buffer target.
);

}

#endif // GLES2_BUFFER_H
