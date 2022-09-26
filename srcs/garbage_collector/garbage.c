/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:52:09 by firawar           #+#    #+#             */
/*   Updated: 2022/09/07 15:17:40 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_use	*gc_create_use(t_list **collector)
{
	t_use	*new;
	t_list	*col;

	new = malloc(sizeof(t_use));
	col = ft_lstnew(new);
	if (!new || !col)
	{
		ft_putstr_fd("Error in usable creation", 2);
		gc_dell(*collector);
		exit (1);
	}
	ft_lstadd_back(collector, col);
	return (new);
}

t_arg	*gc_create_slot(t_list **collector)
{
	t_arg	*new;
	t_list	*col;

	new = malloc(sizeof(t_arg));
	col = ft_lstnew(new);
	if (!new || !col)
	{
		ft_putstr_fd("Error in slot creation", 2);
		gc_dell(*collector);
		exit (1);
	}
	ft_lstadd_back(collector, col);
	return (new);
}