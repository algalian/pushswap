/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:20:42 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 17:20:44 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b(t_stacks *s)
{
	int	i;

	if (s->height_a < 1)
		return ;
	s->height_a--;
	s->height_b++;
	i = s->height_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = s->a[0];
	i = 0;
	while (i < s->height_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = 0;
}

static void	push_a(t_stacks *s)
{
	int	i;

	if (s->height_b < 1)
		return ;
	s->height_a++;
	s->height_b--;
	i = s->height_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = s->b[0];
	i = 0;
	while (i < s->height_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
}

void	push(t_stacks *s, char m)
{
	if (m == 'b')
		push_b(s);
	if (m == 'a')
		push_a(s);
	ft_printf("p%c\n", m);
	s->moves++;
}
