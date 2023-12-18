#include<stdio.h>

int main()
{
    int a;
    int b;
    int c;

    a = 2;
    b = 1;
    c = 3;

    if (a > b)
	{	
        if(a > c)
		{
			if(b > c)
			{
                printf("b"); 
                return(0);
            }
            printf("c");
            return(0);
		}
        printf("a");
        return(0);
    }
    if(a < c)
    {    
        if(b < c)
        {    
            printf("b");
            return(0);
        }
        printf("c");
        return(0);
    }
    printf("a");
    return(0);
}