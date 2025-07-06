NAME = philosopher
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g
SRCS = main.c free_functions.c print_status.c error_functions.c initialisation.c executor.c parseing.c mutex_and_phtread_safety.c philosophers_routine_describe.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBS = -lpthread
.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
# This Makefile compiles a multi-threaded program that simulates philosophers eating.
# It includes rules for building the executable, cleaning object files, and fully cleaning the build directory.
# The program is built using GCC with specified flags for warnings and threading support.
# The source files are compiled into object files, which are then linked to create the final executable.
# The Makefile also includes phony targets to ensure that the commands are always executed.
# The `all` target builds the executable, while `clean` removes object files, and `fclean` removes both object files and the executable.