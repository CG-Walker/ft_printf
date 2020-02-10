/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:00:31 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/01/29 17:02:32 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*fill_itoa(unsigned int n, char *ret, size_t i, BOOL is_neg)
{
	if (n == 0)
		ret[0] = '0';
	ret[i + 1] = '\0';
	while (n > 0)
	{
		ret[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (is_neg == TRUE)
		ret[0] = '-';
	return (ret);
}

char			*ft_ll_itoa(long long int n)
{
	char				*ret;
	size_t				i;
	long long int		cpy_n;
	BOOL				is_negative;

	i = 0;
	if (n < 0)
		is_negative = TRUE;
	else
		is_negative = FALSE;
	cpy_n = (n < 0) ? n * -1 : n;
	n = cpy_n;
	while (cpy_n > 9)
	{
		i++;
		cpy_n /= 10;
	}
	if (is_negative == TRUE)
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	return (fill_itoa(n, ret, i, is_negative));
}
