#include"push_swap.h"


int find_min(t_stacks *s)
{
	int i;
	int min;
	int index;

	i = 0;
	min = s->b[i][2];
	index = i;
	while(i < s->height_b)
	{
		if(s->b[i][2] < min)
		{
			min = s->b[i][2];
			index = i;
		}
		i++;
	}
	return(index);
}

int ft_highest(t_stacks *s, int **a)
{
	int i;
	int max;

	i = 0;
	max = a[i][0];
	while(i < s->height_a)
	{
		if(a[i][0] > max)
		{
			max = a[i][0];
		}
		i++;
	}
	return(max);
}

void target_pos(t_stacks *s, int *b)
{
	int i;
	int bound;

	i = 0;
	bound = ft_highest(s, s->a);
	while(i < s->height_a)
	{
		if(b[0] < s->a[i][0] && bound > s->a[i][0])
		{
			b[1] = i;
			bound = s->a[i][0];
		}
		i++;
	}
}

void total_cost(t_stacks *s, int *b, int n)
{
	int *m;
	int i;
	int min;
	int index;

	m = malloc(sizeof(int) * 4);
	if(!m)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
	m[0] = ft_min(n, b[1]) + ft_abs(n - b[1]);
	m[1] = n + (s->height_a - b[1]) + 1;
	m[2] = (s->height_b - n) + b[1];
	m[3] = ft_min(s->height_b - n,s->height_a - b[1]) + ft_abs((s->height_b - n) - (s->height_a - n));
	i = 0;
	index = 0;
	min = m[0];
	while(i < 4)
	{
		if(m[i] < min)
		{
			min = m[i];
			index = i;
		}
		i++;
	}
	b[2] = min;
	b[3] = index + 1;
	free(m);
}