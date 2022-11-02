NAME = philo
NAME_FS = philo_fs
MAKEFLAGS = --no-print-directory
BUILDDIR = objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
VPATH = src src/main src/args src/TESTS

# headers
INCLUDES = -I /headers

# Lists sources. Manually because of norm...
MAIN = philo.c initialization.c
ARGS = check_args.c print_help_arg.c print_help_utils.c
TESTS = PRINT_DATA.c

# Names sources
SOURCES = $(MAIN) $(ARGS) \
$(TESTS)

# Names objects
OBJS = $(addprefix $(BUILDDIR)/, $(SOURCES:%.c=%.o))

# Compiler
CC = clang
CF = -Wall -Wextra -Werror
GDB = -ggdb
VAL = valgrind --trace-children=no --leak-check=full --track-origins=yes \
		./$(NAME)
FSF = -fsanitize=address

$(NAME): $(LIBFT) $(BUILDDIR) $(OBJS)
	@printf "Compiling philosophers...\n"
	@$(CC) $(CF) $(OBJS) $(INCLUDES) $(LIBFT) -lpthread -o $(NAME)
	@printf "Done!\n"

$(NAME_FS): $(LIBFT) $(OBJS)
	@$(CC) $(CF) $(FSF) $(OBJS) $(INCLUDES) $(LIBFT) -o $(NAME_FS)

$(NAME_TEST): $(LIBFT) $(TEST_OBJS)
	@printf "Compiling test files...\n"
	@$(CC) $(CF) $(TEST_OBJS) $(INCLUDES) $(LIBFT) -o $(NAME_TEST)

$(LIBFT):
	@printf "Compiling libft...\n"
	@make -C $(LIBFT_DIR)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.c
	@$(CC) $(CF) $(GDB) $(INCLUDES) -c $< -o $@

all: $(NAME)

fs: $(NAME_FS)

test:
	@make -C tests/
	@printf "\n"
	@./tests/tester

clean:
	@rm -rf $(BUILDDIR)
	@rm -f vgcore*
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_FS)
	@rm -f vgcore*
	@make fclean -C $(LIBFT_DIR)

re: fclean all

# from here on shit ain't mandatory or bonus
run: all
	$(VAL)

fs: $(NAME_FS)
	./$(NAME_FS)

git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
