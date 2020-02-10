/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:30:52 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/29 17:43:02 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t size_s;

	i = 0;
	size_s = ft_strlen(s);
	while (i < size_s)
	{
		if (c == s[i])
			return (char*)(&s[i]);
		i++;
	}
	if (c == s[i])
		return (char*)(&s[i]);
	return (NULL);
}
