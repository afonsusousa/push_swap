# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= ./
SRC_DIR				= ./
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
OPERATIONS_DIR		=	operations/push.c \
						operations/rev_rotate.c \
						operations/rotate.c \
						operations/swap.c

UTILS_DIR			=	utils/display.c \
                    	utils/init_stack.c \
                    	utils/stack_utils.c 

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