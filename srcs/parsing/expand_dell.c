/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:02:57 by jule-mer          #+#    #+#             */
/*   Updated: 2023/01/29 11:55:03 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_quote(int i, int j)
{
	if (i == 1 || j == 1)
		return (1);
	return (0);
}

void	ft_dell_dollar_2(t_easy **tmp, t_easy **tmp_2, t_list **col, int i)
{
	if ((*tmp)->dell == 1 || ((*tmp)->c == '$' && i > 0))
	{
		(*tmp_2)->next = (*tmp)->next;
		gc_dell_one(*col, *tmp);
		(*tmp) = (*tmp_2);
	}
	else
	{
		(*tmp_2) = (*tmp);
		(*tmp) = (*tmp)->next;
	}
}

void	ft_dell_dollar(t_easy **easy, t_list **collector)
{
	t_easy	*tmp;
	t_easy	*tmp_2;
	int		s_quote;
	int		d_quote;

	s_quote = -1;
	d_quote = -1;
	tmp = *easy;
	if (tmp->dell == 1 || (tmp->c == '$' && tmp->next
			&& (tmp->next->c == '\'' || tmp->next->c == '\"')))
	{
		tmp_2 = tmp;
		tmp = tmp_2->next;
		*easy = tmp;
		gc_dell_one(*collector, tmp_2);
	}
	tmp_2 = tmp;
	while (tmp)
	{
		if (tmp->c == '\'')
			s_quote *= -1;
		else if (tmp->c == '\"')
			d_quote *= -1;
		ft_dell_dollar_2(&tmp, &tmp_2, collector, ft_quote(s_quote, d_quote));
	}
}
