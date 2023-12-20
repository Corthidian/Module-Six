#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H


int rgbToCMYK(int r, intg, intb, double *c, double*m, double *y, double*k);
int cmykToRGB(double c, double m, double y, doublek, int *r, int *g, int*b);

#endif