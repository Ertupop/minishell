/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:06:13 by jule-mer          #+#    #+#             */
/*   Updated: 2023/10/30 14:14:21 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_outfile(t_use **use, t_list **collector, int outfile, int append)
{
	t_use	*new;

	new = gc_alloc_use(collector);
	if (outfile > 0)
	{
		new->tokken = OUTFILE;
		new->tab = NULL;
		new->fd = outfile;
		new->eof = NULL;
	}
	else if (append > 0)
	{
		new->tokken = APPEND;
		new->tab = NULL;
		new->fd = append;
		new ->eof = NULL;
	}
	ft_lstadd_back_use(use, new);
}

char	**ft_use_tab(t_bridge *bridge, t_list **collector, int len)
{
	int		i;
	char	**tab;

	i = -1;
	if (len == 0)
		return (NULL);
	tab = gc_alloc_char_r(collector, len);
	while (++i < len)
	{
		while (bridge && (bridge->tokken == OUTFILE || bridge->tokken == INFILE
				|| bridge->tokken == APPEND || bridge->tokken == LIMITER))
			bridge = bridge->next;
		if (bridge)
		{
			tab[i] = ft_gc_strdup(bridge->str, collector);
			bridge = bridge->next;
		}
		else
			tab[i] = NULL;
	}
	return (tab);
}

int	ft_tab_size(t_bridge *bridge)
{
	int		i;

	i = 0;
	while (bridge && bridge->tokken != PIPE)
	{
		if (bridge->tokken != OUTFILE && bridge->tokken != INFILE
			&& bridge->tokken != APPEND && bridge->tokken != LIMITER)
			i++;
		bridge = bridge->next;
	}
	return (i);
}

int	ft_nbr_file(t_bridge *bridge, int *infile, int *outfile)
{
	if (bridge->tokken == INFILE && *infile == 0)
	{
		*infile = 1;
		return (1);
	}
	else if ((bridge->tokken == OUTFILE || bridge->tokken == APPEND)
		&& *outfile == 0)
	{
		*outfile = 1;
		return (1);
	}
	return (0);
}

int	ft_nbr_slots(t_bridge *bridge)
{
	int			res;
	int			pipe_infile;
	int			pipe_outfile;

	res = 1;
	pipe_infile = 0;
	pipe_outfile = 0;
	while (bridge)
	{
		if (bridge && bridge->tokken == PIPE)
		{
			pipe_infile = 0;
			pipe_outfile = 0;
			if (bridge->next && bridge->next->tokken == 0)
				res += 2;
			else
				res++;
		}
		else if (bridge->tokken >= 3 && bridge->tokken <= 6)
			res += ft_nbr_file(bridge, &pipe_infile, &pipe_outfile);
		bridge = bridge->next;
	}
	return (res);
}
