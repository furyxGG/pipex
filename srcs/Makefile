NAME	=	srcs.a

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I ../includes/libft -I ../includes/get_next_line -I ../includes/ft_printf

SRCS	=	pipex.c			\
			parser.c		\
			check_command.c	\
			helper.c		\
			fork_helper.c	\
			exec_helper.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re