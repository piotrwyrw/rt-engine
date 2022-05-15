#include "vec.h"
#include <math.h>

RT_Vec RT_CreateVec(double d[3]) {
    RT_Vec v;
    v.d[0] = d[0];
    v.d[1] = d[1];
    v.d[2] = d[2];
    return v;
}

RT_Vec RT_CreateVecFromIndividualComponents(double x, double y, double z) {
    RT_Vec v;
    v.d[0] = x;
    v.d[1] = y;
    v.d[2] = z;
    return v;
}

double RT_SqMagVec(RT_Vec *v) {
    return (v->d[0]*v->d[0]) + (v->d[1]*v->d[1]) + (v->d[2]*v->d[2]);
}

double RT_MagVec(RT_Vec *v) {
    return sqrt(RT_SqMagVec(v));
}