# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 09:26:21 by frfrey            #+#    #+#              #
#    Updated: 2020/06/17 14:50:22 by frfrey           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER					= includes/

LIB						= libftprintf.a

LIBS					= lib/libftprintf.a

SRCS_BASE				= $(addprefix base/, ft_minishell.c ft_signal.c)

SRCS_PARSING			= $(addprefix parsing/, parsing.c get_function.c \
							remove_quote.c)

SRCS_EXIT				= $(addprefix exit/, exit.c)

SRCS_DIR				= $(addprefix dir/, pwd.c cd.c)

SRCS_ENV				= $(addprefix env/, env_functions.c env_functions2.c)

SRCS_EXPORT				= $(addprefix export/, export.c export_sort.c rm_quotes.c \
							export_functions.c)

SRCS_UNSET				= $(addprefix unset/, ft_unset.c)

SRCS_ECHO				= $(addprefix echo/, echo.c echo_lst.c \
							echo_utils.c echo_utils2.c)

SRCS_EXEC				= $(addprefix exec/, exec.c split_exec.c \
								ft_exec_prog.c)

SRCS_REDIR				= $(addprefix redirect/, ft_redirect.c ft_utils.c \
							ft_lst.c ft_exec_redir.c ft_exec_type.c \
							ft_redir.c)

SRC_PATH				= srcs/

SRC_NAME				= main.c $(SRCS_UNSET) $(SRCS_BASE) $(SRCS_ENV) \
							$(SRCS_EXIT) $(SRCS_PARSING) $(SRCS_DIR) \
							$(SRCS_EXEC) $(SRCS_EXPORT) $(SRCS_ECHO) \
							$(SRCS_REDIR)

SRCS					= $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME				= $(SRC_NAME:.c=.o)

OBJ_PATH				= obj/

OBJ						= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME					= minishell

RM						= rm -rf

FLAG					= -Wall -Wextra -Werror -O3

#FLAGS					= -g3 -fsanitize=address

# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #

all: $(LIB) $(OBJ_PATH) $(NAME) $(HEADER)

$(NAME): $(OBJ)
	@gcc $(FLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\33[2K\r \033[0m\033[0;33mMinishell: \t\033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p obj/ 2> /dev/null
	@mkdir -p obj/base 2> /dev/null
	@mkdir -p obj/exit 2> /dev/null
	@mkdir -p obj/parsing 2> /dev/null
	@mkdir -p obj/env 2> /dev/null
	@mkdir -p obj/export 2> /dev/null
	@mkdir -p obj/dir 2> /dev/null
	@mkdir -p obj/echo 2> /dev/null
	@mkdir -p obj/exec 2> /dev/null
	@mkdir -p obj/unset 2> /dev/null
	@mkdir -p obj/redirect 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)/minishell.h
	@printf "\033[2K\r\033[0;32m[Compiling] : \t\033[0;32m\033[0m$<"
	@gcc $(FLAG) -I $(HEADER) -c $< -o $@

$(LIB):
	@$(MAKE) -C lib all

clean:
	@$(MAKE) -C lib clean
	@printf "\033[2K\r\x1b[31mDeleting Minishell srcs/	\033[37m"
	@sleep 0.1
	@printf "\033[2K\r\x1b[31mDeleting Minishell srcs/.	\033[37m"
	@sleep 0.1
	@printf "\033[2K\r\x1b[31mDeleting Minishell srcs/..	\033[37m"
	@sleep 0.1
	@printf "\033[2K\r\x1b[31mDeleting Minishell srcs/...	\033[37m"
	@sleep 0.1
	@printf "\033[2K\r\x1b[31mDeleting Minishell srcs/	\033[37m"
	@sleep 0.1
	@printf "\033[2K\r\x1b[31mDeleting Minishell srcs/.	\033[37m"
	@sleep 0.1
	@printf "\033[2K\r\x1b[31mDeleting Minishell srcs/..	\033[37m"
	@sleep 0.1
	@printf "\033[2K\r\x1b[31mDeleting Minishell srcs/...	\033[37m"
	@sleep 0.1
	@${RM} ${OBJ_PATH}
	@printf "\33[2K\r \033[0;32m[OK] \033[0m \x1b[36m Deleted successfully!\n\033[0m"

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean
