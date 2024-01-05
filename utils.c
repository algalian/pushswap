#include"push_swap.h"

void ft_switch(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    sort_three(t_stacks *s)
{
	if(s->a[0] > s->a[1])
	{
		if(s->a[0] > s->a[2])
		{
			if(s->a[1] > s->a[2])
			{
				rotate(s, "a");
				swap(s, "a");
				return;
			}
			rotate(s,"a");
			return;
		}
		if(s->a[1] < s->a[2])
		{
			swap(s, "a");
			return;
		}
		reverse_rotate(s, "a");
		return;
	}
	if(s->a[0] < s->a[2])
	{
		if(s->a[1] < s->a[2])
			return;
		rotate(s, "a");
		swap(s, "a");
		reverse_rotate(s, "a");
		return;
	}
	if(s->a[1] < s->a[2])
	{
		swap(s,"a");
		return;
	}
	reverse_rotate(s,"a");
}

void    print_stacks(t_stacks *s) //for debugging
{
	int i;

	ft_printf("A   B\n");
	ft_printf("_____\n");
	i = 0;
	while(i < ft_max(s->height_a,s->height_b))
	{
		ft_printf("%i   %i\n",s->a[i], s->b[i]);
		i++;
	}
	ft_printf("\n");
}

/*static void pos_in_stack(t_stacks *s) //deprecated
{
	int i;
	if(s->pos_a)
		free(s->pos_a);
	s->pos_a = malloc(sizeof(int) * s->height_a);
	i = 0;
	while(i < s->height_a)
	{
		s->pos_a[i] = s->a[i];
		i++;
	}
	if(s->pos_b)
		free(s->pos_b);
	s->pos_b = malloc(sizeof(int) * s->height_b);
	i = 0;
	while(i < s->height_b)
	{
		s->pos_b[i] = s->b[i];
		i++;
	}
}*/