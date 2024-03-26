/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:49:17 by algalian          #+#    #+#             */
/*   Updated: 2024/03/26 17:49:20 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct stacks
{
	int	**a;
	int	**b;
	int	height_a;
	int	height_b;
	int	*raw;
	int	moves;
	int	flags;
}	t_stacks;

void	push(t_stacks *s, char m);
void	swap(t_stacks *s, char *m);
void	rotate(t_stacks *s, char *m);
void	reverse_rotate(t_stacks *s, char *m);
void	sort_three(t_stacks *s, int max);
void	reset_flag(int flag, int **stack, int height);
int		**ft_index(int *stack_a, int stack_size, int flags);
char	**check_args(int argc, char **argv, t_stacks *s);
int		find_min(t_stacks *s);
int		ft_highest(t_stacks *s, int **a);
void	target_pos(t_stacks *s, int *b);
void	total_cost(t_stacks *s, int *b, int n);
void	free_string(char **s);
void	free_array(int h, int **a);
void	init_stacks(char **str, t_stacks *s);
void	exec_move(t_stacks *s, int index);
void	malloc_error(void *s);
void	less_than_three(t_stacks *s);

#endif
