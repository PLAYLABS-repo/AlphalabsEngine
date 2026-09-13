#include <iostream>
#include "Engine/Src/Main/Main.h"
#include "Engine/Src/Necessity.h"

#include "Engine/Src/Main/Image/ImgDecode.h"
#include "Engine/Src/Main/Image/ImgData.h"

#include "Engine/Src/GLES2Includes.h"

using namespace Alphalabs;

GLuint Program;
GLuint QuadVBO;
GLuint Texture;
GLint  TextureUniform;

// Loads an image off disk and uploads it as a GL texture.
bool LoadImageTexture(const std::string& path)
{
    ImgData   data;
    ImgDecode decoder;

    if (!decoder.Decode(path, data))
    {
        std::cerr << "Failed to decode image: " << path << std::endl;
        return false;
    }

    unsigned char* pixels = decoder.GetRGBAPixels();
    if (pixels == nullptr)
    {
        std::cerr << "Failed to get RGBA pixels for: " << path << std::endl;
        decoder.Unload();
        return false;
    }

    GLES2CreateTexture(
        Texture,
        data.TargetImageWidth,
        data.TargetImageHeight,
        GL_RGBA,
        pixels
    );

    GLES2TextureParameters(
        GL_LINEAR, GL_LINEAR,
        GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE
    );

    decoder.Unload();

    return true;
}

// Initializes the textured quad's shader program and vertex buffer.
void ImageQuadInit()
{
    std::string VertexShaderSource   = File::Read("Res/Shaders/texture.vs");
    std::string FragmentShaderSource = File::Read("Res/Shaders/texture.ps");

    GLuint VertexShader;
    GLuint FragmentShader;

    GLES2CompileShaders(
        VertexShaderSource.c_str(),
        FragmentShaderSource.c_str(),
        VertexShader,
        FragmentShader
    );

    GLES2CreateProgram(Program);

    GLES2AttachShaders(
        VertexShader,
        FragmentShader,
        Program
    );

    GLES2AssignAttribs(Program, 0, "aPosition");
    GLES2AssignAttribs(Program, 1, "aTexCoord");

    GLES2LinkProgram(Program);

    TextureUniform = glGetUniformLocation(Program, "uTexture");

    // Enables alpha blending so transparent pixels in the texture
    // let the background show through instead of rendering opaque.
    glEnable(GL_BLEND);
    GLES2SetBlendFunction(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat QuadVertices[] =
    {
        -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  1.0f, 1.0f
    };

    GLES2CreateVBO(
        QuadVBO,
        GL_ARRAY_BUFFER,
        sizeof(QuadVertices),
        QuadVertices,
        GL_STATIC_DRAW
    );

    LoadImageTexture("UnitTest/image-removebg-preview.png");
}
// Renders the textured quad.
void ImageQuadRender()
{
    GLES2ClearScreen(0.08f, 0.08f, 0.08f, 1.0f);

    GLES2UseProgram(Program);

    GLES2UseCurrent(QuadVBO, GL_ARRAY_BUFFER);

    GLES2Attributes(
        0, 2, GL_FLOAT, GL_FALSE,
        4 * sizeof(GLfloat),
        (void*)0
    );

    GLES2Attributes(
        1, 2, GL_FLOAT, GL_FALSE,
        4 * sizeof(GLfloat),
        (void*)(2 * sizeof(GLfloat))
    );

    GLES2BindTexture(Texture, 0);
    glUniform1i(TextureUniform, 0);

    GLES2DrawType(GL_TRIANGLES, 0, 6);
}

// Program entry point.
int main()
{
    Window Window;

    if (!Window.Init())
        return 1;

    ImageQuadInit();

    while (Window.running)
    {
        Window.PollEvents();
        ImageQuadRender();
        eglSwapBuffers(Window.display, Window.surface);
    }

    return 0;
}
