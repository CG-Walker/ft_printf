/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:48:22 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/02/03 14:49:51 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	flag_digit_settings(const char *s, t_format f, va_list args)
{
	size_t i;

	i = 0;
	if (i == 0 && s[i] == '*' && ft_isdigit(s[i + 1]))
	{
		va_arg(args, int);
		f.min_field = ft_atoi(&s[++i]);
		return (f);
	}
	while (!(ft_isdigit(s[i])) && s[i] != '*')
		i++;
	if (s[i] == '*')
	{
		f.min_field = va_arg(args, int);
		if (f.min_field < 0)
		{
			f.flags |= FLAG_MINUS;
			f.flags &= ~FLAG_DIGIT;
			f.min_field *= -1;
		}
	}
	else
		f.min_field = ft_atoi(&s[i]);
	return (f);
}

t_format	flag_minus_settings(const char *s, t_format f, va_list args)
{
	size_t i;

	i = 0;
	while (s[i] != '-')
		i++;
	while (s[i] == '-')
		i++;
	if (ft_isdigit(s[i]))
		f.min_field = ft_atoi(&s[i]);
	else if (s[i] == '*')
	{
		f.min_field = va_arg(args, int);
		if (f.min_field < 0)
			f.min_field *= -1;
	}
	return (f);
}

t_format	flag_zero_settings(const char *s, t_format f, va_list args)
{
	size_t	i;

	i = 0;
	while (s[i] != '0')
		i++;
	while (s[i] == '0')
		i++;
	if (ft_isdigit(s[i]))
		f.min_field = ft_atoi(&s[i]);
	else if (s[i] == '*')
	{
		f.min_field = va_arg(args, int);
		if (f.min_field < 0)
		{
			f.flags += FLAG_MINUS;
			f.flags -= FLAG_ZERO;
			f.min_field *= -1;
		}
	}
	return (f);
}

t_format	flag_dot_settings(const char *s, t_format f, va_list args)
{
	size_t i;

	i = 0;
	while (s[i] != '.')
		i++;
	while (s[i] == '.')
		i++;
	if (ft_isdigit(s[i]))
		f.precision = ft_atoi(&s[i]);
	else if (s[i] == '*')
	{
		f.precision = va_arg(args, int);
		if (f.precision < 0)
			f.flags &= ~FLAG_DOT;
	}
	return (f);
}
