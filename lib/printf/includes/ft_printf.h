/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:12:41 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/25 17:51:55 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define FALSE 0
# define TRUE 1
# define CONVERTERS "cspdiuxX%"
# define HEXA "abcdef"

typedef struct	s_list_pf
{
	char				*f;
	char				*debut_flags;
	char				type;
	char				*str;
	int					size;
	char				*text;
	int					spaces;
	int					has_spaces;
	int					precision;
	int					nb_precision;
	int					len_int;
	int					zero;
	int					hyphen;

	struct s_list_pf	*next;
}				t_listpf;

char			*ft_itoa_base(int n, int base);
int				ft_printf(const char *format, ...) __attribute__
((format(printf,1,2)));
int				parse_format(t_listpf **alst, char *str);
int				is_converter_pf(char c);
t_listpf		*ft_lstnew_addback(t_listpf **alst, char *flags, char type);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
int				init_parse_lst(t_listpf **alst, char *str);
void			display_lst(t_listpf *lst);
char			*ft_substr(char const *s, unsigned int start, size_t len);
t_listpf		*ft_lstlast_pf(t_listpf *lst);
void			lstdel_first(t_listpf **alst);
int				ft_putstr_len_pf(char *str);
int				ft_disp_elem(t_listpf **alst, va_list params);
int				printf_str(t_listpf *alst, va_list params);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *s);
void			gest_flags_str(t_listpf *alst, va_list params);
int				ft_isdigit(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			gest_flags_c(t_listpf *alst, va_list params);
int				printf_c(t_listpf *alst, va_list params);
void			gest_flags_d(t_listpf *alst, va_list params);
int				printf_d(t_listpf *alst, va_list params);
int				printf_d2(int cpt, int i, t_listpf *alst, int nb);
int				printf_u(t_listpf *alst, va_list params);
int				printf_u2(int cpt, int i, t_listpf *alst, int nb);
char			*ft_itoa_base_u(unsigned n, int base);
int				printf_x(t_listpf *alst, va_list params);
int				printf_x2(int cpt, int i, t_listpf *alst, int nb);
char			*ft_itoa_base_x(unsigned n, char *base);
int				printf_p(t_listpf *alst, va_list params);
int				printf_p2(int cpt, int i, t_listpf *alst, int nb);
char			*ft_itoa_base_p(unsigned long long n, char *base);
#endif
