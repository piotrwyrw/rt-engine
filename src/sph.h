#ifndef RT_SPH_H
#define RT_SPH_H

#include "vec.h"

typedef struct {
    RT_Vec ct;
    double r;
} RT_Sph;

RT_Sph RT_CreateSph(RT_Vec *, double);

double RT_DstSph(RT_Vec *, RT_Sph *);

#endif