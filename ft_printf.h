/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:46:29 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/02/06 20:09:57 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef unsigned char	t_flags;

# define FLAG_ZERO		1
# define FLAG_DIGIT		2
# define FLAG_MINUS		4
# define FLAG_DOT		8

typedef struct	s_format
{
	t_flags			flags;
	int				min_field;
	int				precision;
	char			arg_type;
	size_t			size;
}				t_format;

/*
**	ft_printf_utils
*/

int				is_arg(char c);
char			*ft_u_itoabase(unsigned i, char *base);
char			*ft_llu_itoabase(long long unsigned i, char *base);
size_t			write_spaces(int n);
size_t			write_zeros(int n);

/*
**	ft_args
*/

size_t			arg_di(signed long int i, short int k, t_format format);
size_t			arg_u(unsigned int i, t_format format);
size_t			arg_x(long long int i, t_format format);
size_t			arg_c(unsigned char c, t_format format);
size_t			arg_s(char *s, t_format format);
size_t			arg_p(long long unsigned adress, t_format format);
size_t			arg_percent(t_format format);

/*
**	ft_flags
*/

t_format		flags_initializing(const char *s, t_format format);
t_format		flags_enabling(const char *s, t_format format, va_list args);
t_format		flags_parsing(t_format format, va_list args);
size_t			flags_processing(const char *s, va_list args);

/*
**	ft_flags_options
*/

t_format		flag_digit_settings(const char *s, t_format f, va_list args);
t_format		flag_minus_settings(const char *s, t_format f, va_list args);
t_format		flag_zero_settings(const char *s, t_format f, va_list args);
t_format		flag_dot_settings(const char *s, t_format f, va_list args);

/*
**	ft_printf
*/

int				ft_printf(const char *s, ...);

#endif
