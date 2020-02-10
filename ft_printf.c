/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:10:18 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/02/06 17:48:26 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_nxt(const char *s, va_list args, size_t nbr_c, size_t saved_i)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			saved_i = i;
			nbr_c += flags_processing(&s[++i], args);
			while (s[i] && is_arg(s[i]) != TRUE)
				i++;
			if (s[i] == '\0')
			{
				i = saved_i;
				while (s[i] &&
				(s[i] == '%' || s[i] == '-' || ft_isdigit(s[i]) || s[i] == '.'))
					i++;
			}
			if (s[i] != '\0')
				i++;
		}
		else
			nbr_c += write(1, &s[i++], 1);
	}
	return (nbr_c);
}

int		ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	nbr_c;
	size_t	saved_i;

	if (s == NULL || s[0] == '\0')
		return (-1);
	nbr_c = 0;
	saved_i = 0;
	va_start(args, s);
	nbr_c = ft_printf_nxt(s, args, nbr_c, saved_i);
	va_end(args);
	return (nbr_c);
}
