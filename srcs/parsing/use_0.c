/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:58:10 by jule-mer          #+#    #+#             */
/*   Updated: 2023/10/30 16:09:51 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_fu(t_bridge **bridge, int *len)
{
	if ((*bridge)->tokken == PIPE)
		*len = 2;
	else
		*len = ft_tab_size(*bridge);
}

int	ft_fill_use(t_list **collector, t_use **use, t_bridge **bridge, int len)
{
	t_use	*new;
	int		infile;
	int		outfile;
	int		limiter;
	int		append;

	ft_init_for_use(&infile, &append, &outfile, &limiter);
	new = gc_alloc_use(collector);
	if (ft_good_outfile(*bridge, &outfile, &append)
		|| ft_good_infile(*bridge, &infile, &limiter))
		return (1);
	new->fd = 0;
	ft_fu(bridge, &len);
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
	return (0);
}

int	ft_use(t_use **use, t_bridge *bridge, t_list **collector)
{
	int		slots;
	int		len;
	t_use	*tmp;

	len = 0;
	slots = ft_nbr_slots(bridge) + 1;
	while (slots-- && bridge)
		if (ft_fill_use(collector, use, &bridge, len))
			return (1);
	tmp = *use;
	while (tmp)
	{
		if (tmp->tokken < 0 || tmp->tokken > 5)
			tmp->tokken = 0;
		tmp = tmp->next;
	}
	return (0);
}
