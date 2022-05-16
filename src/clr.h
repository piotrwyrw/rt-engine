#ifndef RT_CLR_H
#define RT_CLR_H

#define CLR_R_CMP 0
#define CLR_G_CMP 1
#define CLR_B_CMP 2

typedef struct {
    unsigned char c[3];
} RT_Color;

RT_Color RT_CreateColor(unsigned char[3]);
RT_Color RT_CreateColorFromInidividualComponents(unsigned char, unsigned char, unsigned char);

#endif