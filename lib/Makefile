# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 14:35:51 by jdel-ros          #+#    #+#              #
#    Updated: 2020/12/17 14:35:52 by jdel-ros         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


HEADER		=					printf/includes/
LIB			=					libft.a
LIBS		=					libft/libft.a
SRC_PATH	=					printf/srcs
SRCS_NAME	= 					ft_printf.c ft_printf_utils.c parse.c \
								converter_c.c converter_d.c converter_s.c \
								converter_u.c converter_x.c converter_p.c
OBJS		= 					${SRCS:.c=.o}
NAME		= 					libftprintf.a
RM			= 					rm -f
FLAGS 		= 					-Wall -Wextra -Werror
#FLAGS		 =                  -g3 -fsanitize=address
SRCS 		= 					$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #

all:							$(LIB) $(NAME)

%.o: %.c 						$(HEADER) $(LIBS)
								@printf "\033[2K\r\033[0;32m[Compiling] : \t\033[0;32m\033[0m$<"
								@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):						$(OBJS) $(HEADER)
								@cp $(LIBS) ./$(NAME)
								@printf "\33[2K\r \033[0m\033[0;33mPrintF: \t\033[0;38;5;121mUpdated\n\033[0m"
								@ar rcs $(NAME) $(OBJS)
$(LIB):
								@$(MAKE) -C libft all
clean:
								@$(MAKE) -C libft clean
								@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
								@$(RM) $(OBJS)

fclean:							clean

								@$(MAKE) -C libft fclean
								@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m\n"
								@$(RM) $(NAME)

re:								fclean all

.PHONY: 						clean fclean
