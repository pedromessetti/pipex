.SILENT:
# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m

NAME = libft.a

CC = cc

CME = ar -rcs

CFLAGS = -Wall -Wextra -Werror -g -I inc

SRCS = src/ft_isalpha.c src/ft_isalnum.c src/ft_isascii.c src/ft_isnum.c src/ft_isprint.c src/ft_isalpha.c \
src/ft_tolower.c src/ft_toupper.c src/ft_str_is_space.c src/ft_split.c src/ft_strdup.c src/ft_strjoin.c src/ft_strlcat.c \
src/ft_strlcpy.c src/ft_strlen.c src/ft_strncmp.c src/ft_strtrim.c src/ft_substr.c  src/ft_strchr.c \
src/ft_strrchr.c src/ft_strmapi.c src/ft_striteri.c src/ft_strnstr.c src/ft_bzero.c src/ft_memcpy.c \
src/ft_memset.c src/ft_memmove.c src/ft_memchr.c src/ft_memcmp.c src/ft_calloc.c src/ft_atoi.c \
src/ft_itoa.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_putnbr_base_fd.c \
src/ft_printf/ft_printf.c src/ft_printf/ft_putchar.c src/ft_printf/ft_putnbr.c src/ft_printf/ft_putstr.c src/ft_printf/ft_putunsnbr.c src/ft_printf/ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CME) $(NAME) $(OBJS)
	echo "$(GREEN)[OK] $(WHITE)$(NAME)$(RESET)" 

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) 

re:	fclean all

run: all clean