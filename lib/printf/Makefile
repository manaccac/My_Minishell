# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rpichon <rpichon@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/09 13:51:45 by rpichon      #+#   ##    ##    #+#        #
#    Updated: 2019/11/29 02:28:50 by rpichon     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

HEADER		=					includes/
LIB			=					libft.a
LIBS		=					../libft/libft.a
SRC_PATH	=					srcs
SRCS_NAME	= 					ft_printf.c ft_printf_utils.c parse.c \
								converter_c.c converter_d.c converter_s.c \
								converter_u.c converter_x.c converter_p.c
OBJS		= 					${SRCS:.c=.o}
NAME		= 					libftprintf.a
RM			= 					rm -f
FLAGS 		= 					-Wall -Wextra -Werror
SRCS 		= 					$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #

all:							$(LIB) $(NAME)

%.o: %.c 						$(HEADER) $(LIBS)
								@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
								@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):						$(OBJS) $(HEADER)
								@cp $(LIBS) ./$(NAME)
								@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling Printf\033[0m"
								@ar rcs $(NAME) $(OBJS)
$(LIB):
								@$(MAKE) -C ../libft all
clean:
								@$(MAKE) -C ../libft clean
								@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
								@$(RM) $(OBJS)

fclean:							clean

								@$(MAKE) -C ../libft fclean
								@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m\n"
								@$(RM) $(NAME)

re:								fclean all

.PHONY: 						clean fclean
