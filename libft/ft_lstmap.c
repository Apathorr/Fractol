/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:56:11 by rsmith            #+#    #+#             */
/*   Updated: 2019/02/20 12:10:06 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*pnlist;
	t_list	*nlist;

	if (!lst)
		return (NULL);
	if (!(nlist = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	nlist = f(lst);
	pnlist = nlist;
	while (lst->next)
	{
		pnlist->next = f(lst->next);
		pnlist = pnlist->next;
		lst = lst->next;
	}
	return (nlist);
}
