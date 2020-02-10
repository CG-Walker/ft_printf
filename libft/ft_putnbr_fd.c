/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:59:55 by cgoncalv          #+#    #+#             */
/*   Updated: 2019/10/11 17:11:57 by cgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int n_cpy;

	n_cpy = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n_cpy = -n;
	}
	if (n_cpy > 9)
		ft_putnbr_fd(n_cpy / 10, fd);
	ft_putchar_fd(n_cpy % 10 + '0', fd);
}
