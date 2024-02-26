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
	int **b;
    int height_a;
	int height_b;
	int *raw;
	int moves;
	int flags;
}	t_stacks;

void	push(t_stacks *s, char m);
void	swap(t_stacks *s, char *m);
void	rotate(t_stacks *s, char *m);
void	reverse_rotate(t_stacks *s, char *m);
void	sort_three(t_stacks *s);
void    print_stacks(t_stacks *s);
void	print_grid(t_stacks *s);
void	reset_flag(int flag, int **stack, int height);
int		**ft_index(int *stack_a, int stack_size, int flags);
void	mount_stacks(char **str, t_stacks *s);
void	parse_args(char **s, t_stacks *stack);

#endif