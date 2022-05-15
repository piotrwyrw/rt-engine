#include "sph.h"
#include "def.h"
#include <math.h>

RT_Sph RT_CreateSph(RT_Vec *v, double r) {
    RT_Sph s;
    s.ct = RT_CreateVecFromIndividualComponents(v->d[VEC_X_CMP], v->d[VEC_Y_CMP], v->d[VEC_Z_CMP]);
    s.r = r;
    return s;
}

double RT_DstSph(RT_Vec *v, RT_Sph *s) {
    RT_Vec *ct = &(s->ct);
    return sqrt(SQ((ct->d[VEC_X_CMP] - v->d[VEC_X_CMP])) + SQ((ct->d[VEC_Y_CMP] - v->d[VEC_Y_CMP])) + SQ((ct->d[VEC_Z_CMP] - v->d[VEC_Z_CMP])));
}