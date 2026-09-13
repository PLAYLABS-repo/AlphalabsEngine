/*********************

GLES2Attributes.h
Created by Josh Billena

*********************/

#ifndef GLES2_ATTRIBUTES_H
#define GLES2_ATTRIBUTES_H

#include <GLES2/gl2.h>

namespace Alphalabs
{

// Configures a vertex attribute.
void GLES2Attributes(
    GLuint Location,                // Attribute location.
    GLint Order,                    // Number of components.
    GLenum Type,                    // Component data type.
    GLboolean Normalize,            // Whether integer data is normalized.
    GLsizei ByteSize,               // Vertex stride in bytes.
    const void* StartData           // Byte offset into the current VBO.
);

}

#endif // GLES2_ATTRIBUTES_H
