# Standard
NAME				= push_swap
CHECKER				= checker

# Directories
LIBFT				= ./libft/libft.a
INC					= ./
SRC_DIR				= ./src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g -I
RM					= rm -f

# Push_swap Source Files
PUSH_SWAP_OPERATIONS =	src/push_swap/operations/push.c \
						src/push_swap/operations/rev_rotate.c \
						src/push_swap/operations/rotate.c \
						src/push_swap/operations/swap.c

PUSH_SWAP_UTILS		=	src/push_swap/utils/init.c \
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

PUSH_SWAP_MAIN		=	src/push_swap/push_swap.c 

# Checker Source Files
CHECKER_OPERATIONS	=	src/checker/operations/push.c \
						src/checker/operations/rev_rotate.c \
						src/checker/operations/rotate.c \
						src/checker/operations/swap.c

CHECKER_UTILS		=	src/checker/utils/atol.c \
						src/checker/utils/errors.c \
						src/checker/utils/parse_operations.c \
						src/checker/utils/parse_stacks.c \
						src/checker/utils/stack_utils.c

CHECKER_GNL			=	src/checker/get_next_line/get_next_line.c \
						src/checker/get_next_line/get_next_line_utils.c

CHECKER_MAIN		=	src/checker/checker.c

# Concatenate source files
PUSH_SWAP_SRCS		= $(PUSH_SWAP_OPERATIONS) $(PUSH_SWAP_UTILS) $(PUSH_SWAP_MAIN)
CHECKER_SRCS		= $(CHECKER_OPERATIONS) $(CHECKER_UTILS) $(CHECKER_GNL) $(CHECKER_MAIN)

# Object files
PUSH_SWAP_OBJ		= $(patsubst %.c,$(OBJ_DIR)%.o,$(PUSH_SWAP_SRCS))
CHECKER_OBJ			= $(patsubst %.c,$(OBJ_DIR)%.o,$(CHECKER_SRCS))

# Build rules
start:				
					@make all

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

# Compile object files from source files
$(OBJ_DIR)%.o:		%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME) $(CHECKER)
					@$(RM) $(LIBFT)

re: 				fclean all

re_bonus:			fclean bonus

# Phony targets represent actions not files
.PHONY: 			start all bonus clean fclean re re_bonus
