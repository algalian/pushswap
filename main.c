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

static void mount_stacks(char **str, t_stacks *s)
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

int *ft_index(int *stack_a, int stack_size)
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

/*static void first_sort(t_stacks *s)
{
	int i;
	
	while(i < s->height - 3)
	{
		if(s->a[i] < (s->height / 2) + 1)
		{
			pb(&s);
		}
		ra(&s);
	}
	
}*/

void test_moves(t_stacks *s)
{

	push(s, 'a');
	push(s, 'b');
	push(s, 'a');
	push(s, 'a');
	swap(s, "a");
	swap(s, "b");
	swap(s, "ab");
	rotate(s, "a");
	rotate(s, "b");
	rotate(s, "ab");
	reverse_rotate(s, "a");
	reverse_rotate(s, "b");
	reverse_rotate(s, "ab");	
}

int main(int argc, char **argv)
{
	t_stacks	s;
	int i;
	int j;

	s.height_a = argc - 1;
	s.height_b = 0; 
	parse_args(argv);
	mount_stacks(argv, &s);
	s.a = ft_index(s.raw, s.height_a);
	i = 0;
	printf("A     B\n");
	while(i < 2)
	{	
		test_moves(&s);
		j = 0;
		while(j < 5)
		{
			printf("%i     %i\n",s.a[j],s.b[j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
