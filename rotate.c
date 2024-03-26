/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:29:22 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 17:29:24 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_stacks *s)
{
	int	j;
	int	*temp;

	if (s->height_a <= 1)
		return ;
	j = 0;
	temp = s->a[0];
	while (j < s->height_a)
	{
		s->a[j] = s->a[j + 1];
		j++;
	}
	s->a[j - 1] = temp;
}

static void	rotate_b(t_stacks *s)
{
	int	j;
	int	*temp;

	if (s->height_b <= 1)
		return ;
	j = 0;
	temp = s->b[0];
	while (j < s->height_b)
	{
		s->b[j] = s->b[j + 1];
		j++;
	}
	s->b[j - 1] = temp;
}

void	rotate(t_stacks *s, char *m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		if (m[i] == 'a')
			rotate_a(s);
		if (m[i] == 'b')
			rotate_b(s);
		i++;
	}
	ft_printf("r");
	if (ft_strlen(m) == 1)
	{
		ft_printf("%c\n", m[0]);
		s->moves++;
		return ;
	}
	ft_printf("r\n");
	s->moves++;
}
