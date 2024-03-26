/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:07:38 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 18:07:39 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	first_step(t_stacks *s)
{
	int	largest;

	largest = s->height_a;
	while (s->height_a > 3 && s->a[0][1] == 0)
	{
		if (s->a[0][0] < (s->height_a / 2) + 1)
			push(s, 'b');
		else
		{
			s->a[0][1] = 1;
			rotate(s, "a");
		}
	}
	reset_flag(1, s->a, s->height_a);
	return (largest);
}

static void	leave_three(t_stacks *s, int largest)
{
	int	i;

	i = 0;
	while (s->height_a > 3)
	{
		if (s->a[0][0] <= largest - 3)
			push(s, 'b');
		else
			rotate(s, "a");
		i++;
	}
}

static void	align(t_stacks *s)
{
	int	i;
	int	*temp;

	i = 0;
	while (s->a[i][0] != 1)
		i++;
	temp = s->a[i];
	if (i <= s->height_a / 2)
		while (s->a[0][0] != temp[0])
			rotate(s, "a");
	else
		while (s->a[0][0] != temp[0])
			reverse_rotate(s, "a");
}

static void	main_sort(t_stacks *s)
{
	int	i;
	int	min;

	while (s->height_b > 0)
	{
		i = 0;
		while (i < s->height_b)
		{
			target_pos(s, s->b[i]);
			total_cost(s, s->b[i], i);
			i++;
		}
		min = find_min(s);
		exec_move(s, min);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	char		**str;
	int			i;

	str = check_args(argc, argv, &s);
	s.flags = 4;
	init_stacks(str, &s);
	s.height_b = 0;
	s.a = ft_index(s.raw, s.height_a, s.flags);
	less_than_three(&s);
	i = first_step(&s);
	leave_three(&s, i);
	sort_three(&s, s.height_a + s.height_b);
	main_sort(&s);
	align(&s);
	free_array(s.height_a, s.a);
	free(s.b);
	return (0);
}
