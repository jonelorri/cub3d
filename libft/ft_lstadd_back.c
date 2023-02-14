/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:59:32 by ibaines           #+#    #+#             */
/*   Updated: 2021/11/23 12:55:03 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*test;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	test = *lst;
	while (test->next != NULL)
		test = test->next;
	test->next = new;
}
