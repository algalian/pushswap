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

static void parse_prompt(char **s)
{
	int	i;
	int j;

	i = 1;
	if(!s[i])
	{
		ft_printf("Error\n");
		exit(1);
	}
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

static void mount_stacks(char **str, int height, t_stacks *s)
{
	int	i;

	i = 0;
	s->a = malloc(height * sizeof(int));
	s->b = ft_calloc(height, sizeof(int));
	while (i < height)
	{
		s->a[i] = ft_atoi(str[i + 1]);
		i++;
	}
}


int median_of_three(int a, int b, int c)
{
	if (a > b)
	{	
        if(a > c)
		{
			if(b > c)
                return(b);
            return(c);
		}
        return(a);
    }
    if(a < c)
    {    
        if(b < c) 
            return(b);
        return(c);
    }
    return(a);
}

static void index(t_stacks *s)
{
	int *c;
	int i;
	int p;

	c = malloc(sizeof(int) * s->height);
	c = ft_memcpy(c, s->a, s->height * sizeof(int));
	p = median_of_three(c[0], c[s->height / 2], c[s->height]);
	
}

int main(int argc, char **argv)
{
	t_stacks	s;
	
	parse_prompt(argv);
	mount_stacks(argv, argc - 1, &s);
	index(&s);
	return (0);
}