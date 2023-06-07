CC = gcc

NAME = push_swap

NAME_BONUS = checker

LIBFT = Libft/libft.a

SRC =	source/push_swap.c \
	source/error_check.c \
	source/fill_stack.c \
	source/stack_utils.c \
	source/stack_utils2.c \
	source/swap.c \
	source/push.c \
	source/rotate.c \
	source/just_do_it.c \
	source/just_do_it2.c \
	source/manage_2to5.c \
	source/lis.c \
	source/push_wherever.c \
	source/find_move.c
	
SRC_BONUS =	source_bonus/checker.c \
		source_bonus/error_check_bonus.c \
		source_bonus/fill_stack_bonus.c \
		source_bonus/ft_command_checker.c \
		source_bonus/push_bonus.c \
		source_bonus/rotate_bonus.c \
		source_bonus/stack_utils_bonus.c \
		source_bonus/swap_bonus.c \
		source_bonus/just_do_it_bonus.c

FLAGS = -Wall -Wextra -Werror -g

all: comp

libcomp:
		@make -C Libft

comp: libcomp
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "\033[92mpush_swap ready\033[0m"

bonus: libcomp
	$(CC) $(FLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "\033[92mchecker ready\033[0m"	
	
libclean:
		@make clean -C Libft

clean:		libclean

libfclean:
		@make fclean -C Libft

fclean:   	libfclean
		rm -rf $(NAME)
		rm -rf $(NAME_BONUS)
		@echo "\033[92mpush_swap and checker removed\033[0m"
		
re: clean all

.PHONY: all re clean fclean

.SILENT:
