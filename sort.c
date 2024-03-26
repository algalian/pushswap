/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:20:28 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 14:20:30 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	path_one(t_stacks *s, int index)
{
	int	*temp;
	int	i;

	temp = s->b[index];
	i = 0;
	while (s->b[0][0] != temp[0] && i < temp[1])
	{
		rotate(s, "ab");
		i++;
	}
	while (s->b[0][0] != temp[0])
	{
		rotate(s, "b");
	}
	while (i < temp[1])
	{
		rotate(s, "a");
		i++;
	}
	push(s, 'a');
}

static void	path_two(t_stacks *s, int index)
{
	int	*temp;
	int	i;

	temp = s->b[index];
	i = 0;
	while (s->b[0][0] != temp[0])
	{
		rotate(s, "b");
	}
	while (i < s->height_a - temp[1])
	{
		reverse_rotate(s, "a");
		i++;
	}
	i++;
	push(s, 'a');
}

static void	path_three(t_stacks *s, int index)
{
	int	i;
	int	*temp;

	temp = s->b[index];
	i = 0;
	while (s->b[0][0] != temp[0])
	{
		reverse_rotate(s, "b");
	}
	while (i < temp[1])
	{
		rotate(s, "a");
		i++;
	}
	push(s, 'a');
}

static void	path_four(t_stacks *s, int index)
{
	int	*temp;
	int	i;

	i = 0;
	temp = s->b[index];
	while (s->b[0][0] != temp[0] && i < s->height_a - temp[1])
	{
		reverse_rotate(s, "ab");
		i++;
	}
	while (s->b[0][0] != temp[0])
	{
		reverse_rotate(s, "b");
	}
	while (i < s->height_a - temp[1])
	{
		reverse_rotate(s, "a");
		i++;
	}
	push(s, 'a');
}

void	exec_move(t_stacks *s, int index)
{
	int	*temp;

	temp = s->b[index];
	if (temp[3] == 1)
		path_one(s, index);
	if (temp[3] == 2)
		path_two(s, index);
	if (temp[3] == 3)
		path_three(s, index);
	if (temp[3] == 4)
		path_four(s, index);
}
