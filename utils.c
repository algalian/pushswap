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

// *****debuggers*****
//----------------------------------------------------------------------------------------------------
void    print_stacks(t_stacks *s) 
{
	int i;

	ft_printf("Stack A\n");
	i = 0;
	while(i <  s->height_a )
	{
		ft_printf("%i\n",s->a[i][0]);
		i++;
	}
	ft_printf("Stack B\n");
	i = 0;
	while(i <  s->height_b)
	{
		ft_printf("%i\n",s->b[i][0]);
		i++;
	}
}

void print_grid(t_stacks *s)
{
	int i;
	int j;

	ft_printf("A\n");
	i = 0;
	while(i < s->height_a)
	{
		j = 0;
		while(j < s->flags)
		{
			ft_printf("%i ",s->a[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("B\n");
	i = 0;
	while(i < s->height_b)
	{
		j = 0;
		while(j < s->flags)
		{
			ft_printf("%i ",s->b[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}