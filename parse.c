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

void parse_args(char **s, t_stacks *stack)
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

void	mount_stacks(char **str, t_stacks *s)
{
	int	i;
	int j;

	i = 0;
	s->raw = malloc(s->height_a * sizeof(int));
	s->b = malloc(s->height_a * sizeof(int*));
	while (i < s->height_a)
	{
		s->raw[i] = ft_atoi(str[i]);
		j = 1;
		s->b[i] = malloc(s->flags*sizeof(int));
		while(j < s->flags)
		{
			s->b[i][j]= 0;
			j++;
		}
		i++;
	}

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
		return (NULL);
	while (++i < stack_size)
	{
		while (++j < stack_size)
			if (stack_a[i] > stack_a[j])
				index++;
		stack_index[i] = malloc(sizeof(int) * flags);
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
	return (stack_index);
}