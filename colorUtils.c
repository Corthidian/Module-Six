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

