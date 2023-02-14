/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:55:55 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/24 12:26:55 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while ((unsigned char)ptr[i] != '\0')
	{
		if (ptr[i] == (char )c)
			return (ptr + i);
		i++;
	}
	if (c == 0)
		return (ptr + i);
	return (NULL);
}
