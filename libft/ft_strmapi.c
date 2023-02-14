/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:53:25 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/24 19:57:54 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr_s;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	ptr_s = malloc(ft_strlen((char *)s) + 1);
	if (!ptr_s)
		return (0);
	while (s[i])
	{
		ptr_s[i] = f(i, (char)s[i]);
		i++;
	}
	ptr_s[i] = '\0';
	return (ptr_s);
}
