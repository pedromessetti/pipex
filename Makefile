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
CFLAGS = -I inc -g -Wall -Wextra -Werror -fsanitize=address

# Source and object files
SRCS = src/main.c src/path.c src/list_utils.c src/checks.c src/ft_utils.c src/child_process.c src/here_doc.c
OBJS = $(SRCS:.c=.o)

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
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(WHITE)	$(NAME)"
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(GREEN)SUCCESSFULLY COMPILED$(RESET)"

# Build pipex executable
all: $(NAME)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Rebuild the project and remove object files
run: re
	$(MAKE) clean

# Show help message
help:
	echo "Usage: make [target]"
	echo ""
	echo "Targets:"
	echo "  all        Build the pipex executable"
	echo "  clean      Remove object files"
	echo "  fclean     Remove object files and the executable"
	echo "  re         Rebuild the project"
	echo "  run        Rebuild the project and remove object files"

# Define repeat_char function
define repeat_char
$(strip $(if $(firstword $(1)), $(CHAR)$(call repeat_char,$(subst $(firstword $(1)),,$(1)))))
endef