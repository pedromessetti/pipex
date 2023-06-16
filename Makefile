.SILENT:

# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m

# Executable name
NAME = pipex

# Compiler options
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CFLAGS_BONUS = -Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS = -I mandatory/inc -g
LDFLAGS_BONUS = -I bonus/inc

# Source and object files
SRCS = mandatory/src/main.c mandatory/src/path.c mandatory/src/list_utils.c \
mandatory/src/checks.c mandatory/src/ft_utils.c mandatory/src/child_process.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = bonus/src/main_bonus.c bonus/src/path_bonus.c bonus/src/list_utils_bonus.c \
bonus/src/checks_bonus.c bonus/src/ft_utils_bonus.c bonus/src/child_process_bonus.c bonus/src/here_doc_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Formatting characters
CHAR = =-=
NUM = 7
REPEATED_CHARS = $(call repeat_char,$(shell seq $(NUM)))

# Default target
$(NAME):	$(OBJS)
	if [ ! -f ./libft/libft.a ]; then \
		$(MAKE) run -C ./libft/; \
	fi
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	echo "\\n$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(WHITE)	$(NAME)"
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(GREEN)SUCCESSFULLY COMPILED$(RESET)\\n"

# Build pipex executable
all: $(NAME)

# Clean object files
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME) ./libft/libft.a

# Rebuild the project
re: fclean all

# Rebuild the project and remove object files
run: re
	$(MAKE) clean

bonus: $(OBJS_BONUS)
	if [ ! -f ./libft/libft.a ]; then \
		$(MAKE) run -C ./libft/; \
	fi
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) -L./libft -lft -o $(NAME)
	echo "$(GREEN)[OK] $(WHITE)BONUS$(RESET)" 


# Define repeat_char function
define repeat_char
$(strip $(if $(firstword $(1)), $(CHAR)$(call repeat_char,$(subst $(firstword $(1)),,$(1)))))
endef