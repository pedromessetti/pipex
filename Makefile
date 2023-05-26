.SILENT:
# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m

NAME = pipex

CC = cc

CFLAGS =  -g -I inc #-fsanitize=address

OTHERFLAG = ./ft_printf/libftprintf.a

SRCS = src/main.c src/path.c src/list_utils.c src/checks.c

OBJS = $(SRCS:.c=.o)

CHAR = =-=
NUM = 7
REPEATED_CHARS = $(call repeat_char,$(shell seq $(NUM)))

all: $(NAME)

$(NAME):	$(OBJS)
	make  -C ./ft_printf/; \
	make  -C ./libft/; \
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a ./libft/libft.a -o $(NAME)
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(WHITE)	$(NAME)" | tr '[:lower:]' '[:upper:]'
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(GREEN)SUCCESSFULLY COMPILED$(RESET)"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	$(MAKE) clean

define repeat_char
$(strip $(if $(firstword $(1)), $(CHAR)$(call repeat_char,$(subst $(firstword $(1)),,$(1)))))
endef
