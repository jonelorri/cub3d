/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:16:24 by ibaines           #+#    #+#             */
/*   Updated: 2021/10/26 12:16:47 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_c;
	unsigned char	*ptr_s;

	c_c = (unsigned char )c;
	ptr_s = (unsigned char *)s;
	while (0 < n)
	{
		if (*ptr_s == c_c)
			return ((void *)ptr_s);
		ptr_s++;
		n--;
	}
	return (NULL);
}
