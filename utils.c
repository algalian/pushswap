#include"push_swap.h"

int median_of_three(int a, int b, int c)
{
	if (a > b)
	{	
        if(a > c)
		{
			if(b > c)
                return(b);
            return(c);
		}
        return(a);
    }
    if(a < c)
    {    
        if(b < c) 
            return(b);
        return(c);
    }
    return(a);
}