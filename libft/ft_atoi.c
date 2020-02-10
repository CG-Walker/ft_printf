/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:14:10 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/17 15:52:56 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	value;
	unsigned long long	max_value;
	int					sign_val;
	size_t				i;

	value = 0;
	max_value = 9223372036854775807;
	i = 0;
	sign_val = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign_val = (str[i++] == '-') ? -1 : 1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		value *= 10;
		value += (str[i++] - '0');
		if (value > max_value && sign_val == 1)
			return (-1);
		else if (value > max_value + 1 && sign_val == -1)
			return (0);
	}
	return ((int)(sign_val * value));
}
