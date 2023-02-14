/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:59:52 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/23 16:56:24 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	if (!dst && !src)
		return (dst);
	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	while (0 < n)
	{
		*ptr1++ = *ptr2++;
		n--;
	}
	return (dst);
}
