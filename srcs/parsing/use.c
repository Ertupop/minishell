/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:56:25 by jule-mer          #+#    #+#             */
/*   Updated: 2023/10/31 14:55:55 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_prompt_infile_error(t_bridge *bridge)
{
	ft_putstr_fd("minishell : ", 2);
	ft_putstr_fd(bridge->str, 2);
	ft_putstr_fd(":no such file or directory\n", 2);
	return (1);
}

int	ft_good_infile(t_bridge *bridge, int *infile, int *limiter)
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
			fd = access(bridge->str, fd);
			if (fd == -1)
				return (ft_prompt_infile_error(bridge));
			else
				*infile = open(bridge->str, O_RDONLY, 00644);
		}
		if (bridge->tokken == LIMITER)
		{
			bridge = bridge->next;
			*limiter += 1;
		}
		bridge = bridge->next;
	}
	return (0);
}

void	ft_gdo(t_bridge *bridge, int *fd, int *outfile, int *append)
{
	bridge = bridge->next;
	if (*fd)
		close(*fd);
	*outfile = 0;
	*append = 0;
}

int	ft_good_outfile(t_bridge *bridge, int *outfile, int *append)
{
	int	fd;

	fd = 0;
	while (bridge && bridge->tokken != PIPE)
	{
		if (bridge->tokken == OUTFILE || bridge->tokken == APPEND)
			ft_gdo(bridge, &fd, outfile, append);
		if (bridge->tokken == OUTFILE && ft_strcmp(bridge->str, ">"))
		{
			fd = open(bridge->str, O_TRUNC | O_CREAT | O_RDWR, 00644);
			if (fd == -1)
				return (ft_prompt_infile_error(bridge));
			*outfile = fd;
		}
		else if (bridge->tokken == APPEND && ft_strcmp(bridge->str, ">>"))
		{
			fd = open(bridge->str, O_APPEND | O_CREAT | O_RDWR, 00644);
			*append = fd;
		}
		bridge = bridge->next;
	}
	return (0);
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
