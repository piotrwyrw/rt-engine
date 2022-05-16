#include "engine.h"
#include "def.h"

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

RT_Color RT_TraceRay(RT_Vec *start, RT_Vec *dir) {
    
}