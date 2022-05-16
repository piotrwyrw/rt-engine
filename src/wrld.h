#ifndef RT_WRLD_H
#define RT_WRLD_H

#include "sph.h"

typedef struct {
    RT_Sph *ss;
    unsigned len;
    unsigned mx;
} RT_World;

RT_World RT_CreateWorld(unsigned);
void RT_DestroyWorld(RT_World *);
unsigned RT_ClosestObstacle(RT_World *, RT_Vec *);

#endif