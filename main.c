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
	int *temp;

	i = 0;
	while(s->a[i][0] != 1)
		i++;
	temp = s->a[i];
	if(i <= s->height_a / 2)
		while(s->a[0][0] != temp[0])
			rotate(s,"a");
	else
		while(s->a[0][0] != temp[0])
			reverse_rotate(s,"a");
}



int	main(int argc, char **argv)
{
	t_stacks	s;
	char		**str;
	int			i;
	int			min;


	str = check_args(argc, argv, &s);
	s.flags = 4;
	init_stacks(str, &s);
	s.height_b = 0;
	s.a = ft_index(s.raw, s.height_a, s.flags);
	if(s.height_a < 3)
	{
		if(s.height_a < 2)
		{		
			free_array(s.height_a, s.a);
			free(s.b);
			return(0);
		}
		if(s.a[0][0] > s.a[1][0])
		{
			swap(&s, "a");
			free_array(s.height_a, s.a);
			free(s.b);
			return(0);
		}
		free_array(s.height_a, s.a);
		free(s.b);
		return(0);
	}
	i = first_step(&s);
	leave_three(&s,i);
	sort_three(&s);
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
		exec_move(&s, min);
	}
	align(&s);
	free_array(s.height_a, s.a);
	free(s.b);
	return(0);
}