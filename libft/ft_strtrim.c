/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:12:34 by ibaines           #+#    #+#             */
/*   Updated: 2022/02/26 10:53:06 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(char *s1, int start, int end);

static int	ft_getstart(char const *s1, char const *set);

static int	ft_getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = (size_t)ft_strlen((char *)s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_get_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_getstart(s1, set);
	end = ft_get_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	ptr = (char *)s1;
	return (ft_trim(ptr, start, end));
}

static char	*ft_trim(char *s1, int start, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(end - start + 1);
	if (!ptr)
		return (0);
	while (start < end)
	{
		ptr[i] = s1[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	ft_get_end(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = (size_t)ft_strlen((char *)s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}
