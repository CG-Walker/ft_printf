/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:47:03 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/02/06 17:56:17 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	flags_initializing(const char *s, t_format format)
{
	size_t i;

	i = 0;
	while (!(ft_isalpha(s[i])) && s[i] != '%' && s[i])
	{
		if (s[i] == '0' && i == 0)
			format.flags |= FLAG_ZERO;
		else if (s[i] == '.')
			format.flags |= FLAG_DOT;
		else if (s[i] == '-')
			format.flags |= FLAG_MINUS;
		else if ((ft_isdigit(s[i]) && i == 0) || (s[i] == '*' && i == 0))
			format.flags |= FLAG_DIGIT;
		i++;
	}
	if (format.flags & FLAG_MINUS && format.flags & FLAG_ZERO)
		format.flags -= FLAG_ZERO;
	return (format);
}

t_format	flags_enabling(const char *s, t_format format, va_list args)
{
	if (format.flags & FLAG_MINUS)
		format = flag_minus_settings(s, format, args);
	if (format.flags & FLAG_ZERO)
		format = flag_zero_settings(s, format, args);
	if (format.flags & FLAG_DIGIT)
		format = flag_digit_settings(s, format, args);
	if (format.flags & FLAG_DOT)
		format = flag_dot_settings(s, format, args);
	return (format);
}

t_format	flags_parsing(t_format format, va_list args)
{
	long int	tmp;
	short int	k;

	if (format.arg_type == 'i' || format.arg_type == 'd')
	{
		tmp = va_arg(args, int);
		k = (tmp < 0) ? 1 : 0;
		tmp = (tmp < 0) ? tmp * -1 : tmp;
		format.size = arg_di(tmp, k, format);
	}
	if (format.arg_type == 'u')
		format.size = arg_u(va_arg(args, int), format);
	if (format.arg_type == 'x' || format.arg_type == 'X')
		format.size = arg_x(va_arg(args, long long int), format);
	if (format.arg_type == 'c')
		format.size = arg_c(va_arg(args, int), format);
	if (format.arg_type == 's')
		format.size = arg_s(va_arg(args, char*), format);
	if (format.arg_type == 'p')
		format.size = arg_p(va_arg(args, long long int), format);
	if (format.arg_type == '%')
		format.size = arg_percent(format);
	return (format);
}

size_t		flags_processing(const char *s, va_list args)
{
	t_format	format;
	size_t		i;

	i = 0;
	while (is_arg(s[i]) != TRUE && s[i])
		i++;
	if (s[i] != '\0')
		format.arg_type = s[i];
	format.flags = 0;
	format.min_field = 0;
	format.precision = 0;
	format.size = 0;
	format = flags_initializing(s, format);
	format = flags_enabling(s, format, args);
	format = flags_parsing(format, args);
	return (format.size);
}
