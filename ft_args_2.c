/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:43:41 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/02/03 14:43:54 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** FLAG_DOT		: Add X 0 minus the size of the number BEFORE the number.
**				  If the number is negative, X doesn't change.
** FLAG_MINUS	: Add X spaces minus the size of the number AFTER the number.
**				  If the number is negative, X - 1.
** FLAG_DIGIT	: Add X spaces minus the size of the number BEFORE the number.
**				  If the number is negative, X - 1.
** FLAG_ZERO	: Add X 0 minus the size of the number BEFORE the number.
**				  If the number is negative, X - 1.
*/

t_format	arg_di_nxt(short k, t_format format, int size_i, char *itoa_i)
{
	int		size_tmp;

	if (k == 1)
		format.size += write(1, "-", 1);
	if (format.flags & FLAG_DOT && format.precision - (size_i - k) > 0)
		format.size += write_zeros(format.precision - (size_i - k));
	if (format.flags & FLAG_ZERO && !(format.flags & (FLAG_DOT | FLAG_MINUS)))
		format.size += write_zeros(format.min_field - size_i);
	format.size += write(1, itoa_i, size_i - k);
	size_tmp = format.size;
	if (format.flags & FLAG_MINUS && (format.min_field - size_tmp) > 0)
		format.size += write_spaces(format.min_field - size_tmp);
	free(itoa_i);
	return (format);
}

size_t		arg_di(signed long int i, short int k, t_format f)
{
	int		size_i;
	char	*itoa_i;

	itoa_i = ft_ll_itoa(i);
	size_i = ft_strlen(itoa_i) + k;
	if (i == 0 && f.flags & FLAG_DOT && size_i > 0)
		size_i--;
	if (f.flags & FLAG_DIGIT && f.precision < size_i)
		f.size += write_spaces(f.min_field - size_i);
	else if (f.flags & (FLAG_DIGIT | FLAG_ZERO) && f.flags & FLAG_DOT)
	{
		if (f.precision >= size_i)
			f.size += write_spaces(f.min_field - (f.precision + k));
		else
			f.size += write_spaces(f.min_field - size_i);
	}
	f = arg_di_nxt(k, f, size_i, itoa_i);
	return (f.size);
}

size_t		arg_u(unsigned int i, t_format format)
{
	int		size_i;
	int		size_tmp;
	char	*itoa_i;

	itoa_i = ft_u_itoa(i);
	size_i = ft_strlen(itoa_i);
	if (i == 0 && format.flags & FLAG_DOT && size_i > 0)
		size_i--;
	if (format.flags & FLAG_DIGIT && format.precision < size_i)
		format.size += write_spaces(format.min_field - size_i);
	else if (format.flags & (FLAG_DIGIT | FLAG_ZERO) && format.flags & FLAG_DOT)
		(format.precision > size_i) ? (format.size +=
		write_spaces(format.min_field - format.precision))
		: (format.size += write_spaces(format.min_field - (size_i)));
	if (format.flags & FLAG_ZERO && !(format.flags & (FLAG_DOT | FLAG_MINUS)))
		format.size += write_zeros(format.min_field - size_i);
	if (format.flags & FLAG_DOT && format.precision - size_i > 0)
		format.size += write_zeros(format.precision - size_i);
	format.size += write(1, itoa_i, size_i);
	size_tmp = format.size;
	if (format.flags & FLAG_MINUS && (format.min_field - size_tmp) > 0)
		format.size += write_spaces(format.min_field - size_tmp);
	free(itoa_i);
	return (format.size);
}

t_format	arg_x_nxt(long long i, t_format format, int size_i, char *hexa)
{
	int		size_tmp;

	if (format.flags & FLAG_DOT && format.precision - size_i > 0)
		format.size += write_zeros(format.precision - size_i);
	if (format.flags & FLAG_ZERO && !(format.flags & (FLAG_DOT | FLAG_MINUS)))
		format.size += write_zeros(format.min_field - size_i);
	if (format.arg_type == 'x' && !(i == 0 && format.flags & FLAG_DOT))
		format.size += write(1, hexa, size_i);
	else if (!(i == 0 && format.flags & FLAG_DOT))
		format.size += write(1, ft_str_toupper(hexa), size_i);
	else
		write(1, 0, 1);
	size_tmp = format.size;
	if (format.flags & FLAG_ZERO && format.flags & FLAG_DOT)
		format.size += write_spaces(format.min_field - size_tmp);
	if (format.flags & FLAG_MINUS)
		format.size += write_spaces(format.min_field - size_tmp);
	free(hexa);
	return (format);
}

size_t		arg_x(long long int i, t_format format)
{
	int		size_i;
	char	*hexa;

	hexa = ft_u_itoabase(i, "0123456789abcdef");
	size_i = ft_strlen(hexa);
	if (i == 0 && format.flags & FLAG_DOT && size_i > 0)
		size_i--;
	if (format.flags & FLAG_DIGIT && format.precision < size_i)
		format.size += write_spaces(format.min_field - size_i);
	else if (format.flags & (FLAG_DIGIT | FLAG_ZERO) && format.flags & FLAG_DOT)
	{
		if (format.precision > size_i)
			format.size += write_spaces(format.min_field - format.precision);
		else
			format.size += write_spaces(format.min_field - size_i);
	}
	format = arg_x_nxt(i, format, size_i, hexa);
	return (format.size);
}
