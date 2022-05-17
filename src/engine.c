#include "engine.h"
#include "def.h"

#define RAY_HIT_THRESHOLD 0.001
#define MAX_RENDER_DEPTH 200

void RT_StartEngine(RT_SDLParams *p, RT_World *w) {
    double angle = 0.0;
    int orgx = w->ss[0].ct.d[VEC_X_CMP];
    INFINITE {
        SDL_Event evt;
        while (SDL_PollEvent(&evt) > 0) {
            if (evt.type == SDL_QUIT) goto quit;
        }
        RT_Render(p, w);
        SDL_UpdateWindowSurface(p->w);
        angle += 0.05;
        w->ss[0].ct.d[VEC_Y_CMP] = orgx + sin(angle) * 200;
    }
    quit:
    RT_SDLQuit(p);
}

static int frame = 0;
void RT_Render(RT_SDLParams *p, RT_World *w) {
    // if (frame > 0) return;
    frame ++;
    printf("%d\n", frame);
    RT_Color c;
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
    SDL_RenderPresent(p->r);
}

RT_State RT_TraceRay(RT_Color *target, RT_World *wd, RT_Vec *start, RT_Vec *dir) {
    double d = 0;
    if (RT_IsNorm(dir)) RT_NormVec(dir); // Make sure, that the direction vector is normalized
    RT_Vec _s = RT_CreateVecFromIndividualComponents(start->d[VEC_X_CMP], start->d[VEC_Y_CMP], start->d[VEC_Z_CMP]);
    RT_Sph *obj = NULL;

    INFINITE {
        obj = &(wd->ss[RT_ClosestObstacle(wd, &_s)]);
        double _d = RT_DstSph(&_s, obj);
        d += _d;

        if (d > MAX_RENDER_DEPTH) {
            return ERROR_STATE;
        }


        RT_Vec tmp = RT_CreateVecFromIndividualComponents(dir->d[VEC_X_CMP], dir->d[VEC_Y_CMP], dir->d[VEC_Z_CMP]);
        // RT_NormVec(&tmp);
        RT_MulVec(&tmp, _d);
        RT_AddVec(&_s, &tmp); // Add the temporary vector to the _s vector

        if (_d <= RAY_HIT_THRESHOLD) {
            break;
        }
    }

    // At this point (_s) is the point of intersection between the ray and the sphere, (d) is the length of the ray
    // For now, we will color the pixel according to the length of the ray (for temporary testing purposes)
    RT_Vec n = RT_NewDiffVec(&_s, &(obj->ct));
    RT_NormVec(&n);
    RT_MulVec(&n, 255/2);
    target->c[CLR_R_CMP] = 255/2 + (n.d[VEC_X_CMP]);
    target->c[CLR_G_CMP] = 255/2 + (n.d[VEC_Y_CMP]);
    target->c[CLR_B_CMP] = 255/2 + (n.d[VEC_Z_CMP]);
    
    // Return as success, to let the engine know, that the target pixel has been filled out.
    return SUCCESS_STATE;
}
