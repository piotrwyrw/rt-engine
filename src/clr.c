#include "clr.h"

RT_Color RT_CreateColor(unsigned char c[3]) {
    RT_Color cl;
    cl.c[CLR_R_CMP] = c[CLR_R_CMP];
    cl.c[CLR_G_CMP] = c[CLR_G_CMP];
    cl.c[CLR_B_CMP] = c[CLR_B_CMP];
    return cl;
}

RT_Color RT_CreateColorFromInidividualComponents(unsigned char r, unsigned char g, unsigned char b) {
    RT_Color cl;
    cl.c[CLR_R_CMP] = r;
    cl.c[CLR_G_CMP] = g;
    cl.c[CLR_B_CMP] = b;
    return cl;
}