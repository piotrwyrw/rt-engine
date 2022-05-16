#include "sdl.h"
#include "def.h"
#include "engine.h"
#include <stdio.h>

int main(void) {
    RT_SDLParams p = RT_InitSDL(WIDTH, HEIGHT);
    RT_StartEngine(&p);
    return 0;
}