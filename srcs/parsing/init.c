/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:55:16 by firawar           #+#    #+#             */
/*   Updated: 2022/08/14 20:06:08 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_end_init(t_arg **new)
{
	(*new)->is_command = 0;
	(*new)->is_action_tokken = 0;
	(*new)->is_argument = 0;
	(*new)->is_file = 0;
	(*new)->next = NULL;
}

int	ft_init_quote_2(int i, char *str)
{
	char	c;

	c = str[i];
	while (c == '\'' || c == '\"')
	{
		while (str[i] && str[i] != c)
			i++;
		if (str[i] && ft_is_sep(str[i], "\'\""))
			c = str[i++];
		else
			c = '\0';
	}
	return (i);
}

void	ft_init_quote(t_list **collector, t_arg **new, char *str, int j)
{
	int		i;
	int		start;
	char	c;

	i = ft_init_quote_2(j, str);
	(*new)->str = gc_alloc_char(collector, i - j - 1);
	start = 0;
	c = str[j++];
	while (j < i - 1)
	{
		while (c == '\'' || c == '\"')
		{
			while (str[j] && str[j] != c)
				(*new)->str[start++] = str[j++];
			if (str[j] == c)
				j++;
			if (str[j] && (str[j] == '\'' || str[j] == '\"') && str[j - 1] == c)
				c = str[j++];
			else
				c = str[j++];
		}
	}
	(*new)->str[start] = '\0';
	ft_end_init(new);
}

void	ft_init_sep(t_list **collector, t_arg **new, char *str, int i)
{
	int	j;
	int	start;

	j = i;
	while (str[j] && ft_is_sep(str[j], "<>|"))
	{
		j++;
		if (j - i > 1 && str[j] != str[j - 1])
			break ;
	}
	(*new)->str = gc_alloc_char(collector, j - i);
	i--;
	start = -1;
	while (++i < j)
		(*new)->str[++start] = str[i];
	(*new)->str[++start] = '\0';
	ft_end_init(new);
}
