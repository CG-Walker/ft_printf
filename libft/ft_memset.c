/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:56:04 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/22 14:12:30 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *ptr;

	if (b == NULL)
		return (NULL);
	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}
