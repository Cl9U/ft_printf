NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I.
HEADER = ft_printf.h
LIBFT = ./libft
SRCS = ft_printf.c \
	   ft_parse.c \
	   ft_print_char.c \
	   ft_print_str.c \
	   ft_print_ptr.c \
	   ft_print_nbr.c \
	   ft_print_unsigned.c \
	   ft_print_hex_low.c \
	   ft_print_hex_up.c \
	   ft_print_percent.c \
	   ft_printchar_count.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re