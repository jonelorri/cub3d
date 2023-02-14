/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:53:44 by ibaines           #+#    #+#             */
/*   Updated: 2021/10/26 10:52:25 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	srcsize;

	srcsize = (size_t)ft_strlen((char *)src);
	a = 0;
	if (dstsize > 0)
	{
		while (a < dstsize - 1 && *(char *)src)
		{
			*dest = *src;
			src++;
			dest++;
			a++;
		}
		*dest = '\0';
	}
	return (srcsize);
}
