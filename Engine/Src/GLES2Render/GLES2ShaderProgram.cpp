#include "GLES2ShaderProgram.h"

namespace Alphalabs
{

// Compiles vertex and fragment shaders.
void GLES2CompileShaders(
    const char* VertexSource,
    const char* FragmentSource,
    GLuint& VertexShader,
    GLuint& FragmentShader
)
{
    // Creates the vertex shader.
    VertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Supplies the vertex shader source.
    glShaderSource(VertexShader, 1, &VertexSource, NULL);
    // Compiles the vertex shader.
    glCompileShader(VertexShader);

    // Creates the fragment shader.
    FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Supplies the fragment shader source.
    glShaderSource(FragmentShader, 1, &FragmentSource, NULL);
    // Compiles the fragment shader.
    glCompileShader(FragmentShader);
}

// Creates an empty shader program.
void GLES2CreateProgram(GLuint& Program)
{
    // Creates the program.
    Program = glCreateProgram();
}

// Attaches shaders to a program.
void GLES2AttachShaders(
    GLuint VertexShader,
    GLuint FragmentShader,
    GLuint Program
)
{
    // Attaches the vertex shader.
    glAttachShader(Program, VertexShader);
    // Attaches the fragment shader.
    glAttachShader(Program, FragmentShader);
}

// Assigns an attribute to a location before linking.
void GLES2AssignAttribs(
    GLuint Program,
    GLuint Location,
    const char* Name
)
{
    // Assigns the requested attribute location.
    glBindAttribLocation(Program, Location, Name);
}

// Uploads a uniform value to a shader program.
void GLES2AssignUniform(
    GLuint Program,
    const char* Name,
    GLenum Type,
    const void* Value
)
{
    // Finds the uniform location in the program.
    GLint Location = glGetUniformLocation(Program, Name);

    // Stops when the uniform was not found.
    if (Location < 0 || Value == NULL)
        return;

    // Uploads a single float.
    if (Type == GL_FLOAT)
        glUniform1f(Location, *(const GLfloat*)Value);

    // Uploads two floats.
    else if (Type == GL_FLOAT_VEC2)
        glUniform2fv(Location, 1, (const GLfloat*)Value);

    // Uploads three floats.
    else if (Type == GL_FLOAT_VEC3)
        glUniform3fv(Location, 1, (const GLfloat*)Value);

    // Uploads four floats.
    else if (Type == GL_FLOAT_VEC4)
        glUniform4fv(Location, 1, (const GLfloat*)Value);

    // Uploads a 2x2 matrix.
    else if (Type == GL_FLOAT_MAT2)
        glUniformMatrix2fv(Location, 1, GL_FALSE, (const GLfloat*)Value);

    // Uploads a 3x3 matrix.
    else if (Type == GL_FLOAT_MAT3)
        glUniformMatrix3fv(Location, 1, GL_FALSE, (const GLfloat*)Value);

    // Uploads a 4x4 matrix.
    else if (Type == GL_FLOAT_MAT4)
        glUniformMatrix4fv(Location, 1, GL_FALSE, (const GLfloat*)Value);

    // Uploads a single integer or sampler value.
    else if (Type == GL_INT || Type == GL_SAMPLER_2D)
        glUniform1i(Location, *(const GLint*)Value);

    // Uploads two integers.
    else if (Type == GL_INT_VEC2)
        glUniform2iv(Location, 1, (const GLint*)Value);

    // Uploads three integers.
    else if (Type == GL_INT_VEC3)
        glUniform3iv(Location, 1, (const GLint*)Value);

    // Uploads four integers.
    else if (Type == GL_INT_VEC4)
        glUniform4iv(Location, 1, (const GLint*)Value);
}

// Links a shader program.
void GLES2LinkProgram(GLuint Program)
{
    // Links the attached shaders.
    glLinkProgram(Program);
}

// Makes a shader program current.
void GLES2UseProgram(GLuint Program)
{
    // Activates the program.
    glUseProgram(Program);
}

}
