/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:10:17 by jule-mer          #+#    #+#             */
/*   Updated: 2023/10/30 16:08:05 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_start_easy(t_easy **easy, t_list **collector, t_parse *parse)
{
	t_easy	*new;

	new = gc_create_easy(collector);
	ft_init_easy(new);
	new->c = parse->str[parse->i++];
	if (new->c == ' ')
		new->space = 1;
	ft_check_quote(&new);
	ft_lstadd_back_easy(easy, new);
}

void	ft_dell_tab(t_parse *parse)
{
	int	i;

	i = -1;
	while (parse->str[++i])
		if (parse->str[i] == '\t')
			parse->str[i] = ' ';
}

int	ft_check_check_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			i++;
			if (str[i] == '<')
				i++;
			while (str[i] == ' ')
				i++;
			if ((str[i] == '\'' && str[i + 1] == '\'')
				|| (str[i] == '\"' && str[i + 1] == '\"'))
				return (ft_prompt_check_error());
		}
		i++;
	}
	return (0);
}

int	ft_check_check_1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
		{
			i++;
			if (str[i] == '>')
				i++;
			while (str[i] == ' ')
				i++;
			if ((str[i] == '\'' && str[i + 1] == '\'')
				|| (str[i] == '\"' && str[i + 1] == '\"'))
				return (ft_prompt_check_error());
		}
		i++;
	}
	return (0);
}

int	ft_parse(t_use **use, t_parse *parse, t_list **collector, t_env **env)
{
	t_easy	*easy;
	t_easy	*tmp;

	easy = NULL;
	ft_dell_tab(parse);
	if (ft_check_parse(parse->str) || ft_check_check_1(parse->str)
		|| ft_check_check_2(parse->str))
		return (1);
	while (parse->str[parse->i])
		ft_start_easy(&easy, collector, parse);
	ft_p(&easy, collector, env);
	tmp = easy;
	while (tmp)
	{
		if (tmp->next && (tmp->next->d_quote || tmp->next->s_quote))
			tmp->next = tmp->next->next;
		else
			tmp = tmp->next;
	}
	ft_p2(&easy, collector, parse);
	if (ft_create_bridge(easy, use, collector))
		return (1);
	return (0);
}
