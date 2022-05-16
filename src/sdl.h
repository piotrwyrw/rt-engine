#ifndef RT_SDL_H
#define RT_SDL_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window *w;
    SDL_Surface *s;
    SDL_Renderer *r;
} RT_SDLParams;

RT_SDLParams RT_CreateSDLParams(SDL_Window *, SDL_Surface *, SDL_Renderer *);
RT_SDLParams RT_InitSDL(unsigned, unsigned);
void RT_SDLQuit(RT_SDLParams *);

#endif