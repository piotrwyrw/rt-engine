#include "sdl.h"
#include "def.h"
#include "engine.h"
#include <stdio.h>

int main(void) {
    RT_SDLParams p = RT_InitSDL(WIDTH, HEIGHT);

    RT_World w = RT_CreateWorld(2);
    RT_Vec c = RT_CreateVecFromIndividualComponents(WIDTH/2, HEIGHT/2, 550);
    RT_Vec c2 = RT_CreateVecFromIndividualComponents(WIDTH/2, HEIGHT/2, 200);
    // RT_Vec c2 = RT_CreateVecFromIndividualComponents(WIDTH/5, HEIGHT/5, 500);
    RT_Sph s = RT_CreateSph(&c, 400);
    RT_Sph s2 = RT_CreateSph(&c2, 150);
    w.ss[0] = s;
    w.ss[1] = s2;
    // RT_Sph s2 = RT_CreateSph(&c, 500);
    // w.ss[1] = s2;
    w.len = 2;
    RT_StartEngine(&p, &w);
    RT_DestroyWorld(&w);
    return 0;
}
