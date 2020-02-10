/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:18:30 by cgoncalv          #+#    #+#             */
/*   Updated: 2020/01/22 19:52:05 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*if_zero(void)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * (2))))
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_u_itoa(unsigned long long n)
{
	unsigned long long	tmp;
	size_t				i;
	char				*ret;

	tmp = n;
	i = 0;
	if (n == 0)
		return (if_zero());
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i + 1] = '\0';
	while (n > 0)
	{
		ret[i--] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}
