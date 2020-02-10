/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:19:33 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/23 17:09:54 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (dst == src)
		return (dst);
	if (dst < src)
		while (++i < len)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	else
		while (len-- > 0)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	return (dst);
}
