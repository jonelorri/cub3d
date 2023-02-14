/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:22 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/24 19:58:24 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while ((s1[b] != '\0' || s2[b] != '\0') && a < n)
	{
		if (s1[b] != s2[b])
			return ((unsigned char)s1[b] - (unsigned char)s2[b]);
		a++;
		b++;
	}
	return (0);
}
