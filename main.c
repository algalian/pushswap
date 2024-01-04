#include"push_swap.h"

static void	num_ok(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
		{
			ft_printf("Error\n");
			exit(2);
		}
		i++;
	}
}

static void parse_args(char **s)
{
	int	i;
	int j;

	if(!s)
	{
		ft_printf("Error\n");
		exit(1);
	}
	i = 1;
	while(s[i])
	{
		ft_atoi(s[i]);
		num_ok(s[i]);
		i++;
	}
	i = 1;
	while(s[i])
	{
		j = i + 1;
		while(s[j])
		{
			if(ft_strncmp(s[i], s[j], ft_max(ft_strlen(s[i]),ft_strlen(s[j]))) == 0)
			{
				ft_printf("Error");
				exit(1);
			}
			j++;
		}
		i++;	
	}
}

static void	mount_stacks(char **str, t_stacks *s)
{
	int	i;

	i = 0;
	s->raw = malloc(s->height_a * sizeof(int));
	s->b = ft_calloc(s->height_a, sizeof(int));
	while (i < s->height_a)
	{
		s->raw[i] = ft_atoi(str[i + 1]);
		i++;
	}
}

static int	*ft_index(int *stack_a, int stack_size)
{
	int	i;
	int	j;
	int	index;
	int	*stack_index;

	i = -1;
	j = -1;
	index = 1;
	stack_index = malloc(sizeof(int) * (stack_size + 1));
	if (!stack_index)
		return (NULL);
	stack_index[stack_size] = '\0';
	while (++i < stack_size)
	{
		while (++j < stack_size)
			if (stack_a[i] > stack_a[j])
				index++;
		stack_index[i] = index;
		index = 1;
		j = -1;
	}
	return (stack_index);
}

static void	print_stacks(t_stacks *s) //for debugging
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

static void	first_move(t_stacks *s)
{
	while(s->height_a > 4)
	{
		if(s->a[0] < s->height_a/2 + 1)
		{
			push(s,'b');
			print_stacks(s);
		}
		else
		{
			rotate(s, "a");
			print_stacks(s);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	s.height_a = argc - 1;
	s.height_b = 0;
	parse_args(argv);
	mount_stacks(argv, &s);
	s.a = ft_index(s.raw, s.height_a);
	print_stacks(&s);
	first_move(&s);
	return (0);
}
