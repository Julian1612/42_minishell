# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 10:38:06 by dgross            #+#    #+#              #
#    Updated: 2023/01/06 23:45:08 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

VPATH		= src: src/builtins: src/utils: src/signals: \
			  src/lexer: src/parser: src/execution: \
			  src/redirection: src/heredoc:

LIBFT		= libft/libft.a

SRC			= main.c error.c free.c\
			  utils.c catch.c\
			  signals.c \
			  reset_redir.c redirection.c \
			  parser.c cmd_counter.c cmd_handler.c init_cmd.c redir_handler.c \
			  lexer.c counter.c skipper.c whitespace_skipper.c \
			  heredoc_exp.c heredoc.c \
			  execution.c execute_builtin.c execute_cmd.c \
			  exec_exit.c expansion.c edit_line.c \
			  echo.c cd.c pwd.c export.c env.c exit.c unset.c

OBJ_DIR		= ./obj/

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g

INCLUDES	= -I./includes -I./libft/includes -I /Users/$(USER)/goinfre/.brew/opt/readline/include #-Wno-gnu-include-next -ILeaksanitizer/include


LINCLUDES	= -L./libft -lft -L /Users/$(USER)/goinfre/.brew/opt/readline/lib #-LLeaksanitizer -llsan -lc++

g			= \033[1;32m
de 			= \033[0m
r 			= \033[0;31m
w			= \033[0;97m
b			= \033[0;30m
br          = \033[38;5;215m
wb			= \033[48;5;015m
brb			= \033[48;5;137m

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

obj/%.o: %.c
	@echo "$(g)Compiling  $(w)$<$(de)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): --minishell_img obj $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(LIBFT) $(LINCLUDES) -lreadline -o $(NAME)
	@echo "$(g)Compiling Done ✔️$(de)"

clean:
	@echo "$(r)Cleaning 🧹 $(w)...$(de)"
	@$(MAKE) clean -C libft/
	@rm -rf obj
	@rm -rf here_doc

fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -rf $(NAME)

git:
	git add .
	git commit -m "commit"
	git push

re: fclean all

.PHONY: all clean fclean re

--minishell_img:
	@echo "            $(b)▄▄████████▄▄$(de)"
	@echo "        $(b)▄██$(g)╬╬╬╬╬╬╬╬$(b)██$(g)╬╬╬╬$(b)██▄$(de)"
	@echo "      $(b)██$(g)╬╬╬╬╬$(b)████▓█$(g)╬╬╬╬╬╬╬╠╬$(b)██$(de)"
	@echo "     $(b)╓██$(g)╬╣$(b)██$(g)╬╬╬╬╬╬╬$(b)██$(g)╬╬╬╬╬╬╬╬╬╬$(b)██$(de)"
	@echo "     $(b)█$(g)╬╬$(b)█$(g)╬╬╬╬╬╬╬╬╬╬╬$(b)█$(g)╬╬╬╬╬╬╬╬$(b)███$(wb)▀██$(b)▄"
	@echo "    $(b)█$(g)╬╬$(b)█$(g)╬╬╬╬╬╬╬╬╬╬╬$(b)█$(g)╬╬╬$(b)██$(wb)▀▀▀▀      $(de)$(b)$(wb)▀$(b)▄▄$(de)"
	@echo "   $(b)██$(g)╬╬$(b)█$(g)╬╬╬╬╬╬╬╬╬╬╬$(b)███$(wb)▀▀              $(b)█$(de)"
	@echo "   $(b)█$(g)╬╬$(b)███$(g)╠╬╬╬╬╬╬$(b)██$(wb)▀         ▄$(b)████$(brb)▀█$(wb)  █$(b) $(de)$(w) ███    ███ 🍄 ███    ██ 🍄 ███████ ██   ██ ███████ ██      ██$(de)"
	@echo "$(b)$(wb)█▀▀▀███████▀▀▀▀▀        ▄▄$(b)███████$(brb)░░$(b)█▀$(de)$(w)   ████  ████ ██ ████   ██ ██ ██      ██   ██ ██      ██      ██$(de)"
	@echo "$(b)▌$(wb)                   ▄█$(de)$(b)$(brb)▀▀░░░$(b)$(brb)▀████▌$(br)░░$(b)█$(de)$(w)    ██ ████ ██ ██ ██ ██  ██ ██ ███████ ███████ █████   ██      ██  $(de)"
	@echo "$(b)▀▄$(wb)          ▄▄$(de)$(b)██████$(brb)▌░░░░░░░░░░░░$(b)█$(de)$(w)      ██  ██  ██ ██ ██  ██ ██ ██      ██ ██   ██ ██      ██      ██    $(de)"
	@echo "  $(b)▀▀█████████$(brb)▀░░░░$(b)$(brb)▀▀█$(brb)▄░░░░$(b)$(brb)▀▄$(br)░░░░$(b)█$(de)$(w)       ██      ██ ██ ██   ████ ██ ███████ ██   ██ ███████ ███████ ███████$(de)"
	@echo "      $(b)▀█$(brb)▄░░░░░░░$(br)░░░░░$(b)$(brb)▀▀▄▄▄$(br)░░$(b)$(brb)▀█$(b)▀▀▀$(de)"
	@echo "        $(b)▀▀██$(brb)▄$(br)░░░$(b)$(brb)▀▄$(br)░░░░░░$(b)$(brb)▄█$(de)$(b)▀▀▀$(de)"
	@echo "           $(b) ▀▀▀▀███▀▀▀▀▀$(de)"
	@echo "$(w)-----------------------------------------------------------------------------------------------------------$(de)"
