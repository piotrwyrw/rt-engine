#include "vec.h"
#include "def.h"
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
    return (v->d[VEC_X_CMP]*v->d[VEC_X_CMP]) + (v->d[VEC_Y_CMP]*v->d[VEC_Y_CMP]) + (v->d[VEC_Z_CMP]*v->d[VEC_Z_CMP]);
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

void RT_NormVec(RT_Vec *v) {
    double m = RT_MagVec(v);
    if (m == 0.0) return;
    RT_DivVec(v, m);
}

int RT_IsNorm(RT_Vec *v) {
    return RT_MagVec(v) == 1.0;
}

RT_Vec RT_NewDiffVec(RT_Vec *v1, RT_Vec *v2) {
    return RT_CreateVecFromIndividualComponents(
        v1->d[VEC_X_CMP] - v2->d[VEC_X_CMP],
        v1->d[VEC_Y_CMP] - v2->d[VEC_Y_CMP],
        v1->d[VEC_Z_CMP] - v2->d[VEC_Z_CMP]
    );
}

RT_Vec RT_AddVec(RT_Vec *target, RT_Vec *v) {
    target->d[VEC_X_CMP] = v->d[VEC_X_CMP];
    target->d[VEC_Y_CMP] = v->d[VEC_Y_CMP];
    target->d[VEC_Z_CMP] = v->d[VEC_Z_CMP];
}

double RT_SqDstVec(RT_Vec *v1, RT_Vec *v2) {
    return SQ(v1->d[VEC_X_CMP] - v2->d[VEC_X_CMP]) + SQ(v1->d[VEC_Y_CMP] - v2->d[VEC_Y_CMP]) + SQ(v1->d[VEC_Z_CMP] - v2->d[VEC_Z_CMP]);
}

double RT_DstVec(RT_Vec *v1, RT_Vec *v2) {
    return sqrt(RT_SqDstVec(v1, v2));
}