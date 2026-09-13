#include "GLES2Attributes.h"

namespace Alphalabs
{

// Configures a vertex attribute.
void GLES2Attributes(
    GLuint Location,
    GLint Order,
    GLenum Type,
    GLboolean Normalize,
    GLsizei ByteSize,
    const void* StartData
)
{
    // Enables the vertex attribute.
    glEnableVertexAttribArray(Location);

    // Describes how the vertex data is laid out.
    glVertexAttribPointer(
        Location,
        Order,
        Type,
        Normalize,
        ByteSize,
        StartData
    );
}

}
