#ifndef RT_VEC_H
#define RT_VEC_H

typedef struct {
    double d[3];
} RT_Vec;

RT_Vec RT_CreateVec(double[3]);
RT_Vec RT_CreateVecFromIndividualComponents(double, double, double);

double RT_SqMagVec(RT_Vec *);
double RT_MagVec(RT_Vec *);

#endif