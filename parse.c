/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:30:17 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 14:30:19 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	num_ok(char *str)
{
	int	i;

	i = 0;
	if (!str)
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

static int	parse_nums(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		num_ok(s[i]);
		ft_atoi(s[i]);
		i++;
	}
	return (i);
}

static void	parse_args(char **s, t_stacks *stack)
{
	int	i;
	int	j;

	stack->height_a = parse_nums(s);
	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (ft_strncmp(s[i], s[j],
					ft_max(ft_strlen(s[i]), ft_strlen(s[j]))) == 0)
			{
				ft_printf("Error 5");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static char	**store_string(char **argv, t_stacks *s)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (argv[i])
		i++;
	str = (char **) malloc(sizeof(char *) * (i + 1));
	malloc_error(str);
	j = 0;
	while (j < i - 1)
	{
		str[j] = ft_strdup(argv[j + 1]);
		j++;
	}
	str[j] = NULL;
	parse_args(str, s);
	return (str);
}

char	**check_args(int argc, char **argv, t_stacks *s)
{
	char	**str;

	if (!argv[1])
	{
		ft_printf("Error 1 \n");
		exit(1);
	}
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!str[0])
		{
			ft_printf("Error 2 \n");
			exit(2);
		}
		parse_args(str, s);
	}
	else
		str = store_string(argv, s);
	return (str);
}
