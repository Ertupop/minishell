/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:21:49 by jule-mer          #+#    #+#             */
/*   Updated: 2021/12/01 16:34:38 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_e;

	if (!f || !del)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		new_e = ft_lstnew(f(lst->content));
		if (!new_e)
		{
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_e);
		lst = lst->next;
	}
	return (new_l);
}
