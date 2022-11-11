# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 12:00:24 by dgross            #+#    #+#              #
#    Updated: 2022/11/11 15:30:59 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I./includes

OBJ_DIR		= ./obj/

SRC	 		= ft_malloc.c ft_atoi_base.c ft_putunsigned.c ft_putstring.c ft_putptr.c ft_puthexnbr.c ft_printf.c ft_countnbr.c get_next_line_utils.c get_next_line.c ft_strtrim.c ft_strjoin.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_substr.c ft_atoi.c ft_strdup.c ft_strrchr.c ft_calloc.c \
				ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_strcmp.c ft_int_strdup.c ft_int_memcpy.c

OBJS		= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

BONUS_SRC	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJ	= $(addprefix $(OBJ_DIR),$(BONUS_SRC:.c=.o))

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): obj $(OBJS)
	@ar -rcs $(NAME) $(OBJS)


clean:
	@rm -rf obj
	@rm -rf b_obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re