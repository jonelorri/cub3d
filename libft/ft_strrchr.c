/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:50:39 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/24 12:33:20 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char)ptr[i] == (unsigned char )c)
			return (ptr + i);
		i--;
	}
	if (c == 0)
		return (ptr + i);
	return (NULL);
}
