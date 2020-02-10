/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduptoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:21:09 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/12/17 17:27:23 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strduptoc(const char *s1, char c)
{
	char	*copy;
	size_t	i;
	size_t	size;

	i = -1;
	size = 0;
	while (s1[size] && s1[size] != c)
		size++;
	if (!(copy = malloc((sizeof(char) * size) + 1)))
		return (NULL);
	while (++i < size)
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
