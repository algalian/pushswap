#include"push_swap.h"

void	init_stacks(char **str, t_stacks *s)
{
	int	i;
	int j;

	i = 0;
	s->raw = malloc(s->height_a * sizeof(int));
	if(!s->raw)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
	s->b = malloc(s->height_a * sizeof(int*));
	if(!s->b)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
	while (i < s->height_a)
	{
		s->raw[i] = ft_atoi(str[i]);
		i++;
	}
	free_string(str);
}

int	**ft_index(int *stack_a, int stack_size, int flags)
{
	int	i;
	int	j;
	int	index;
	int	**stack_index;

	i = -1;
	j = -1;
	index = 1;
	stack_index = malloc(sizeof(int*) * (stack_size + 1));
	if (!stack_index)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
	while (++i < stack_size)
	{
		while (++j < stack_size)
			if (stack_a[i] > stack_a[j])
				index++;
		stack_index[i] = malloc(sizeof(int) * flags);
		if(!stack_index[i])
		{
			ft_printf("malloc error\n");
			exit(1);
		}
		stack_index[i][0] = index;
		index = 1; 
		j = -1;
	}
	i = 0;
	while(i < stack_size)
	{
		j = 1;
		while(j < flags)
		{
			stack_index[i][j] = 0;
			j++;
		}
		i++;
	}
	free(stack_a);
	return (stack_index);
}