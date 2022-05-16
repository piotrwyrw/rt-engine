#include "engine.h"
#include "def.h"

#define RAY_HIT_THRESHOLD 0.001
#define MAX_RENDER_DEPTH 100

void RT_StartEngine(RT_SDLParams *p, RT_World *w) {
    INFINITE {
        SDL_Event evt;
        while (SDL_PollEvent(&evt) > 0) {
            if (evt.type == SDL_QUIT) goto quit;
        }
        RT_Render(p, w);
        SDL_UpdateWindowSurface(p->w);
    }
    quit:
    RT_SDLQuit(p);
}

static int frame = 0;
void RT_Render(RT_SDLParams *p, RT_World *w) {
    if (frame > 0) return;
    frame ++;
    RT_Color c;
    printf("Rendering frame 0 ...\n");
    for (unsigned x = 0; x < WIDTH; x ++)
        for (unsigned y = 0; y < HEIGHT; y ++) {
            RT_Vec v = RT_CreateVecFromIndividualComponents((double) x, (double) y, 0.0);
            RT_Vec d = RT_CreateVecFromIndividualComponents(0.0, 0.0, 1.0);
            RT_State s = RT_TraceRay(&c, w, &v, &d);
            if (s == ERROR_STATE) {
                SDL_SetRenderDrawColor(p->r, 80, 80, 80, SDL_ALPHA_OPAQUE);
            } else {
                SDL_SetRenderDrawColor(p->r, c.c[CLR_R_CMP], c.c[CLR_G_CMP], c.c[CLR_B_CMP], SDL_ALPHA_OPAQUE);
            }
            SDL_RenderDrawPoint(p->r, x, y);
        }
    printf("Done.\n");
    SDL_RenderPresent(p->r);
}

RT_State RT_TraceRay(RT_Color *target, RT_World *wd, RT_Vec *start, RT_Vec *dir) {
    double d = 0;
    if (RT_IsNorm(dir)) RT_NormVec(dir); // Make sure, that the direction vector is normalized
    RT_Vec _s = RT_CreateVecFromIndividualComponents(start->d[VEC_X_CMP], start->d[VEC_Y_CMP], start->d[VEC_Z_CMP]);

    INFINITE {
        RT_Sph s = wd->ss[RT_ClosestObstacle(wd, &_s)];
        // printf("%f\n", d);
        // return ERROR_STATE;
        double _d = RT_DstSph(&_s, &s);
        d += _d;
        printf("Closest obstacle: %f.\n", _d);

        if (d > MAX_RENDER_DEPTH) {
            // printf("Exceeded max. depth of %d: %d;\n", MAX_RENDER_DEPTH, (int) d);
            return ERROR_STATE;
        }


        RT_Vec tmp = RT_CreateVecFromIndividualComponents(dir->d[VEC_X_CMP], dir->d[VEC_Y_CMP], dir->d[VEC_Z_CMP]);
        RT_NormVec(&tmp);
        RT_MulVec(&tmp, d);
        RT_AddVec(&_s, &tmp); // Add the temporary vector to the _s vector

        if (_d <= RAY_HIT_THRESHOLD) {
            break;
        }
    }

    // At this point (_s) is the point of intersection between the ray and the sphere, (d) is the length of the ray
    // For now, we will color the pixel according to the length of the ray (for temporary testing purposes)
    char g = (char) ((255/MAX_RENDER_DEPTH)*d);
    target->c[CLR_R_CMP] = g;
    target->c[CLR_G_CMP] = g;
    target->c[CLR_B_CMP] = g;
    
    // Return as success, to let the engine know, that the target pixel has been filled out.
    return SUCCESS_STATE;
}