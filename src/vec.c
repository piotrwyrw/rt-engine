#include "vec.h"
#include <math.h>

RT_Vec RT_CreateVec(double d[3]) {
    RT_Vec v;
    v.d[VEC_X_CMP] = d[VEC_X_CMP];
    v.d[VEC_Y_CMP] = d[VEC_Y_CMP];
    v.d[VEC_Z_CMP] = d[VEC_Z_CMP];
    return v;
}

RT_Vec RT_CreateVecFromIndividualComponents(double x, double y, double z) {
    RT_Vec v;
    v.d[VEC_X_CMP] = x;
    v.d[VEC_Y_CMP] = y;
    v.d[VEC_Z_CMP] = z;
    return v;
}

double RT_SqMagVec(RT_Vec *v) {
    return (v->d[0]*v->d[0]) + (v->d[1]*v->d[1]) + (v->d[2]*v->d[2]);
}

double RT_MagVec(RT_Vec *v) {
    return sqrt(RT_SqMagVec(v));
}

void RT_DivVec(RT_Vec *v, double d) {
    v->d[VEC_X_CMP] /= d;
    v->d[VEC_Y_CMP] /= d;
    v->d[VEC_Z_CMP] /= d;
}

void RT_MulVec(RT_Vec *v, double d) {
    v->d[VEC_X_CMP] *= d;
    v->d[VEC_Y_CMP] *= d;
    v->d[VEC_Z_CMP] *= d;
}

RT_Vec RT_DiffVec(RT_Vec *v1, RT_Vec *v2) {
    return RT_CreateVecFromIndividualComponents(
        v1->d[VEC_X_CMP] - v2->d[VEC_X_CMP],
        v1->d[VEC_Y_CMP] - v2->d[VEC_Y_CMP],
        v1->d[VEC_Z_CMP] - v2->d[VEC_Z_CMP]
    );
}