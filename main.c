#include"push_swap.h"

static void	num_ok(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
		{
			ft_printf("Error 4\n");
			exit(2);
		}
		i++;
	}
}

static void parse_prompt(char **s)
{
	int i;
	
	i = 1;
	if(!s[i])
	{
		ft_printf("Error 1\n");
		exit(1);
	}
	while(s[i])
	{
		ft_atoi(s[i]);
		num_ok(s[i]);
		i++;
	}
}
static void mount_stacks(char **str, int height, t_stacks *s)
{
	int i;

	i = 0;
	s->a = malloc(height * sizeof(int));
	s->b = ft_calloc(height, sizeof(int));
	while (i < height)
	{
		s->a[i] = ft_atoi(str[i + 1]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stacks	s;
	int			i;
	
	parse_prompt(argv);
	mount_stacks(argv, argc - 1, &s);
	i = 0;
	while (s.a[i])
	{
		ft_printf("%i\n", s.a[i]);
		i++;
	}
	return (0);
}