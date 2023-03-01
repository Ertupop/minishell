/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:10:49 by jule-mer          #+#    #+#             */
/*   Updated: 2023/02/08 14:12:40 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lstadd_back_use(t_use **alst, t_use *new)
{
	t_use	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast_use(*alst);
	tmp->next = new;
}

t_bridge	*ft_lstlast_bridge(t_bridge *lst)
{
	t_bridge	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_lstadd_back_bridge(t_bridge **alst, t_bridge *new)
{
	t_bridge	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast_bridge(*alst);
	tmp->next = new;
}

t_easy	*ft_lstlast_easy(t_easy *lst)
{
	t_easy	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_lstadd_back_easy(t_easy **alst, t_easy *new)
{
	t_easy	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast_easy(*alst);
	tmp->next = new;
}
