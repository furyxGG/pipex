/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:03:18 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:43:11 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*first;

	if (!lst || !f || !del)
		return (NULL);
	nlist = ft_lstnew(f(lst->content));
	if (!nlist)
		return (NULL);
	lst = lst->next;
	first = nlist;
	while (lst)
	{
		nlist->next = ft_lstnew(f(lst->content));
		if (!nlist->next)
		{
			ft_lstclear(&first, del);
			return (0);
		}
		nlist = nlist->next;
		lst = lst->next;
	}
	nlist->next = NULL;
	return (first);
}
