/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:09:27 by ertupop           #+#    #+#             */
/*   Updated: 2022/09/26 17:07:09 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	gc_del_str(t_list *coll, void *addr)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;

	tmp = coll;
	pev = NULL
	while( tmp->next && tmp->content != addr)
	{
		prev = tmp;
		tmp = tmp->next;
	}
}
