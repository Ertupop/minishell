/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:51:29 by jule-mer          #+#    #+#             */
/*   Updated: 2023/10/31 14:52:06 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_size_of_str(t_easy **easy, int i, int len)
{
	int		min;
	char	c;
	t_easy	*tmp;

	i = 0;
	min = 0;
	len = 0;
	c = ' ';
	tmp = *easy;
	if (!tmp)
		return (0);
	while (tmp && ((tmp->c != ' ' && i == 0)
			|| (tmp->c != ' ' && i == 1)) && ++len)
	{
		ft_zos(tmp, &i, &c, &min);
		tmp = tmp->next;
	}
	return (ft_the_result(len, min));
}

int	ft_please(t_easy **easy, int i, int j)
{
	if (*easy && ft_size_of_str(easy, i, j) == 1
		&& (*easy)->c == '\"')
	{
		*easy = (*easy)->next;
		if ((*easy)->next)
			*easy = (*easy)->next;
		if ((*easy)->next)
			*easy = (*easy)->next;
		return (1);
	}
	return (0);
}

char	*ft_the_str(t_easy **easy, t_list **collector, int i, int j)
{
	char	c;
	char	*str;

	i = 0;
	j = 0;
	c = ' ';
	if (ft_please(easy, i, j))
		return (NULL);
	str = gc_alloc_char(collector, ft_size_of_str(easy, i, j));
	while (*easy)
	{
		if (((*easy)->c == '\'' || (*easy)->c == '\"') && i == 0)
			ft_help_line(&i, &c, (*easy)->c, 1);
		else if ((*easy)->c == c && i == 1)
			ft_help_line(&i, &c, (*easy)->c, 2);
		if ((*easy)->c == ' ' && i == 0)
			break ;
		else if (((*easy)->c != c && i == 1)
			|| ((*easy)->c == c && i == 2) || i == 0)
			str[j++] = (*easy)->c;
		if (i == 2)
			i = 0;
		*easy = (*easy)->next;
	}
	return (str);
}

int	ft_number_space(t_easy *easy)
{
	int		len;
	int		i;
	char	c;

	len = 0;
	i = 0;
	c = ' ';
	while (easy)
	{
		if ((easy->c == '\'' || easy->c == '\"') && i == 0)
		{
			i = 1;
			c = easy->c;
		}
		else if (easy->c == c && i == 1)
		{
			i = 0;
			c = ' ';
		}
		if (easy->space && easy->next && i == 0)
			len++;
		easy = easy->next;
	}
	return (len + 1);
}

int	ft_create_bridge(t_easy *easy, t_use **use, t_list **collector)
{
	t_bridge	*bridge;
	t_bridge	*new;
	int			len;
	int			j;

	bridge = NULL;
	new = NULL;
	j = 0;
	len = ft_number_space(easy);
	while (len--)
	{
		new = gc_create_bridge(collector);
		new->str = ft_the_str(&easy, collector, len, j);
		if (easy)
			easy = easy->next;
		if (new && new->str[0])
			ft_lstadd_back_bridge(&bridge, new);
	}
	ft_tokkenisation(&bridge);
	return (ft_use(use, bridge, collector));
}
