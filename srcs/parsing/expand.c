/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:29:12 by jule-mer          #+#    #+#             */
/*   Updated: 2023/10/26 20:18:29 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_easy	*ft_create_expand(char *str, t_list **collector)
{
	t_easy	*easy;
	t_easy	*new;
	int		i;

	easy = NULL;
	i = -1;
	while (str[++i])
	{
		new = gc_create_easy(collector);
		ft_init_easy(new);
		new->c = str[i];
		ft_lstadd_back_easy(&easy, new);
	}
	return (easy);
}

void	ft_expand_exit(t_easy **easy, t_list **collector)
{
	t_easy	*expand;
	t_easy	*tmp;
	t_easy	*tmp_2;

	tmp = (*easy)->next;
	expand = ft_create_expand(ft_itoa_2(g_exit, collector), collector);
	if ((*easy)->next && (*easy)->next->next)
	{
		tmp_2 = expand;
		while (expand && expand->next)
			expand = expand->next;
		expand->next = (*easy)->next->next;
		expand = tmp_2;
	}
	(*easy)->next = expand;
	(*easy)->dell = 1;
	gc_dell_one(*collector, tmp);
}

void	ft_apply_expand(char *str, t_easy **easy, t_list **collector)
{
	t_easy	*expand;
	t_easy	*tmp;
	t_easy	*dell;
	t_easy	*tmp_2;

	tmp = (*easy)->next;
	expand = ft_create_expand(str, collector);
	tmp_2 = expand;
	while (tmp && tmp->d_quote == 0 && tmp->c != '$' && tmp->c != ' ')
	{
		dell = tmp;
		tmp = tmp->next;
		gc_dell_one(*collector, dell);
	}
	while (expand->next)
		expand = expand->next;
	expand->next = tmp;
	(*easy)->next = tmp_2;
	(*easy)->dell = 1;
}

void	ft_check_expand(t_easy **easy, t_list **collector, t_env **env)
{
	t_easy	*tmp;
	t_easy	*start;
	int		len;
	char	*str;

	tmp = (*easy)->next;
	start = tmp;
	len = 0;
	while (tmp && tmp->d_quote == 0 && tmp->c != '$' && tmp->c != ' '
		&& ++len >= 0)
		tmp = tmp->next;
	str = gc_alloc_char(collector, len);
	len = 0;
	while (start && start->d_quote == 0 && start->c != '$' && start->c != ' ')
	{
		str[len++] = start->c;
		start = start->next;
	}
	if (ft_find_env(*env, ft_strcat(str, "=", collector)))
		ft_apply_expand(ft_split_env(
				ft_find_env(*env, ft_strcat(
						str, "=", collector))), easy, collector);
	else
		ft_apply_expand(" ", easy, collector);
}

void	ft_expand(t_easy **easy, t_list **collector, t_env **env)
{
	t_easy	*tmp;
	int		i;
	int		j;

	i = 1;
	j = -1;
	tmp = *easy;
	while (tmp)
	{
		if (tmp->s_quote == 1)
			i *= -1;
		else if (tmp->d_quote == 1)
			j *= -1;
		if (tmp->c == '$' && tmp->next && tmp->next->c == '?')
			ft_expand_exit(&tmp, collector);
		else if (tmp->c == '$' && j == 1 && tmp->next
			&& tmp->next->c != ' ' && tmp->next->c != '\"')
			ft_check_expand(&tmp, collector, env);
		else if (tmp->c == '$' && i == 1 && tmp->next && tmp->next->c != ' '
			&& tmp->next->c != '\"' && tmp->next->c != '\'')
			ft_check_expand(&tmp, collector, env);
		tmp = tmp->next;
	}
	ft_dell_dollar(easy, collector);
}
