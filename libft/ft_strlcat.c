/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:45:58 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/24 19:56:35 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	l_dest;
	size_t	l_src;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	l_dest = ft_strlen(dest);
	l_src = ft_strlen((char *)src);
	i = 0;
	while (l_dest + i < dstsize - 1 && src[i] != '\0')
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	if (dstsize <= l_dest)
		return (l_src + dstsize);
	return (l_dest + l_src);
}
