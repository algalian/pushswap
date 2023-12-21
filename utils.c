#include<stdio.h>

void ft_switch(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
