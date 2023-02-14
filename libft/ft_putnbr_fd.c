/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:48:19 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/16 11:55:50 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write(int a, int fd)
{
	int	b;

	b = a + '0';
	write(fd, &b, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{		
	if (nb >= 0 && nb < 10)
		ft_write(nb % 10, fd);
	if (nb >= 10 && nb <= 2147483647)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_write(nb % 10, fd);
	}
	if (nb < 0 && nb >= -2147483647)
	{
		nb = nb * -1;
		write(fd, "-", 1);
		ft_putnbr_fd(nb, fd);
	}
	if (nb == -2147483648)
	{
		nb = 214748364;
		write(fd, "-", 1);
		ft_putnbr_fd(nb, fd);
		ft_putnbr_fd(8, fd);
	}	
}
