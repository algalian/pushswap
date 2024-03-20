#include"push_swap.h"


void    sort_three(t_stacks *s)
{
	if(s->a[0][0] > s->a[1][0])
	{
		if(s->a[0][0] > s->a[2][0])
		{
			if(s->a[1][0] > s->a[2][0])
			{
				rotate(s, "a");
				swap(s, "a");
				return;
			}
			rotate(s,"a");
			return;
		}
		if(s->a[1][0] < s->a[2][0])
		{
			swap(s, "a");
			return;
		}
		reverse_rotate(s, "a");
		return;
	}
	if(s->a[0][0] < s->a[2][0])
	{
		if(s->a[1][0] < s->a[2][0])
			return;
		rotate(s, "a");
		swap(s, "a");
		reverse_rotate(s, "a");
		return;
	}
	if(s->a[1][0] < s->a[2][0])
	{
		swap(s,"a");
		return;
	}
	reverse_rotate(s,"a");
}

void reset_flag(int flag, int **stack, int height)
{
	int i;

	i = 0;
	while(i <  height)
	{
		stack[i][flag] = 0;
		i++;
	}
}

void free_string(char **s)
{
	int i;
	
	i = 0;
	while(s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void free_array(int h, int **a)
{
	int i;

	i = 0;
	while(i < h)
	{
		free(a[i]);
		i++;
	}
	h++;
	free(a);
}
