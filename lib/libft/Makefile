# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:51:45 by rpichon           #+#    #+#              #
#    Updated: 2020/06/04 15:29:30 by rpichon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


INCLUDE 	= libft.h

SRCS		= ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		 	  ft_memcmp.c ft_bzero.c ft_toupper.c ft_tolower.c \
			  ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c \
			  ft_strlcat.c ft_strnstr.c ft_strdup.c ft_strjoin.c ft_strtrim.c \
			  ft_strmapi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_atoi.c ft_calloc.c ft_substr.c ft_split.c ft_itoa.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			  ft_isspace.c ft_itoa_base.c ft_strndup.c get_next_line.c \
			  get_next_line_utils.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
			  ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			  ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			  ft_lstmap_bonus.c ft_strstr.c ft_strcmp.c ft_strtrim_free.c \
			  ft_strndup_f.c ft_strdup_f.c ft_intchr.c ft_atoi_size_t.c

OBJS		= $(SRCS:.c=.o)

NAME		= libft.a

RM			= rm -f

FLAGS		= -Wall -Werror -Wextra

all:		$(NAME)

%.o: %.c 	$(INCLUDE)
			@printf "\033[2K\r\033[0;32m[Compiling] : \t\033[0;32m\033[0m$<"
	    	@gcc $(FLAGS) -o $@ -c $<

$(NAME): 	$(OBJS) $(INCLUDE)
			@ar rcs $(NAME) $(OBJS)
			@printf "\33[2K\r \033[0m\033[0;33mLibft: \t\033[0;38;5;121mUpdated\n\033[0m"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:		fclean all
.PHONY:fclean all clean
