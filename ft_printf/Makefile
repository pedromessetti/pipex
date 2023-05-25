.SILENT:
# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m
NAME = libftprintf.a

CC = cc

CME = ar -rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_putnbr_base.c \
ft_putunsnbr.c 

OBJS = $(SRCS:.c=.o)

${NAME}:	${OBJS}
			${CME} ${NAME} ${OBJS}
			echo "$(GREEN)[OK]$(NAME)$(RESET)"

all:		${NAME}

clean:
			rm -f *.o *.out

fclean:		clean
			rm -f ${NAME}

re:			fclean all

run: re
	$(MAKE) clean