/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:23:36 by firawar           #+#    #+#             */
/*   Updated: 2022/08/05 13:12:15 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_ope(char *str, int i)
{
	int	j;

	if (str[i] == '|')
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i] || str[i] == '|')
		{
			if (!str[i])
				ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
			else
				ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
			return (1);
		}
	}
	else if (ft_is_sep(str[i], "<>"))
	{
		j = i;
		while (str[i] && str[i] == ' ')
			i++;
		if (i > j && str[i] && ft_is_sep(str[i], "<>"))
		{
			ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
			return (1);
		}
		else if (str[i + 1] && ft_is_sep(str[i + 1], "<>") && str[i] != str[i + 1])
		{
			ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
			return (1);
		}
		j = i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (i > j || ft_is_sep(str[i], "<>"))
		{
			ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
			return (1);
		}
	}
	return (0);
}

int	ft_check_str(char *str)
{
	int		i;
	char	c;

	i = -1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	while (str[++i])
	{
		if (ft_is_sep(str[i], "\'\""))
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				i++;
			if (str[i++] != c)
			{
				if (c == '\'')
					ft_putstr_fd("minishell: Missing a simple quote\n", 2);
				else
					ft_putstr_fd("minishell: Missing a double quote\n", 2);
				return (1);
			}
		}
		if (ft_ope(str, i))
			return (1);
	}
	return (0);
}
