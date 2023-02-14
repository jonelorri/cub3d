/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:55:14 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/24 19:27:33 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_number(char *str, int n);

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 0;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\v' || str[a] == '\n' \
			|| str[a] == '\f' || str[a] == '\r')
	{
		a++;
	}
	while (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			b++;
		a++;
		c++;
	}
	if (str[a] >= '0' && str[a] <= '9' && c < 2)
		return (print_number((char *)str + a, b));
	else
		return (0);
}

static int	print_number(char *str, int n)
{
	long int	c;
	int			a;

	c = 0;
	a = 0;
	while (str[a] >= '0' && str[a] <= '9')
	{
		c = c * 10;
		c = c + (str[a] - '0');
		a++;
	}
	if (n % 2 != 0)
		c = c * -1;
	return (c);
}
