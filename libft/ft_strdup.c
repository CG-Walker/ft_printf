/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:40:30 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/29 17:42:29 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;
	size_t	size_s1;

	i = -1;
	size_s1 = ft_strlen(s1);
	if (!(copy = malloc((sizeof(char) * size_s1) + 1)))
		return (NULL);
	while (++i < size_s1)
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
