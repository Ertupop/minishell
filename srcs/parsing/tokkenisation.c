/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokkenisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:30:46 by jule-mer          #+#    #+#             */
/*   Updated: 2023/05/19 10:57:47 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_is_action(t_bridge **bridge)
{
	if (!ft_strcmp((*bridge)->str, ">"))
	{
		(*bridge)->tokken = OUTFILE;
		(*bridge)->next->tokken = OUTFILE;
	}
	else if (!ft_strcmp((*bridge)->str, ">>"))
	{
		(*bridge)->tokken = APPEND;
		(*bridge)->next->tokken = APPEND;
	}
	else if (!ft_strcmp((*bridge)->str, "<"))
	{
		(*bridge)->tokken = INFILE;
		(*bridge)->next->tokken = INFILE;
	}
	else if (!ft_strcmp((*bridge)->str, "<<"))
	{
		(*bridge)->tokken = LIMITER;
		(*bridge)->next->tokken = LIMITER;
	}
	else if (!ft_strcmp((*bridge)->str, "|"))
		(*bridge)->tokken = PIPE;
}

void	ft_tokkenisation(t_bridge **bridge)
{
	t_bridge	*tmp;

	tmp = *bridge;
	while (tmp)
	{
		if (tmp->tokken == 0)
		{
			ft_is_action(&tmp);
		}
		tmp = tmp->next;
	}
}
