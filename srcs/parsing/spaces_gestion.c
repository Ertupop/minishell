/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:09:56 by jule-mer          #+#    #+#             */
/*   Updated: 2023/01/28 20:28:20 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_skip_middle(t_easy **tmp, t_list **collector, int *i)
{
	t_easy	*tmp_2;

	if (((*tmp)->s_quote || (*tmp)->d_quote) && *i == 0)
		*i = 1;
	else if (((*tmp)->s_quote || (*tmp)->d_quote) && *i == 1)
		*i = 0;
	if ((*tmp)->c == ' ' && *i == 0 && (*tmp)->next && (*tmp)->next->c == ' ')
	{
		tmp_2 = (*tmp)->next;
		(*tmp)->next = tmp_2->next;
		gc_dell_one(*collector, tmp_2);
	}
	else
		*tmp = (*tmp)->next;
}

void	ft_skip_start(t_easy **easy, t_easy **tmp, t_list **collector)
{
	t_easy	*tmp_2;

	tmp_2 = *tmp;
	*tmp = (*tmp)->next;
	gc_dell_one(*collector, tmp_2);
	*easy = *tmp;
}

void	ft_skip_space(t_easy **easy, t_list **collector)
{
	t_easy	*tmp;
	int		i;

	i = 0;
	tmp = *easy;
	while (tmp && tmp->space == 1)
		ft_skip_start(easy, &tmp, collector);
	while (tmp)
		ft_skip_middle(&tmp, collector, &i);
	if (*easy && (*easy)->c == ' ')
		*easy = (*easy)->next;
}
