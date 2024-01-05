#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct stacks
{
	int	*a;
	int *b;
    int height_a;
	int height_b;
	int *raw;
	int moves;
	int *pos_a;
	int *pos_b;
}	t_stacks;

void	push(t_stacks *s, char m);
void	swap(t_stacks *s, char *m);
void	rotate(t_stacks *s, char *m);
void	reverse_rotate(t_stacks *s, char *m);
void	ft_switch(int *a, int *b);
void	sort_three(t_stacks *s);
void    print_stacks(t_stacks *s);
 
#endif