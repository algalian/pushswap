/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:05:33 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 15:06:02 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_flag(int flag, int **stack, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		stack[i][flag] = 0;
		i++;
	}
}

void	free_string(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_array(int h, int **a)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

void	less_than_three(t_stacks *s)
{
	if (s->height_a < 3)
	{
		if (s->height_a < 2)
		{
			free_array(s->height_a, s->a);
			free(s->b);
			exit(0);
		}
		if (s->a[0][0] > s->a[1][0])
		{
			swap(s, "a");
			free_array(s->height_a, s->a);
			free(s->b);
			exit(0);
		}
		free_array(s->height_a, s->a);
		free(s->b);
		exit(0);
	}
}
