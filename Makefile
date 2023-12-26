SRCS = ft_printf_base.c		\
		ft_print_unsigned.c		\
		ft_printf.c		\
		ft_utils.c 	\
	
NAME = libftprintf.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

LIBFT_PATH = ./Libft
LIBFT =	$(LIBFT_PATH)/libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o: %.c ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@clang $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "Printf Done !"

all: $(NAME)

bonus:				all

clean:
	rm -rf $(OBJS_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re libft

