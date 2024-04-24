/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:27:12 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 14:27:16 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(char **str, t_stacks *s)
{
	int	i;

	i = 0;
	s->raw = malloc(s->height_a * sizeof(int));
	malloc_error(s->raw);
	s->b = malloc(s->height_a * sizeof(int *));
	malloc_error(s->b);
	while (i < s->height_a)
	{
		s->raw[i] = ft_atoi(str[i], str);
		i++;
	}
	s->height_b = 0;
	s->flags = 4;
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
	stack_index = malloc(sizeof(int *) * (stack_size + 1));
	malloc_error(stack_index);
	while (++i < stack_size)
	{
		while (++j < stack_size)
			if (stack_a[i] > stack_a[j])
				index++;
		stack_index[i] = malloc(sizeof(int) * flags);
		malloc_error(stack_index[i]);
		stack_index[i][0] = index;
		index = 1;
		j = -1;
	}
	free(stack_a);
	return (stack_index);
}
