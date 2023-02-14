/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:03:46 by ibaines           #+#    #+#             */
/*   Updated: 2022/02/18 19:07:23 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_callocitoa(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

static size_t	ft_get_len(int n)
{
	size_t	i;

	i = 0;
	while ((n / 10) >= 1)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

static size_t	ft_check(size_t *i, int *n)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*i = 1;
		return (1);
	}
	*i = 0;
	return (0);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	i;

	if (n != -2147483648)
	{
		i = ft_check(&i, &n);
		i = i + ft_get_len(n);
		ptr = ft_callocitoa(i + 1, 1);
		if (!ptr)
			return (0);
		if (i > 0)
			ptr[0] = '-';
		i--;
		while ((n / 10) >= 1)
		{
			ptr[i] = (n % 10) + 48;
			n = n / 10;
			i--;
		}
		ptr[i] = (n % 10) + 48;
		return (ptr);
	}
	else
		return (ft_strdup("-2147483648"));
}
