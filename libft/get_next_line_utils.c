/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:16:03 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/01 13:03:14 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	cont;

	cont = 0;
	while (*(str) != '\0')
	{
		cont++;
		str = str + 1;
	}
	return (cont);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr1;
	int		i;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ptr1 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr1)
		return (NULL);
	while (s1[i])
	{
		ptr1[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr1[i + j] = s2[j];
		j++;
	}
	ptr1[j + i] = '\0';
	free((char *)s1);
	return (ptr1);
}

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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while (a < n && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}
