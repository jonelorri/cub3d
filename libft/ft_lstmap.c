/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:14:53 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/23 12:24:07 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_lst;
	t_list	*ptr_result;

	if (!lst || !f)
		return (0);
	ptr_result = NULL;
	while (lst)
	{
		ptr_lst = ft_lstnew(f(lst->content));
		if (!ptr_lst)
			ft_lstdelone(ptr_lst, del);
		ft_lstadd_back(&ptr_result, ptr_lst);
		lst = lst->next;
	}
	return (ptr_result);
}
