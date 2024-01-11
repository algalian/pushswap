#include"push_swap.h"

static void	num_ok(char *str)
{
	int	i;

	i = 0;
	if(!str)
	{
		ft_printf("Error 3 \n");
		exit(2);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			ft_printf("Error 4\n");
			exit(2);
		}
		i++;
	}
}

static void parse_args(char **s, t_stacks *stack)
{
	int	i;
	int j;

	i = 0;
	while(s[i])
	{
		num_ok(s[i]);
		ft_atoi(s[i]);
		i++;
	}
	stack->height_a = i;
	i = 0;
	while(s[i])
	{
		j = i + 1;
		while(s[j])
		{
			if(ft_strncmp(s[i], s[j], ft_max(ft_strlen(s[i]),ft_strlen(s[j]))) == 0)
			{
				ft_printf("Error 5");
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
		s->raw[i] = ft_atoi(str[i]);
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


static void first_move(t_stacks *s)
{
	int largest;

	largest = s->height_a;
	while(s->height_a > 3)
	{
		if(s->a[0] < largest - 2)
			push(s, 'b');
		else
			rotate(s, "a");
	}
}

static void sort_b(t_stacks *s)
{
	int i;

	i = 0;
	while(s->b[i] + 1 != s->a[0])
		i++;
	if(i < s->height_b / 2)
	{
		while(s->b[0] + 1 != s->a[0])
			rotate(s, "b");
		push(s, 'a');
		return;
	}
	while(s->b[0] + 1 != s->a[0])
		reverse_rotate(s, "b");
	push(s, 'a');
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
	mount_stacks(str, &s);
	s.height_b = 0;
	s.a = ft_index(s.raw, s.height_a);
	first_move(&s);
	while(s.height_a > 3)
		push(&s,'b');
	sort_three(&s);
	while(s.height_b >= 1)
		sort_b(&s);
	return(0);
}
