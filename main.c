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
static int	ft_blanks(char *c)
{
	int i;
	 
	i = 0;
	while (c[i])
	{
		if(c[i] < 33 || c[i] > 125)
		{
			return (0);
		}
	}
	return (1);
}

static void parse_args(char **s, t_stacks *stacks)
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
		if(ft_blanks(s[i]) == 0);
		{
			ft_atoi(s[i]);
			num_ok(s[i]);
		}
		i++;
	}
	i = 1;
	while(s[i])
	{
		if(ft_blanks(s[i]) == 1)
		{	
			i++;
			stacks->height--;
		}
		j = i + 1;
		while(s[j])
		{
			if(ft_blanks(s[j]) == 1)
				j++;
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

static void mount_stacks(char **str, t_stacks *s)
{
	int	i;

	i = 0;
	s->a = malloc(s->height * sizeof(int));
	s->b = ft_calloc(s->height, sizeof(int));
	while (i < s->height)
	{
		s->a[i] = ft_atoi(str[i + 1]);
		i++;
	}
}

int *index(int *stack_a, int stack_size)
{
	int	i;
	int	j;
	int	index;
	int	*stack_index;

	i = -1;
	j = -1;
	index = 0;
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
		index = 0;
		j = -1;
	}
	return (stack_index);
}
int main(int argc, char **argv)
{
	t_stacks	s;

	s.height = argc - 1;
	parse_args(argv, &s);
	mount_stacks(argv, &s);
	s.index = index(s.a, s.height);

	return (0);
}
