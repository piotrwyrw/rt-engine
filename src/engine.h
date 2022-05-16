#ifndef RT_ENGINE_H
#define RT_ENGINE_H

#include "sdl.h"
#include "clr.h"
#include "vec.h"

void RT_StartEngine(RT_SDLParams *);
void RT_Render(RT_SDLParams *);
RT_Color RT_TraceRay(RT_Vec *, RT_Vec *);

#endif