# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= ./
SRC_DIR				= ./
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g -I
RM					= rm -f

# Source Files
OPERATIONS_DIR		=	operations/push.c \
						operations/rev_rotate.c \
						operations/rotate.c \
						operations/swap.c

UTILS_DIR			=	utils/display.c \
                    	utils/init_stack.c \
                    	utils/stack_utils.c \
                    	utils/atol.c \
                    	utils/cost.c \
                    	utils/stack_b_utils.c \
                    	utils/stack_a_utils.c \
                    	utils/sort_utils.c \
                    	utils/sort.c \
                    	utils/indexes.c \
                    	utils/targets.c \
                    	utils/lis.c \
                    	utils/sort_search.c \
                    	utils/final_positions.c 

PUSH_SWAP_DIR		=	push_swap.c 

# Concatenate all source files
SRCS 				= $(OPERATIONS_DIR) $(UTILS_DIR) $(PUSH_SWAP_DIR) 

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re