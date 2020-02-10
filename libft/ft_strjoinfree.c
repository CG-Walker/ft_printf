/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:02:49 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/12/16 18:53:57 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*ret;
	size_t	size_s1;
	size_t	size_s2;

	if (s1 == NULL)
	{
		ret = ft_strdup(s2);
		free(s2);
		return (ret);
	}
	if (s2 == NULL)
	{
		ret = ft_strdup(s1);
		free(s1);
		return (ret);
	}
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (!(ret = malloc((sizeof(char) * (size_s1 + size_s2) + 1))))
		return (NULL);
	ft_memcpy(ret, s1, size_s1);
	ft_memcpy(&ret[size_s1], s2, size_s2 + 1);
	free(s1);
	free(s2);
	return (ret);
}
