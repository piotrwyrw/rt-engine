#ifndef SQ
#   define SQ(x) ((x) * (x))
#endif

#ifndef WIDTH
#   define WIDTH 100
#endif

#ifndef HEIGHT
#   define HEIGHT 100
#endif

#ifndef TRUE
#   define TRUE 1
#endif

#ifndef FALSE
#   define FALSE 0
#endif

#ifndef INFINITE
#   define INFINITE for (;;)
#endif

#ifndef RGB
#   define RGB(r, g, b) r, g, b, SDL_ALPHA_OPAQUE
#endif

#ifndef rgb
#   define rgb RGB
#endif

typedef int RT_State;

#ifndef ERROR_STATE
#   define ERROR_STATE 0
#endif

#ifndef SUCCESS_STATE
#   define SUCCESS_STATE 1
#endif