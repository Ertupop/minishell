/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:07:44 by jule-mer          #+#    #+#             */
/*   Updated: 2023/06/12 16:19:54 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_good_double(t_easy **tmp, int *i)
{
	if (*i == 0)
		*i = 2;
	else if (*i == 2)
		*i = 0;
	else
		(*tmp)->d_quote = 0;
}

void	ft_good_simple(t_easy **tmp, int *i)
{
	if (*i == 0)
		*i = 1;
	else if (*i == 1)
		*i = 0;
	else
		(*tmp)->s_quote = 0;
}

void	ft_good_quote(t_easy **easy)
{
	t_easy	*tmp;
	int		i;

	tmp = (*easy);
	i = 0;
	while (tmp)
	{
		while (tmp && tmp->c != '\"' && tmp->c != '\'')
			tmp = tmp->next;
		if (tmp && tmp->c == '\'')
			ft_good_simple(&tmp, &i);
		else if (tmp && tmp->c == '\"')
			ft_good_double(&tmp, &i);
		if (tmp)
			tmp = tmp->next;
	}
}

void	ft_check_quote(t_easy **easy)
{
	if ((*easy)->c == '\'')
		(*easy)->s_quote = 1;
	else if ((*easy)->c == '\"')
		(*easy)->d_quote = 1;
}
