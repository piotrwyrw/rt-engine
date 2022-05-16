#include "engine.h"
#include "def.h"

#define RAY_HIT_THRESHOLD 0.001

void RT_StartEngine(RT_SDLParams *p) {
    INFINITE {
        SDL_Event evt;
        while (SDL_PollEvent(&evt) > 0) {
            if (evt.type == SDL_QUIT) goto quit;
        }
        RT_Render(p);
        SDL_UpdateWindowSurface(p->w);
    }
    quit:
    RT_SDLQuit(p);
}


void RT_Render(RT_SDLParams *p) {
    SDL_SetRenderDrawColor(p->r, rgb(44, 62, 80));
    SDL_RenderClear(p->r);
    SDL_RenderPresent(p->r);
}

RT_Color RT_TraceRay(RT_World *wd, RT_Vec *start, RT_Vec *dir) {
    double d = 0;
    if (RT_IsNorm(dir)) RT_NormVec(dir);
    RT_Vec _s = RT_CreateVecFromIndividualComponents(start->d[VEC_Z_CMP], start->d[VEC_Y_CMP], start->d[VEC_Z_CMP]);

    while (d <= RAY_HIT_THRESHOLD) {
        
    }
}