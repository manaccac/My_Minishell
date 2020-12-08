/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:30:38 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/17 14:37:50 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

/*
**	DEFINE AUTHORIZED BASH FUNCTIONS
*/
typedef enum		e_redirect
{
	NOTHING,
	SIMPLE,
	DOUBLE,
	S_IN,
	PIPE
}					t_redirec;

/*
**			STRUCTURES
*/
typedef struct		s_env
{
	char			*name;
	char			*val;
	struct s_env	*next;
}					t_env;

typedef struct		s_line
{
	char			*av;
	char			*function;
	struct s_line	*next;
}					t_line;

typedef struct		s_word
{
	char			*word;
	struct s_word	*next;
}					t_word;

typedef struct		s_redir
{
	char			*path;
	int				type;
	struct s_redir	*next;
}					t_redir;

typedef struct		s_echo
{
	int				option;
	int				quote;
	int				space;
	int				i;
	int				y;
}					t_echo;

typedef struct		s_shell
{
	t_env			*env;
	t_line			*line;
	t_echo			*echo;
	t_word			*word;
	t_redir			*redir;
	int				is_export;
	char			*result;
	int				forked;
	int				nb_red;
	int				nb_pip;
	int				nb_pipe;
	int				*sfd;
	char			*path;
	char			**envp;
}					t_shell;

#endif
