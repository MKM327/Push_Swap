SRCS = init_stacks.c push_swap.c sort_three_numbers.c \
stack_operations.c sort_five_numbers.c handle_args.c \
big_stack_utils.c sort_big_stack.c calculate_min_steps.c \


OBJS			= $(SRCS:.c=.o)

NAME			= push_swap.a
CC = gcc
#CFLAGS = -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
	make -C libft/
	ar rc $(NAME) $(OBJS) libft/*.o
	mv *.o ./objs
	gcc -o push_swap $(NAME)

clean:
	make clean -C libft/
	rm -f ./objs/*.o

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -f push_swap
re: fclean all
