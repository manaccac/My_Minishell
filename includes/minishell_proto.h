/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_proto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:34:03 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:34:04 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROTO_H
# define MINISHELL_PROTO_H

# include "minishell_proto.h"

/*
**			FONCTIONS BASE
*/
void				ft_wait_for_command(t_shell *shell);
void				print_prompt(void);
int					parse_line(char *line, t_shell *shell);
int					get_function(char *function, t_shell *shell);
char				*rm_quotes_free(char *str, int nb, char quote, int i);
char				*remove_double_quote(char *str);
char				*remove_simple_quote(char *str);

/*
**			FONCTIONS DIR
*/
void				ft_change_dir(t_shell *shell);
void				ft_pwd(t_shell *shell);
char				*chredir(char *line, t_shell *shell);

/*
**			FONCTIONS ENV
*/
t_env				*init_env(char **envp);
char				*get_name(char *env);
char				*get_val(char *env);
t_env				*lst_new_env(char *name, char *val);
void				disp_env(t_shell *shell);
void				ft_export(t_shell *shell);
void				free_env(t_env *env);
void				export_sort(t_shell *shell);
void				ft_unset(t_shell *shell);
char				*get_var_name(char *s);
char				*get_val_value(char *s);
void				addlast_lst(t_env *env, char *name, char *val);

/*
**			FONCTIONS ECHO
*/
void				print_echo(t_shell *shell);
void				ft_prepare_lst(char **line, t_env *env, t_echo *pars);
int					parse_argument_echo(char *line, int *option);
void				ft_free_echo(t_word *lst);
void				ft_prepare_line(t_echo *p, t_env *env, t_word *w);
int					ft_check_is_env(t_env *env, t_word *word, t_echo *o);

/*
**			FONCTIONS EXEC
*/
char				**ft_split_exec(char *str, char *charset);
void				ft_exec(t_shell *shell);
void				ft_exec_prog(t_redir *redir, t_shell *shell);

/*
**			FONCTIONS REDIRECTION
*/
int					ft_check_redir(t_shell *shell);
int					ft_check_next(char *line);
t_redir				*init_lst_redir(char *str);
int					count_redir(t_redir *redir, t_shell *shell);
int					ft_pipe(t_shell *shell);
void				exec_master(t_shell *shell, t_redir *redir, int fd1[2]);
void				ft_exec_simple(t_redir *redir, int fd);
void				ft_exec_double(t_redir *redir, int fd);
void				ft_exec_s_in(t_redir *redir, int fd);

/*
**			FONCTIONS SIGNAL
*/
void				signal_manager(int sig);
void				signal_child(int sig);

/*
**			FONCTIONS EXIT
*/
void				ft_exit(t_shell *shell);
void				ft_exit_eof(t_shell *shell);

#endif
