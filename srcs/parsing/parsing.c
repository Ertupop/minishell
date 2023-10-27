/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:35:20 by jule-mer          #+#    #+#             */
/*   Updated: 2023/06/12 17:10:03 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_easy(t_easy *easy)
{
	easy->space = 0;
	easy->d_quote = 0;
	easy->s_quote = 0;
	easy->dell = 0;
	easy->c = '\0';
	easy->next = NULL;
}

void	ft_good_help_3(t_easy **new, t_easy **easy, t_list **collector)
{
	*new = gc_create_easy(collector);
	ft_init_easy(*new);
	(*new)->space = 1;
	(*new)->c = ' ';
	(*new)->next = (*easy)->next;
	(*easy)->next = *new;
}

void	ft_good_help_2(t_easy **new, t_easy **easy, t_list **collector)
{
	*new = gc_create_easy(collector);
	ft_init_easy(*new);
	(*new)->space = 1;
	(*new)->c = ' ';
	(*new)->next = (*easy)->next;
	(*easy)->next = *new;
}

void	ft_good_help(t_easy *easy, int *s, int *d)
{
	if (easy->c == '\'' && *d == 0)
	{
		if (*s == 0)
			*s = 1;
		else
			*s = 0;
	}
	if (easy->c == '\"' && *s == 0)
	{
		if (*d == 0)
			*d = 1;
		else
			*d = 0;
	}
}

void	ft_good_place(t_easy **first, t_list **collector)
{
	int		s;
	int		d;
	t_easy	*new;
	t_easy	*easy;

	easy = *first;
	new = NULL;
	s = 0;
	d = 0;
	while (easy)
	{
		ft_good_help(easy, &s, &d);
		if (!s && !d && easy->c != ' ' && easy->c != '<'
			&& easy->c != '>' && easy->next && ((easy->next->c == '<')
				|| (easy->next->c == '>') || (easy->next->c == '|')))
			ft_good_help_2(&new, &easy, collector);
		if (!s && !d && (easy->c == '>' || easy->c == '<') && easy->next
			&& easy->next->c != '>' && easy->next->c != '<'
			&& easy->next->c != ' ')
			ft_good_help_3(&new, &easy, collector);
		easy = easy->next;
	}
}
