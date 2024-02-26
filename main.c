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
	while(s->height_a > 3 && i < 30)
	{
		if(s->a[0][0] <= largest - 3)
			push(s, 'b');
		else
			rotate(s, "a");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		**str;
	int			i;
	int			j;

	if(!argv[1])
	{
		ft_printf("Error 1 \n");
		return(1);
	}
	if(argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if(!str[0])
		{
			ft_printf("Error 2 \n");
			return(2);
		}
		parse_args(str, &s);
	}
	else
	{
		i = 1;
		while(argv[i])
			i++;
		str = (char **) malloc(sizeof(char*) * (i + 1));
		j = 0;
		while(j < i - 1)
		{
			str[j] = ft_strdup(argv[j + 1]);
			j++;
		}
		str[j] = NULL;
		parse_args(str, &s);
	}
	s.flags = 8;
	mount_stacks(str, &s);
	s.height_b = 0;
	s.a = ft_index(s.raw, s.height_a, s.flags);
	i = first_step(&s);
	leave_three(&s,i);
	sort_three(&s);
	print_stacks(&s);
	return(0);
}