/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:57:21 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/01/30 16:53:51 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_arg(char c)
{
	if (c == 'x' || c == 'X' || c == 'p' || c == 'i' ||
	c == 'd' || c == 's' || c == 'c' || c == 'u' || c == '%')
		return (TRUE);
	return (FALSE);
}

char	*ft_u_itoabase(unsigned i, char *base)
{
	unsigned	cpy_i;
	size_t		size_base;
	size_t		n;
	char		*result;

	n = 0;
	cpy_i = i;
	size_base = ft_strlen(base);
	while (cpy_i > 0)
	{
		n++;
		cpy_i /= size_base;
	}
	if (i == 0)
		n = 1;
	if (!(result = malloc(sizeof(char) * n + 1)))
		return (NULL);
	result[n--] = '\0';
	(i == 0) ? result[0] = '0' : 0;
	while (i > 0)
	{
		result[n--] = base[i % size_base];
		i /= size_base;
	}
	return (result);
}

char	*ft_llu_itoabase(long long unsigned i, char *base)
{
	long long unsigned	cpy_i;
	size_t				size_base;
	size_t				n;
	char				*result;

	n = 0;
	cpy_i = i;
	size_base = ft_strlen(base);
	while (cpy_i > 0)
	{
		n++;
		cpy_i /= size_base;
	}
	if (i == 0)
		n = 1;
	if (!(result = malloc(sizeof(char) * n + 1)))
		return (NULL);
	result[n--] = '\0';
	(i == 0) ? result[0] = '0' : 0;
	while (i > 0)
	{
		result[n--] = base[i % size_base];
		i /= size_base;
	}
	return (result);
}

size_t	write_spaces(int n)
{
	int		i;
	char	*spaces;

	if (n <= 0)
		return (0);
	i = 0;
	if (!(spaces = malloc(sizeof(char) * n + 1)))
	{
		while (i++ < n)
			write(1, " ", 1);
		return (i);
	}
	spaces[n] = '\0';
	spaces = ft_memset(spaces, ' ', n);
	i += write(1, spaces, n);
	free(spaces);
	return (i);
}

size_t	write_zeros(int n)
{
	int		i;
	char	*zeros;

	if (n <= 0)
		return (0);
	i = 0;
	if (!(zeros = malloc(sizeof(char) * n + 1)))
	{
		while (i++ < n)
			write(1, " ", 1);
		return (i);
	}
	zeros[n] = '\0';
	zeros = ft_memset(zeros, '0', n);
	i += write(1, zeros, n);
	free(zeros);
	return (i);
}
