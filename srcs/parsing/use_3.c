/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:09:16 by jule-mer          #+#    #+#             */
/*   Updated: 2023/09/22 15:19:16 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_heredoc(t_use **use, t_list **collector, int limiter,
			t_bridge *bridge)
{
	t_use	*new;

	if (limiter > 0)
	{
		new = gc_alloc_use(collector);
		new->tokken = LIMITER;
		new->tab = NULL;
		new->fd = ft_acces_heredoc(new, collector);
		if (new->fd == -1)
			return ;
		while (bridge && bridge->tokken != PIPE)
		{
			if (bridge->tokken == LIMITER)
			{
				bridge = bridge->next;
				new->eof = bridge->str;
			}
			bridge = bridge->next;
		}
		ft_lstadd_back_use(use, new);
	}
}

void	ft_add_infile(t_use **use, t_list **collector, int infile)
{
	t_use	*new;

	if (infile > 0)
	{
		new = gc_alloc_use(collector);
		new->tokken = INFILE;
		new->tab = NULL;
		new->fd = infile;
		new->eof = NULL;
		ft_lstadd_back_use(use, new);
	}
}
