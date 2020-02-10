/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:20:29 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/22 13:47:05 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static BOOL	is_set(char const c, char const *set)
{
	size_t i;

	i = 0;
	while (c != set[i] && set[i])
		i++;
	if (c == set[i])
		return (TRUE);
	else
		return (FALSE);
}

char		*ft_strtrim(char const *s, char const *set)
{
	size_t	end;
	size_t	start;
	char	*copy;

	if (s == NULL || set == NULL)
		return (0);
	start = 0;
	end = ft_strlen(s);
	while (is_set(s[start], set) == TRUE && s[start])
		start++;
	while (is_set(s[end], set) == TRUE && end > start)
		end--;
	if (!(copy = malloc(sizeof(char) * ((end - start) + 2))))
		return (NULL);
	ft_memcpy(copy, &s[start], ((end - start) + 1));
	copy[((end - start) + 1)] = '\0';
	return (copy);
}
