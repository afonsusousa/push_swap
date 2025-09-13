# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 16:47:35 by amagno-r          #+#    #+#              #
#    Updated: 2025/09/13 16:43:54 by amagno-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c 

PRINTF_SRCS = ft_printf/ft_printf.c \
	ft_printf/ft_printf_utils_address.c \
	ft_printf/ft_printf_utils.c \
	ft_printf/ft_printf_utils_flags.c \
	ft_printf/ft_printf_utils_putchar.c \
	ft_printf/ft_printf_utils_puthex.c \
	ft_printf/ft_printf_utils_putnbr.c \
	ft_printf/ft_printf_utils_putn.c \
	ft_printf/ft_printf_utils_puts.c \
	ft_printf/ft_printf_utils_putunbr.c \
	ft_printf/ft_printf_utils_strs.c

BONUS = ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

OBJSBONUS = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS) $(PRINTF_OBJS)
	ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS)

bonus: $(NAME) $(OBJSBONUS) 
	ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS) $(OBJSBONUS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(PRINTF_OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
