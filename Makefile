NAME	=	pipex

LIBFT	=	./includes/libft/libft.a
GNL		=	./includes/get_next_line/gnl.a
PRINTF	=	./includes/ft_printf/libftprintf.a
SOURCES	=	./srcs/srcs.a

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I ./includes/libft -I ./includes/get_next_line -I ./includes/ft_printf -I ./srcs -g -g3

SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(LIBFT) $(GNL) $(PRINTF) $(SOURCES) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SOURCES) $(LIBFT) $(GNL) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(dir $(LIBFT))

$(GNL):
	make -C $(dir $(GNL))

$(PRINTF):
	make -C $(dir $(PRINTF))

$(SOURCES):
	make -C $(dir $(SOURCES))

clean:
	rm -rf $(OBJS)
	make -C $(dir $(LIBFT)) clean
	make -C $(dir $(GNL)) clean
	make -C $(dir $(PRINTF)) clean
	make -C $(dir $(SOURCES)) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(dir $(LIBFT)) fclean
	make -C $(dir $(GNL)) fclean
	make -C $(dir $(PRINTF)) fclean
	make -C $(dir $(SOURCES)) fclean

re: fclean all

.PHONY: all clean fclean re