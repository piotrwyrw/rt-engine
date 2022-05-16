#include "wrld.h"
#include <stdlib.h>

RT_World RT_CreateWorld(unsigned mx) {
    RT_World w;
    w.mx = mx;
    w.len = 0;
    w.ss = malloc(sizeof(RT_Sph) * mx);
    return w;
}

void RT_DestroyWorld(RT_World *w) {
    free(w->ss);
}

unsigned RT_ClosestObstacle(RT_World *wd, RT_Vec *v) {
    double _d = 0;
    int idx = 0;
    for (unsigned i = 0; i < wd->len; i ++) {
        double d = RT_DstSph(v, &(wd->ss[i]));
        if (d < _d) {
            _d = d;
            idx = i;
        }
    }
    return idx;
}