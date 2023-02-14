/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:49:46 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/23 12:19:28 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstnext;

	if (lst && del)
	{
		while (*lst)
		{
			lstnext = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lstnext;
		}
	}
}
