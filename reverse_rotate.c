/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:37:17 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 17:37:19 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_a(t_stacks *s)
{
	int	j;
	int	*temp;

	if (s->height_a <= 1)
		return ;
	j = s->height_a - 1;
	temp = s->a[s->height_a - 1];
	while (j > 0)
	{
		s->a[j] = s->a[j - 1];
		j--;
	}
	s->a[0] = temp;
}

static void	reverse_rotate_b(t_stacks *s)
{
	int	j;
	int	*temp;

	if (s->height_b <= 1)
		return ;
	j = s->height_b - 1;
	temp = s->b[s->height_b - 1];
	while (j > 0)
	{
		s->b[j] = s->b[j - 1];
		j--;
	}
	s->b[0] = temp;
}

void	reverse_rotate(t_stacks *s, char *m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		if (m[i] == 'a')
			reverse_rotate_a(s);
		if (m[i] == 'b')
			reverse_rotate_b(s);
		i++;
	}
	ft_printf("rr");
	if (i == 1)
	{
		ft_printf("%c\n", m[0]);
		s->moves++;
		return ;
	}
	ft_printf("r\n");
	s->moves++;
}
