#include "GLES2StencilFunctions.h"

namespace Alphalabs
{

// Clears the stencil buffer to Value.
void GLES2ClearStencil(GLint Value)
{
    // Sets the stencil clear value.
    glClearStencil(Value);

    // Clears only the stencil buffer.
    glClear(GL_STENCIL_BUFFER_BIT);
}

// Begins writing geometry into the stencil mask.
void GLES2InitStencilMask()
{
    // Enables stencil testing.
    glEnable(GL_STENCIL_TEST);

    // Always passes and uses reference value 1.
    glStencilFunc(GL_ALWAYS, 1, 0xFF);

    // Replaces the stencil value when the fragment passes.
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    // Allows stencil writes.
    glStencilMask(0xFF);

    // Prevents the mask from writing color.
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
}

// Switches from writing the mask to testing it.
void GLES2EndStencilMask()
{
    // Restores color writes.
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

    // Only passes where stencil equals 1.
    glStencilFunc(GL_EQUAL, 1, 0xFF);

    // Keeps the stencil buffer unchanged.
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    // Prevents masked geometry from changing the stencil buffer.
    glStencilMask(0x00);
}

// Disables stencil masking and restores normal state.
void GLES2DisableStencilMask()
{
    // Disables stencil testing.
    glDisable(GL_STENCIL_TEST);

    // Restores stencil writes.
    glStencilMask(0xFF);

    // Ensures color writes are enabled.
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
}

}
