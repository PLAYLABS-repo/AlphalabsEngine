/*********************

GLES2StencilFunctions.h
Created by Josh Billena

*********************/

#ifndef GLES2_STENCIL_FUNCTS_H
#define GLES2_STENCIL_FUNCTS_H

#include <GLES2/gl2.h>

namespace Alphalabs
{

// Clears the stencil buffer to Value.
void GLES2ClearStencil(GLint Value);

// Begins writing geometry into the stencil mask.
void GLES2InitStencilMask();

// Switches from writing the mask to testing it.
void GLES2EndStencilMask();

// Disables stencil masking and restores normal state.
void GLES2DisableStencilMask();

}

#endif // GLES2_STENCIL_FUNCTS_H
