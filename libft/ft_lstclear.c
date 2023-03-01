/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:46:49 by jule-mer          #+#    #+#             */
/*   Updated: 2023/01/23 06:44:10 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		elem = *lst;
		*lst = elem->next;
		free(elem);
	}
	*lst = NULL;
}
