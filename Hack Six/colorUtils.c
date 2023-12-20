#include "colorUtils.h"
#include <math.h>
#define MAX_COLOR_VALUE 255.0

int rgbToCMYK(int r, int g, int b, double*c, double*m, double *y, double *k)
 {
    
if (c == NULL|| m == NULL|| y == NULL|| k == NULL) 
{
        
return 1; 

}

    
if (r < 0|| r > 255|| g < 0|| g > 255|| b < 0|| b > 255) 
{
        
return 2; 

}

*c = 1.0 - r / MAX_COLOR_VALUE;
*m = 1.0 - g / MAX_COLOR_VALUE;
*y = 1.0 - b / MAX_COLOR_VALUE;
*k = fmin(*c, fmin(*m, *y));
*c = (*c - *k) / (1.0 - *k);
*m = (*m - *k) / (1.0- *k);
*y = (*y - *k) / (1.0- *k);

    
return 0;

}

int cmykToRGB(double c, double m, doubley, double k, int *r, int *g, int *b)
 {
    
if (r == NULL || g == NULL|| b == NULL) 
{
        
return 1; 

}

    
if(c < 0|| c >  1.0|| m < 0|| m > 1.0|| y < 0|| y > 1.0|| k < 0|| k > 1.0) 
{
        
return 2; 

}

*r = round(MAX_COLOR_VALUE * (1.0- c) * (1.0- k));
*g = round(MAX_COLOR_VALUE * (1.0- m) * (1.0- k));
*b = round(MAX_COLOR_VALUE * (1.0- y) * (1.0- k));

    
return 0; 
}