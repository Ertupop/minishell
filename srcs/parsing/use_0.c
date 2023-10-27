/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:58:10 by jule-mer          #+#    #+#             */
/*   Updated: 2023/09/06 23:25:30 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_fill_use(t_list **collector, t_use **use, t_bridge **bridge, int len)
{
	t_use	*new;
	int		infile;
	int		append;
	int		outfile;
	int		limiter;

	ft_init_for_use(&infile, &append, &outfile, &limiter);
	new = gc_alloc_use(collector);
	ft_good_outfile(*bridge, &outfile, &append);
	ft_good_infile(*bridge, &infile, &limiter);
	new->fd = 0;
	if ((*bridge)->tokken == PIPE)
		len = 2;
	else
		len = ft_tab_size(*bridge);
	if (len > 0)
		new->tab = ft_use_tab(*bridge, collector, len);
	ft_lstadd_back_use(use, new);
	if (limiter > 0)
		ft_add_heredoc(use, collector, limiter, *bridge);
	ft_fill_use_2(bridge, &new);
	if (outfile > 0 || append > 0)
		ft_add_outfile(use, collector, outfile, append);
	if (infile > 0)
		ft_add_infile(use, collector, infile);
}

void	ft_use(t_use **use, t_bridge *bridge, t_list **collector)
{
	int		slots;
	int		len;
	t_use	*tmp;

	len = 0;
	slots = ft_nbr_slots(bridge) + 1;
	while (slots-- && bridge)
		ft_fill_use(collector, use, &bridge, len);
	tmp = *use;
	while (tmp)
	{
		if (tmp->tokken < 0 || tmp->tokken > 5)
			tmp->tokken = 0;
		tmp = tmp->next;
	}
}
