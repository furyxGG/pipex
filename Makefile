NAME	=	pipex

LIBFT	=	./includes/libft/libft.a
GNL		=	./includes/get_next_line/gnl.a
PRINTF	=	./includes/ft_printf/libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I ./includes/libft -I ./includes/get_next_line -I ./includes/ft_printf

SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(LIBFT) $(GNL) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(dir $(LIBFT))

$(GNL):
	make -C $(dir $(GNL))

$(PRINTF):
	make -C $(dir $(PRINTF))

clean:
	rm -rf $(OBJS)
	make -C $(dir $(LIBFT)) clean
	make -C $(dir $(GNL)) clean
	make -C $(dir $(PRINTF)) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(dir $(LIBFT)) fclean
	make -C $(dir $(GNL)) fclean
	make -C $(dir $(PRINTF)) clean

re: fclean all

.PHONY: all clean fclean re