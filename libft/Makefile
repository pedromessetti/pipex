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

SRCS = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isnum.c ft_isprint.c ft_isalpha.c \
ft_tolower.c ft_toupper.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strtrim.c ft_substr.c  ft_strchr.c \
ft_strrchr.c ft_strmapi.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_memcpy.c \
ft_memset.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_atoi.c \
ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_base_fd.c \
ft_printf.c ft_printf_utils.c get_next_line.c ft_strncpy.c ft_strcpy.c

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