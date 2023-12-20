#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H

typedef enum
{
    AVERGAE,
    LIGHNTESS,
    LUMINOSITY
} Mode;

int toGrayScale(int*r, int*g, int*b, Mode m);
int toSepia(int *r, int *g, int *b);

#endif
