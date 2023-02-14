/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:40:33 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/01 13:02:26 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getline(int i, ssize_t nbytes, char **res)
{
	char	*mem;
	char	*ptr;

	while (res[0][i] != '\n' && (res[0][i] != '\0'))
		i++;
	if (nbytes == 0 && !ft_strchr(res[0], '\n'))
		i = ft_strlen(res[0]);
	mem = (char *)malloc(i + 2);
	if (!mem)
		return (0);
	ft_strncpy(mem, res[0], i + 1);
	mem[i + 1] = '\0';
	if (!strchr(res[0], '\n'))
		i--;
	ptr = ft_strdup(*res + i + 1);
	free(*res);
	*res = ptr;
	if (nbytes == 0 && **res == '\0' )
	{
		free (*res);
		*res = NULL;
	}
	return (mem);
}

int	ft_firstread(ssize_t nbytes, char **res, char **buf, int fd)
{
	*buf = (char *)malloc(1 + 1);
	if (!*buf)
		return (0);
	if ((*res && !ft_strchr(*res, '\n')) || *res == NULL)
	{
		nbytes = read(fd, *buf, 1);
		if (nbytes <= 0 && (!*res || **res == '\0'))
		{
			free(*buf);
			return (0);
		}
	}
	buf[0][nbytes] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	ssize_t		nbytes;
	int			i;
	char		*buf;
	char static	*res;

	nbytes = 0;
	i = 0;
	if (ft_firstread(nbytes, &res, &buf, fd) == 0)
		return (0);
	if (res == NULL)
		res = ft_strdup(buf);
	else
		res = ft_strjoin(res, buf);
	while (!ft_strchr(res, '\n'))
	{
		nbytes = read(fd, buf, 1);
		if (nbytes == 0 && res)
			break ;
		buf[nbytes] = '\0';
		res = ft_strjoin(res, buf);
	}
	free(buf);
	return (ft_getline(i, nbytes, &res));
}
