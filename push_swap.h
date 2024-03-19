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
void	parse_args(char **s, t_stacks *stack);
char	**check_args(int argc, char **argv, t_stacks *s);
int		upwards_cost(t_stacks *s, int i, int *n);
int		downwards_cost(t_stacks *s, int *n);
int		find_min(t_stacks *s);
int		ft_highest(t_stacks *s, int **a);
void	target_pos(t_stacks *s, int *b);
void total_cost(t_stacks *s, int *b, int n);
void free_string(char **s);
void free_array(int h, int **a);
void mount_stacks(char **str, t_stacks *s);



#endif