/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:13:16 by algalian          #+#    #+#             */
/*   Updated: 2024/04/03 13:13:23 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	perfectly_sorted(t_stacks *s)
{
	free_array(s->height_a, s->a);
	free(s->b);
	exit(0);
}

static int	easy_short(t_stacks *s)
{
	int	i;

	i = 0;
	while (s->a[i][0] != 1)
		i++;
	while (i < s->height_a - 1)
	{
		if (s->a[i][0] + 1 != s->a[i + 1][0])
			return (-1);
		i++;
	}
	return (i);
}

void	identity_test(t_stacks *s)
{
	int	i;
	int	j;
	int	n;

	i = easy_short(s);
	if (i == -1)
		return ;
	if (s->a[0][0] == 1)
		perfectly_sorted(s);
	n = s->a[i][0];
	if (s->a[i - 1][0] + 1 != n && !(s->a[i - 1][0] == s->height_a && n == 1))
		return ;
	j = 0;
	while (s->a[j + 1][0] != 1)
	{
		if (s->a[j][0] + 1 != s->a[j + 1][0])
			return ;
		j++;
	}
	align(s);
	perfectly_sorted(s);
}
