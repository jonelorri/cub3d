/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:57:06 by ibaines           #+#    #+#             */
/*   Updated: 2021/10/25 13:58:07 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	size_t			i;
	char			*ptr;

	ptr = (char *)b;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return ((void *)ptr);
}
