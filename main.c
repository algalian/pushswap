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
	int i;

	i = 0;
	while(n[0] > s->a[i][0])
		i++;
	if(i <= s->height_a / 2)
	{
		n[3] = 1;
		return(i);
	}
	n[3] = -1;
	return(s->height_a  - i);
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

static void exec_move(t_stacks *s, int index)
{
	int i;
	int j;
	int *t;
	
	t = s->b[index];
	if(s->b[index][4] == 1) 
	{
		while(s->b[0][0] != t[0])
		{
			rotate(s, "b");
		}
	}
	else
	{
		while(s->b[0][0] != t[0])
		{
			reverse_rotate(s, "b");
		}
	}
//-------------------------------------
	if(s->b[index][3] == 1)
	{
		i = 0;
		while(s->a[0][0] < s->b[0][0])
		{
			rotate(s,"a");
			i++;
		}
		push(s, 'a');
		j = 0;
		while(j < i)
		{
			reverse_rotate(s, "a");
			j++;
		}
		return;
	}
	else
	{
		i = 0;
		while(s->a[0][0] < s->b[0][0])
		{
			reverse_rotate(s, "a");
			i++;
		}
		push(s, 'a');
		j = 0;
		while(j < i)
		{
			reverse_rotate(s, "a");
			j++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		**str;
	int			i;
	int			j;
	int 		min;

	str = check_args(argc, argv, &s);
	s.flags = 8;
	mount_stacks(str, &s);
	s.height_b = 0;
	s.a = ft_index(s.raw, s.height_a, s.flags);
	i = first_step(&s);
	leave_three(&s,i);
	sort_three(&s);
	j = 0;
	i = 0;
	while(s.height_b > 0)
	{	
		while(i < s.height_b)
		{
			s.b[i][1] = downwards_cost(&s, s.b[i]);
			s.b[i][2] = upwards_cost(&s, i, s.b[i]);
			min = find_min(&s); 
			i++;
		}
		exec_move(&s, min);
		j++;
	}
	//print_stacks(&s);
	//ft_printf("moves: %i\n", s.moves);
	return(0);
}