/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:38:23 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/11/08 14:40:10 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	i;

	i = -1;
	if (!(copy = malloc((sizeof(char) * (n + 1)))))
		return (NULL);
	while (++i < n)
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
