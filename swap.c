/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:41:43 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 17:41:45 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_and_account(t_stacks *s, char *m)
{
	ft_printf("s");
	if (ft_strlen(m) == 1)
	{
		ft_printf("%c\n", m[0]);
		s->moves++;
		return ;
	}
	ft_printf("s\n");
	s->moves++;
}

void	swap(t_stacks *s, char *m)
{
	int	i;

	i = 0;
	if (s->height_a <= 1)
	{
		i++;
		if (s->height_b <= 1)
			return ;
	}
	while (m[i])
	{
		if (m[i] == 'a')
			ft_swap(s->a[0], s->a[1]);
		if (m[i] == 'b')
		{
			if (s->height_b <= 1)
				return ;
			ft_swap(s->b[0], s->b[1]);
		}
		i++;
	}
	print_and_account(s, m);
}
