#ifndef RT_VEC_H
#define RT_VEC_H

#define VEC_X_CMP 0
#define VEC_Y_CMP 1
#define VEC_Z_CMP 2

typedef struct {
    double d[3];
} RT_Vec;

typedef RT_Vec RT_Point;

RT_Vec RT_CreateVec(double[3]);
RT_Vec RT_CreateVecFromIndividualComponents(double, double, double);

double RT_SqMagVec(RT_Vec *);
double RT_MagVec(RT_Vec *);

void RT_DivVec(RT_Vec *, double);
void RT_MulVec(RT_Vec *, double);

RT_Vec RT_DiffVec(RT_Vec *, RT_Vec *);

#endif