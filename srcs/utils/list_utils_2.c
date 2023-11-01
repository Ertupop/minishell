/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:12:14 by jule-mer          #+#    #+#             */
/*   Updated: 2023/10/30 15:47:37 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	t_env	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_lstadd_back_env(t_env **alst, t_env *new)
{
	t_env	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast_env(*alst);
	tmp->next = new;
}

t_use	*ft_lstlast_use(t_use *lst)
{
	t_use	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_dell_easy(t_easy *easy, t_list **collector)
{
	t_easy	*dell;

	while (easy)
	{
		dell = easy;
		easy = easy->next;
		gc_dell_one(*collector, &dell);
	}
}

void	ft_init_for_use(int *i, int *o, int *a, int *l)
{
	*i = 0;
	*o = 0;
	*a = 0;
	*l = 0;
}
