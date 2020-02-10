/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:51:15 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/18 15:29:33 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (s == NULL)
		return (0);
	if (start > ft_strlen(s))
	{
		if (!(ret = malloc(sizeof(char) * 1)))
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(ret, &s[start], len);
	ret[len] = '\0';
	return (ret);
}
