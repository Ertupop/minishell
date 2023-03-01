/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:56:25 by jule-mer          #+#    #+#             */
/*   Updated: 2023/02/18 16:07:28 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_good_infile(t_bridge *bridge, int *infile)
{
	int	fd;

	fd = 0;
	while (bridge && bridge->tokken != PIPE)
	{
		if (bridge->tokken == INFILE)
		{
			bridge = bridge->next;
			if (fd)
				close(fd);
			*infile = 0;
		}
		if (bridge->tokken == INFILE)
		{
			fd = access(bridge->str, fd);
			if (fd == -1)
			{
				ft_putstr_fd("minishell : ", 2);
				ft_putstr_fd(bridge->str, 2);
				ft_putstr_fd(":no such file or directory\n", 2);
			}
			else
			{
				fd = open(bridge->str, O_RDONLY, 00644);
				*infile = fd;
			}
		}
		bridge = bridge->next;
	}
}

void	ft_good_outfile(t_bridge *bridge, int *outfile, int *append)
{
	int	fd;

	fd = 0;
	while (bridge && bridge->tokken != PIPE)
	{
		if (bridge->tokken == OUTFILE || bridge->tokken == APPEND)
		{
			bridge = bridge->next;
			if (fd)
				close(fd);
			*outfile = 0;
			*append = 0;
		}
		if (bridge->tokken == OUTFILE)
		{
			fd = open(bridge->str, O_TRUNC | O_CREAT | O_RDWR, 00644);
			*outfile = fd;
		}
		else if (bridge->tokken == APPEND)
		{
			fd = open(bridge->str, O_APPEND | O_CREAT | O_RDWR, 00644);
			*append = fd;
		}
		bridge = bridge->next;
	}
}

void	ft_fill_use_2(t_bridge **bridge, t_use **new)
{
	if ((*bridge)->tokken == PIPE)
	{
		*bridge = (*bridge)->next;
		(*new)->tokken = PIPE;
	}
	else
		while (*bridge && (*bridge)->tokken != PIPE)
			*bridge = (*bridge)->next;
}

void	ft_fill_use(t_list **collector, t_use **use, t_bridge **bridge, int len)
{
	t_use	*new;
	int		infile;
	int		append;
	int		outfile;

	infile = 0;
	outfile = 0;
	append = 0;
	new = gc_alloc_use(collector);
	ft_good_outfile(*bridge, &outfile, &append);
	ft_good_infile(*bridge, &infile);
	new->fd = 0;
	if ((*bridge)->tokken == PIPE)
		len = 1;
	else
		len = ft_tab_size(*bridge);
	new->tab = ft_use_tab(*bridge, collector, len);
	ft_lstadd_back_use(use, new);
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
	slots = ft_nbr_slots(bridge);
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
