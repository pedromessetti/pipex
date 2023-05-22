NAME = libftprintf.a

CC = cc

CME = ar -rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_putnbr_base.c \
ft_putunsnbr.c \
ft_putaddr.c
                     
OBJS = $(SRCS:.c=.o)

${NAME}:	${OBJS}
			${CME} ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f *.o *.out

fclean:		clean
			rm -f ${NAME}

re:			fclean all

compile:	re
	cc *.c

run:	compile
	./a.out