/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:01:46 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 17:01:49 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first(t_stacks *s, int max)
{
	if (s->a[1][0] == max - 1)
	{
		swap(s, "a");
		reverse_rotate(s, "a");
		return ;
	}
	rotate(s, "a");
}

static void	second(t_stacks *s, int max)
{
	if (s->a[0][0] == max - 1)
	{
		reverse_rotate(s, "a");
		return ;
	}
	swap(s, "a");
	rotate(s, "a");
}

static void	third(t_stacks *s, int max)
{
	if (s->a[1][0] == max - 1)
		return ;
	swap(s, "a");
}

void	sort_three(t_stacks *s, int max)
{
	if (max == s->a[0][0])
	{
		first(s, max);
		return ;
	}
	if (max == s->a[1][0])
	{
		second(s, max);
		return ;
	}
	if (max == s->a[2][0])
	{
		third(s, max);
		return ;
	}
}
