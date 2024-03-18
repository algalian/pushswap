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

static void align(t_stacks *s)
{
	int i;

	i = 0;
	while(s->a[i] != 1)
		i++;
	
}

static void exec_move(t_stacks *s, int index)
{
	int *temp;
	int i;

	temp = s->b[index];
	i = 0;
	if(temp[3] == 1)
	{			
		while(s->b[0][0] != temp[0] && i < temp[1])
		{
			rotate(s, "ab");
			i++;
		}
		while(s->b[0][0] != temp[0])
		{
			rotate(s,"b");
		}
		while(i < temp[1])
		{
			rotate(s, "a");
			i++;
		}
		push(s,'a');
	}
	if(temp[3] == 2)
	{
		while(s->b[0][0] != temp[0])
		{
			rotate(s,"b");
		}
		while(i < s->height_a - temp[1])
		{
			reverse_rotate(s, "a");
			i++;
		}
		i++;
		push(s,'a');

	}
	if(temp[3] == 3)
	{
		while(s->b[0][0] != temp[0])
		{
			reverse_rotate(s, "b");
		}
		while(i < temp[1])
		{
			rotate(s, "a");
			i++;
		}
		push(s, 'a');
	}
	if(temp[3] == 4)
	{
		while(s->b[0][0] != temp[0] && i < s->height_a - temp[1])
		{
			reverse_rotate(s, "ab");
			i++;
		}
		while(s->b[0][0] != temp[0])
		{
			reverse_rotate(s, "b");
		}
		while(i < s->height_a - temp[1])
		{
			reverse_rotate(s,"a");
			i++;
		}
		push(s, 'a');

	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		**str;
	int			i;
	int			min;
	int			j;
	int			k;

	str = check_args(argc, argv, &s);
	s.flags = 4;
	mount_stacks(str, &s);
	s.height_b = 0;
	s.a = ft_index(s.raw, s.height_a, s.flags);
	i = first_step(&s);
	leave_three(&s,i);
	sort_three(&s);
	j = 0;
	k = 0;
	while(s.height_b > 0)
	{
		i = 0;
		while(i < s.height_b)
		{
			target_pos(&s, s.b[i]);
			total_cost(&s, s.b[i], i);
			i++;
		}
		min = find_min(&s);
		print_grid(&s);
		printf("min: %i\n", s.b[min][0]);
		exec_move(&s, min);
		j = 1;
		while(j < s.flags)
		{
			reset_flag(j, s.b, s.height_b);
			j++;
		}
		k++;
	}
	align(&s);
	ft_printf("moves: %i\n", s.moves);
	return(0);
}