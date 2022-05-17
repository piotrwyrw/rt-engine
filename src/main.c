#include "sdl.h"
#include "def.h"
#include "engine.h"
#include <stdio.h>

int main(void) {
    RT_SDLParams p = RT_InitSDL(WIDTH, HEIGHT);
    RT_World w = RT_CreateWorld(1);
    RT_Vec c = RT_CreateVecFromIndividualComponents(WIDTH/2, HEIGHT/2, 500);
    RT_Sph s = RT_CreateSph(&c, 400);
    w.ss[0] = s;
    w.len ++;
    RT_StartEngine(&p, &w);
    RT_DestroyWorld(&w);
    return 0;
}
