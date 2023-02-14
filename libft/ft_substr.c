/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:15:09 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/24 20:04:31 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mem(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	if (start <= (unsigned int)ft_strlen((char *)s))
	{	
		if ((unsigned int)ft_strlen((char *)s) - start >= len)
		{
			return (ft_mem(s, start, len));
		}
		else
			return \
		(ft_mem(s, start, (size_t)ft_strlen((char *)s) - (size_t)start));
	}
	else
		return \
		(ft_mem(s, start, 0));
}

static char	*ft_mem(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;	

	i = 0;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
