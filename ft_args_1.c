/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:16:09 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/02/06 17:50:50 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	arg_c(unsigned char c, t_format format)
{
	if (format.flags & FLAG_ZERO)
		format.size += write_zeros(format.min_field - 1);
	if (format.flags & FLAG_DIGIT)
		format.size += write_spaces(format.min_field - 1);
	format.size += write(1, &c, 1);
	if (format.flags & FLAG_MINUS)
		format.size += write_spaces(format.min_field - 1);
	return (format.size);
}

size_t	arg_s(char *s, t_format format)
{
	int		size_s;
	short	s_null;

	s_null = 0;
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		s_null = 1;
	}
	size_s = ft_strlen(s);
	if (format.flags & FLAG_DOT && format.precision < (int)ft_strlen(s))
		size_s = format.precision;
	if (format.flags & FLAG_DIGIT)
		format.size += write_spaces(format.min_field - size_s);
	if (format.flags & FLAG_ZERO)
		format.size += write_zeros(format.min_field - size_s);
	if (format.flags & FLAG_DOT && format.precision < (int)ft_strlen(s))
		format.size += write(1, s, format.precision);
	else
		format.size += write(1, s, ft_strlen(s));
	if (format.flags & FLAG_MINUS && size_s < format.min_field)
		format.size += write_spaces(format.min_field - size_s);
	if (s_null == 1)
		free(s);
	return (format.size);
}

size_t	arg_p(long long unsigned adress, t_format format)
{
	int		size_tmp;
	char	*hexa_adress;

	hexa_adress = ft_llu_itoabase(adress, "0123456789abcdef");
	size_tmp = ft_strlen(hexa_adress);
	if (adress == 0 && format.flags & FLAG_DOT && size_tmp > 0)
		size_tmp--;
	if (format.flags & FLAG_DIGIT)
		format.size += write_spaces(format.min_field - (size_tmp + 2));
	format.size += write(1, "0x", 2);
	if (format.flags & FLAG_DOT)
		format.size += write_zeros(format.precision - size_tmp);
	if (format.flags & FLAG_ZERO)
		format.size += write_zeros(format.min_field - size_tmp - 2);
	format.size += write(1, hexa_adress, size_tmp);
	if (format.flags & FLAG_MINUS && size_tmp < format.min_field)
		format.size += write_spaces(format.min_field - (size_tmp + 2));
	free(hexa_adress);
	return (format.size);
}

size_t	arg_percent(t_format format)
{
	int i;

	i = 0;
	if (format.flags & FLAG_DIGIT)
		format.size += write_spaces(format.min_field - 1);
	if (format.flags & FLAG_ZERO)
		while (i++ < format.min_field - 1)
			format.size += write(1, "0", 1);
	format.size += write(1, "%", 1);
	if (format.flags & FLAG_MINUS)
		format.size += write_spaces(format.min_field - 1);
	return (format.size);
}
