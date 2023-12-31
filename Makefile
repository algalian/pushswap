NAME		= push_swap


SRCS		= main.c \
			utils.c \
			moves.c \

OBJS		= $(SRCS:%.c=%.o)


LIBFT		= libft/libft.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I libft


${NAME}: ${OBJS}
	@make  -sC libft
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME) 

clean:
	@make clean -sC libft
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -sC libft
	@rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus