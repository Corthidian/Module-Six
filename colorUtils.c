#include "colorUtils.h"
#include <math.h>


typedef enum
{

    NO_ERROR,
    INVALID_INPUT
} ErrorCode;

int toGrayScale(int *r, int *g, int*b, Mode m)
 {
    ErrorCode error = NO_ERROR;
if(r == NULL|| g == NULL || b == NULL) 
{
    return
 INVALID_INPUT;
}

int grayValue;

    
switch(m) 
{
        
case AVERAGE:grayValue = (*r + *g + *b) / 3;
            
break;
        
case LIGHTNESS: grayValue = (*r + *g + *b) / 3;

break;
        
case LUMINOSITY: grayValue = (int)round(0.21 * *r + 0.72 * *g + 0.07* *b); 
            
break;
        
default: error = INVALID_INPUT;

}
if (error == NO_ERROR) 
 {
        *r = grayValue;
        *g = grayValue;
        *b = grayValue;
}

    
return  error;
}

int toSepia(int *r, int *g, int *b)
 {
    if(r == NULL|| g == NULL|| b == NULL) 
    {
        return INVALID_INPUT;
    }

    
int newR = (int)round(0.393 * *r + 0.769* *g +  0.189* *b);
    
int newG = (int)round(0.349* *r +  0.686* *g + 0.168* *b);
    
int newB = (int)round(0.272* *r + 0.534* *g + 0.131* *b);*r = (newR > 255) ? 255: newR;*g = (newG > 255) ? 255: newG;*b = (newB > 255) ? 255: newB;
return  NO_ERROR;
}