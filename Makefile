NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= ./libft
INCLUDE		= -I. -I$(LIBFT)
HEADER		= ft_printf.h
SRCS		= ft_printf.c \
			ft_parse.c \
			ft_print_char.c \
			ft_print_str.c \
			ft_print_ptr.c \
			ft_print_nbr.c \
			ft_print_unsigned.c \
			ft_print_hex_low.c \
			ft_print_hex_up.c \
			ft_print_percent.c \
			ft_printchar_count.c \
			ft_utoa.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re