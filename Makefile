.SILENT:
# Color variables
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #fsanitize=address

SRCS = main.c ft_utils.c

OBJS = $(SRCS:.c=.o)

CHAR = =-=
NUM = 7
REPEATED_CHARS = $(call repeat_char,$(shell seq $(NUM)))

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L. -o $(NAME)
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "	$(NAME)"| tr '[:lower:]' '[:upper:]'| tr '[:lower:]' '[:upper:]'
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(GREEN)SUCCESSFULLY COMPILED$(RESET)"
	
all: $(NAME)

clean:
	rm -f *.O

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all clean

define repeat_char
$(strip $(if $(firstword $(1)), $(CHAR)$(call repeat_char,$(subst $(firstword $(1)),,$(1)))))
endef

.PHONY: example1 example2 all clean fclean re run

example1:
	echo "This is example 1"
	echo $(REPEATED_CHARS)

example2:
	echo "This is example 2"
	echo $(REPEATED_CHARS)