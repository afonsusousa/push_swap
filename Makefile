NAME				= push_swap
CHECKER				= checker

LIBFT				= ./libft/libft.a
INC					= ./
SRC_DIR				= ./src/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g -fPIE -I
RM					= rm -f

PUSH_SWAP_OPERATIONS =	src/push_swap/operations/push.c \
						src/push_swap/operations/rev_rotate.c \
						src/push_swap/operations/rotate.c \
						src/push_swap/operations/swap.c

PUSH_SWAP_UTILS		= 	src/push_swap/utils/init.c \
                    	src/push_swap/utils/stack_utils.c \
                    	src/push_swap/utils/atol.c \
                    	src/push_swap/utils/costs.c \
                    	src/push_swap/utils/insertions.c \
                    	src/push_swap/utils/sort_utils.c \
                    	src/push_swap/utils/sort.c \
                    	src/push_swap/utils/indexes.c \
                    	src/push_swap/utils/targets.c \
                    	src/push_swap/utils/lis.c \
                    	src/push_swap/utils/errors.c \
                    	src/push_swap/utils/sort_search.c

PUSH_SWAP_MAIN		= 	src/push_swap/push_swap.c 

CHECKER_OPERATIONS	= 	src/checker/operations/push.c \
						src/checker/operations/rev_rotate.c \
						src/checker/operations/rotate.c \
						src/checker/operations/swap.c

CHECKER_UTILS		= 	src/checker/utils/atol.c \
						src/checker/utils/errors.c \
						src/checker/utils/parse_operations.c \
						src/checker/utils/parse_stacks.c \
						src/checker/utils/stack_utils.c

CHECKER_GNL			= 	src/checker/get_next_line/get_next_line.c \
						src/checker/get_next_line/get_next_line_utils.c

CHECKER_MAIN			= 	src/checker/checker.c

PUSH_SWAP_SRCS		= $(PUSH_SWAP_OPERATIONS) $(PUSH_SWAP_UTILS) $(PUSH_SWAP_MAIN)
CHECKER_SRCS		= $(CHECKER_OPERATIONS) $(CHECKER_UTILS) $(CHECKER_GNL) $(CHECKER_MAIN)

PUSH_SWAP_OBJ		= $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJ			= $(CHECKER_SRCS:.c=.o)

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

bonus:				$(CHECKER)

$(NAME): 			$(PUSH_SWAP_OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(PUSH_SWAP_OBJ) $(LIBFT) -o $(NAME)
					@echo "push_swap compiled successfully!"

$(CHECKER): 		$(CHECKER_OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(CHECKER_OBJ) $(LIBFT) -o $(CHECKER)
					@echo "checker compiled successfully!"

%.o: %.c
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME) $(CHECKER)
					@$(RM) $(LIBFT)

re: 				fclean all

re_bonus:			fclean bonus

.PHONY: 			start all bonus clean fclean re re_bonus
