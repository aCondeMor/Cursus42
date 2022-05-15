/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:57:21 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/16 00:15:50 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;

	if ((!lst))
		return (0);
	newlst = 0;
	while (lst)
	{
		node = ft_lstnew(f((*lst).content));
		if (!node)
		{
			ft_lstclear(&node, del);
			return (0);
		}
		ft_lstadd_back(&newlst, node);
		lst = (*lst).next;
	}
	return (newlst);
}
