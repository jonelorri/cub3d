/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:18:58 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/25 12:13:19 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_ptr(char *s, char c)
{
	int	i;
	int	len;
	int	ptr;

	len = 0;
	i = 0;
	ptr = 0;
	if (c == '\0' && s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			ptr++;
			len = 0;
		}
	}
	return (ptr);
}

static int	ft_res_word(char *s, int len, int i, char **ptr)
{
	char	*wptr;

	wptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!wptr)
		return (-1);
	wptr[len] = '\0';
	len--;
	while (len >= 0)
	{
		wptr[len] = s[len + i];
		len--;
	}
	*ptr = wptr;
	return (0);
}

static int	ft_get_word(char *s, char c, char **ptr, int ptrlen)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	j = 0;
	k = 0;
	len = 0;
	while (s[i] == c)
		i++;
	j = i;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	if (len > 0)
	{
		if (ft_res_word(s, len, j, ptr))
			return (-1);
	}
	if (ptrlen > 1)
		ft_get_word(s + i, c, &ptr[k + 1], ptrlen - 1);
	return (0);
}

static char	**ft_res_pointer(int ptr)
{
	char	**string;
	char	*ptrs;

	string = (char **)malloc((ptr + 1) * sizeof (ptrs));
	if (!string)
		return (NULL);
	return (string);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ptr;
	char	**array;

	if (!s)
		return (NULL);
	i = 0;
	ptr = ft_len_ptr((char *)s, c);
	array = ft_res_pointer(ptr);
	if (ptr > 0)
	{
		if (ft_get_word((char *)s, c, array, ptr))
			return (NULL);
	}
	array[ptr] = NULL;
	return (array);
}
