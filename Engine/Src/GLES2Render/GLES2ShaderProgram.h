/*********************

GLES2ShaderProgram.h
Created by Josh Billena

*********************/

#ifndef GLES2_SHADER_PROGRAM_H
#define GLES2_SHADER_PROGRAM_H

#include <GLES2/gl2.h>

namespace Alphalabs
{

// Compiles vertex and fragment shaders.
void GLES2CompileShaders(
    const char* VertexSource,       // Vertex shader source.
    const char* FragmentSource,     // Fragment shader source.
    GLuint& VertexShader,           // Receives the vertex shader.
    GLuint& FragmentShader          // Receives the fragment shader.
);

// Creates an empty shader program.
void GLES2CreateProgram(GLuint& Program);

// Attaches shaders to a program.
void GLES2AttachShaders(
    GLuint VertexShader,
    GLuint FragmentShader,
    GLuint Program
);

// Assigns an attribute to a location before linking.
void GLES2AssignAttribs(
    GLuint Program,
    GLuint Location,
    const char* Name
);

// Uploads a uniform value to a shader program.
void GLES2AssignUniform(
    GLuint Program,
    const char* Name,
    GLenum Type,
    const void* Value
);

// Links a shader program.
void GLES2LinkProgram(GLuint Program);

// Makes a shader program current.
void GLES2UseProgram(GLuint Program);

}

#endif // GLES2_SHADER_PROGRAM_H
