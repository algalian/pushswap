#include"push_swap.h"

static int first_step(t_stacks *s)
{
	int largest;

	largest = s->height_a;
	while(s->height_a > 3 && s->a[0][1] == 0)
	{
		if(s->a[0][0] < (s->height_a/2) + 1)

			push(s, 'b');
		else
		{	
			s->a[0][1] = 1;
			rotate(s, "a");
		}
	}
	reset_flag(1, s->a, s->height_a);
	return(largest);
}

static void leave_three(t_stacks *s, int largest)
{
	int i;

	i = 0;
	while(s->height_a > 3)
	{
		if(s->a[0][0] <= largest - 3)
			push(s, 'b');
		else
			rotate(s, "a");
		i++;
	}
}

static int upwards_cost(t_stacks *s, int i, int *n)
{
	if(i <= s->height_b / 2)
	{
		n[4] = 1;
		return(i);			
	}
	n[4] = -1;
	return(s->height_b - i);
}

static int downwards_cost(t_stacks *s, int *n)
{
	if(n[5] <= s->height_a / 2)
	{
		n[3] = 1;
		return(n[5]);			
	}
	n[3] = -1;
	return(s->height_a - n[5]);
}

static int find_min(t_stacks *s)
{
	int i;
	int min;
	int index;

	i = 0;
	min = s->b[i][1] + s->b[i][2];
	index = i;
	while(i < s->height_b)
	{
		if(s->b[i][1] + s->b[i][2] < min)
		{
			min = s->b[i][1] + s->b[i][2];
			index = i;
		}
		i++;
	}
	return(index);
}

static void turn_back(t_stacks *s, int n, int w)
{
	int i;

	if(w == 1)
	{
		i = 0;
		while(i < n)
		{
			reverse_rotate(s, "a");
			i++;
		}
	}
	if(w == -1)
	{
		i = 0;
		while(i < n)
		{
			rotate(s, "a");
			i++;
		}
	}
}

static void exec_move(t_stacks *s, int index)
{
	int *temp;
	int i;

	temp = s->b[index];
	if(temp[4] == 1)
	{
		while(s->b[0][0] != temp[0])
		{
			rotate(s, "b");
		}
	}
	if(temp[4] == -1)
	{
		while(s->b[s->height_b - 1][0] != temp[0])
		{
			reverse_rotate(s, "b");
		}
	}
	if(temp[3] == 1)
	{
		i = 0;
		while(i < temp[5])
		{
			rotate(s, "a");
			i++;
		}
	}
	if(temp[3] == -1)
	{	
		i = 0;
		while(i < s->height_b - temp[5])
		{
			reverse_rotate(s, "a");
			i++;
		}
	}
	push(s, 'a');
	turn_back(s, i, temp[3]);
}

static int ft_highest(t_stacks *s, int **a)
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

static void target_pos(t_stacks *s, int *b)
{
	int i;
	int bound;

	i = 0;
	bound = ft_highest(s, s->a);
	while(i < s->height_a)
	{
		if(b[0] < s->a[i][0] && bound > s->a[i][0])
		{
			b[5] = i;
			bound = s->a[i][0];
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		**str;
	int			i;
	int 		min;
	int			j;

	str = check_args(argc, argv, &s);
	s.flags = 8;
	mount_stacks(str, &s);
	s.height_b = 0;
	s.a = ft_index(s.raw, s.height_a, s.flags);
	i = first_step(&s);
	leave_three(&s,i);
	sort_three(&s);
	j = 0;
	while(s.height_b > 0)
	{
		i = 0;
		while(i < s.height_b)
		{
			target_pos(&s, s.b[i]);
			s.b[i][1] = downwards_cost(&s, s.b[i]);
			s.b[i][2] = upwards_cost(&s, i, s.b[i]);
			i++;
		}
		min = find_min(&s);
		exec_move(&s, min);
		j++;
	}
	ft_printf("moves: %i\n", s.moves);
	return(0);
}