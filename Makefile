NAME		= minishell

LIBFT		= libft/libft.a

SRC			= main.c

OBJ_DIR		= ./obj/

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I./includes -I./libft/includes

LINCLUDES	= -L./libft -lft

g			= \033[1;32m
de 			= \033[0m
r 			= \033[0;31m
w			= \033[0;97m
d 			= \033[1;2;30m
hb 			= \033[1;34m
db 			= \033[0;34m
db 			= \033[38;5;017m
b			= \033[0;30m
br          = \033[38;5;215m
wb			= \033[48;5;015m
brb			= \033[48;5;137m

--minishell_img:
	@echo "             $(b)▄▄████████▄▄$(de)"
	@echo "         $(b)▄██$(g)╬╬╬╬╬╬╬╬$(b)██$(g)╬╬╬╬$(b)██▄$(de)"
	@echo "       $(b)██$(g)╬╬╬╬╬$(b)████▓█$(g)╬╬╬╬╬╬╬╠╬$(b)██$(de)"
	@echo "      $(b)╓██$(g)╬╣$(b)██$(g)╬╬╬╬╬╬╬$(b)██$(g)╬╬╬╬╬╬╬╬╬╬$(b)██$(de)"
	@echo "      $(b)█$(g)╬╬$(b)█$(g)╬╬╬╬╬╬╬╬╬╬╬$(b)█$(g)╬╬╬╬╬╬╬╬$(b)█▓█▀███▄$(de)"
	@echo "     $(b)█$(g)╬╬$(b)▓▒$(g)╬╬╬╬╬╬╬╬╬╬╬$(b)█$(g)╬╬$(b)██▓▀▀└$(wb)        $(de)$(b)█─$(de)"
	@echo "    $(b)██$(bb)╬╬$(b)█$(g)╬╬╬╬╬╬╬╬╬╬╬$(b)▓██▀▀─$(wb)             $(b)▌$(de)"
	@echo "    $(b)█$(g)▒╣$(b)███$(g)╠╬╬╬╬╬╬$(b)██▀ $(wb)        $(b)▄████$(brb)▀█$(wb)  █$(b)─$(de) ███    ███ ██ ███    ██ ██ ███████ ██   ██ ███████ ██      ██"
	@echo " $(b)$(wb)█▀▀▀███████▀▀▀          ▄▄$(b)▓█████▌$(de)$(brb)░ $(b)█▀$(de)   ████  ████ ██ ████   ██ ██ ██      ██   ██ ██      ██      ██"
	@echo "$(b)╟▌$(wb)                   ▄█$(de)$(b)$(brb)▀▀░░░$(b)$(brb)▀████▌$(br)░░$(b)█$(de)    ██ ████ ██ ██ ██ ██  ██ ██ ███████ ███████ █████   ██      ██  "
	@echo " $(b)▀▄$(wb)          ▄▄$(de)$(b)██████$(brb)▌░░░░░░░░░░░░$(b)█$(de)      ██  ██  ██ ██ ██  ██ ██ ██      ██ ██   ██ ██      ██      ██    "
	@echo "   $(b)└╙▀████████▌$(brb)▀░░░$(b)╙▀▀█$(brb)▄░░░░$(b)╦▄$(brb)░░░░$(b)█$(de)      ██      ██ ██ ██   ████ ██ ███████ ██   ██ ███████ ███████ ███████"
	@echo "       $(b)╙█▄$(brb)░░░░░░░$(br)░░░░░$(b)╙▀▄▄▄$(brb)░░$(b)$(brb)╠█$(b)▀▀▀$(de)"
	@echo "         $(b)╙▀██$(brb)▄$(br)░░░$(b)$(brb)▀▄▄$(br)░░░░░$(b)▄█▀▀▀$(de)"
	@echo "            $(b)─╙╙▀▀▀███▀▀▀▀╙$(de)"
	@echo "----------------------------------------------------------------------------------------------------------------------"
     
all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

obj/%.o: src/%.c
	@echo "$(g)Compiling  $(w)$<$(de)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
                    
$(NAME): --minishell_img obj $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) $(LIBFT) $(LINCLUDES) -o $(NAME)
	@echo "$(g)Compiling Done ✔️$(de)"

clean:
	@echo "$(r)Cleaning 🧹 $(w)...$(de)"
	@$(MAKE) clean -C libft/
	@rm -rf obj

fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re