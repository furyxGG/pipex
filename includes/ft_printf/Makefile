NAME		=		libftprintf.a

CC			=		cc
CFLAGS		=	-Wall -Werror -Wextra

SRCS 		=	ft_printf.c	\
				ft_scrnprint.c \
				ft_itoa.c

OBJS		=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
