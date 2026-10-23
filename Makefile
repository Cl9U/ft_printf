NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= libft
INCLUDES	= -I mandatory -I bonus -I $(LIBFT)

SRCS		= mandatory/ft_printf.c \
			mandatory/ft_parse.c \
			mandatory/ft_print_char.c \
			mandatory/ft_print_str.c \
			mandatory/ft_print_ptr.c \
			mandatory/ft_print_nbr.c \
			mandatory/ft_print_unsigned.c \
			mandatory/ft_print_hex_low.c \
			mandatory/ft_print_hex_up.c \
			mandatory/ft_print_percent.c \
			mandatory/ft_printchar_count.c \
			mandatory/ft_utoa.c

SRCS_B		= bonus/ft_printf_bonus.c \
			bonus/ft_parse_bonus.c \
			bonus/ft_print_char_bonus.c \
			bonus/ft_print_str_bonus.c \
			bonus/ft_print_ptr_bonus.c \
			bonus/ft_print_nbr_bonus.c \
			bonus/ft_print_unsigned_bonus.c \
			bonus/ft_print_hex_low_bonus.c \
			bonus/ft_print_hex_up_bonus.c \
			bonus/ft_print_percent_bonus.c \
			bonus/ft_printchar_count_bonus.c \
			bonus/ft_utoa_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_B)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS_B)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re