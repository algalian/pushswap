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
	if(i <= s->height_a / 2)
	{
		n[4] = 1;
		return(i);			
	}
	n[4] = -1;
	return(s->height_a - i);
}

static int downwards_cost(t_stacks *s, int *n)
{
	int i;
	int j;

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

static void exec_move(t_stacks *s, int min)
{

}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		**str;
	int			i;
	int 		min;

	str = check_args(argc, argv, &s);
	s.flags = 8;
	mount_stacks(str, &s);
	s.height_b = 0;
	s.a = ft_index(s.raw, s.height_a, s.flags);
	i = first_step(&s);
	leave_three(&s,i);
	sort_three(&s);
	i = 0;
	//while(s.height_b > 0)
	//{
		s.b[i][1] = downwards_cost(&s, s.b[i]);
		s.b[i][2] = upwards_cost(&s, i, s.b[i]);
		min = find_min(&s); 
		exec_move(&s, min);
	//}
	return(0);
}