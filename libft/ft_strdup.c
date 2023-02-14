/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:08:23 by ibaines           #+#    #+#             */
/*   Updated: 2022/02/18 19:08:42 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;
	size_t	ptrs1;

	i = 0;
	ptrs1 = ft_strlen((char *)s1);
	ptr = (char *)malloc(ptrs1 + 1 + 1);
	if (!ptr)
		return (NULL);
	while (i <= (int)ptrs1)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}
