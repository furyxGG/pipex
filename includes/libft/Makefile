SRCS = \
	ft_strlen.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_split.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \

OBJS = $(SRCS:.c=.o)

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

clean:
	rm -f $(OBJS)

.PHONY: all clean fclean re 
