#ifndef RT_ENGINE_H
#define RT_ENGINE_H

#include "sdl.h"
#include "clr.h"
#include "vec.h"
#include "wrld.h"
#include "def.h"

void RT_StartEngine(RT_SDLParams *, RT_World *);
void RT_Render(RT_SDLParams *, RT_World *);
RT_State RT_TraceRay(RT_Color *, RT_World *, RT_Vec *, RT_Vec *);

#endif