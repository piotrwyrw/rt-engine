#include "sdl.h"

RT_SDLParams RT_CreateSDLParams(SDL_Window *w, SDL_Surface *s, SDL_Renderer *r) {
    RT_SDLParams params;
    params.w = w;
    params.s = s;
    params.r = r;
    return params;   
}

RT_SDLParams RT_InitSDL(unsigned w, unsigned h) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *_w = SDL_CreateWindow("Raytracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
    SDL_Surface *s = SDL_GetWindowSurface(_w);
    SDL_Renderer *r = SDL_CreateSoftwareRenderer(s);
    return RT_CreateSDLParams(_w, s, r);
}

void RT_SDLQuit(RT_SDLParams *p) {
    SDL_DestroyRenderer(p->r);
    SDL_DestroyWindow(p->w);
    SDL_Quit();
}