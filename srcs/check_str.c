/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:23:36 by firawar           #+#    #+#             */
/*   Updated: 2022/07/29 12:28:26 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_third(char *str, int i)
{
	if (str[i] && ft_is_sep(str[i], "<>|")
		&& str[i + 1] && ft_is_sep(str[i + 1], "<>|")
		&& str[i + 2] && ft_is_sep(str[i + 2], "<>|"))
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		return (1);
	}
	return (0);
}

int	ft_return_str(int a, int b)
{
	if (a)
	{
		ft_putstr_fd("Missing a simple quote\n", 2);
		return (1);
	}
	else if (b)
	{
		ft_putstr_fd("Missing a double quote\n", 2);
		return (1);
	}
	return (0);
}

int	ft_quote(char *str, int i)
{
	int	d_quote;
	int	s_quote;

	s_quote = 0;
	d_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (str[i] == '\'' && s_quote == 0 && d_quote == 0)
				s_quote = 1;
			else if (str[i] == '\"' && s_quote == 0 && d_quote == 0)
				d_quote = 1;
			else if (str[i] == '\'' && s_quote == 1)
				s_quote = 0;
			else if (str[i] == '\"' && d_quote == 1)
				d_quote = 0;
		}
		i++;
	}
	return (ft_return_str(s_quote, d_quote));
	return (0);
}

int	ft_check_str(char *str)
{
	int	i;
	int	q;

	q = 0;
	i = -1;
	while (str[++i])
	{
		if (q == 0 && (str[i] == '\'' || str[i] == '\"'))
		{
			if (ft_quote(str, i))
				return (1);
			q = 1;
		}
		if (ft_third(str, i))
			return (1);
	}
	if (ft_is_sep(str[i - 1], "<>|\\"))
	{
		ft_putstr_fd("minishell: syntax error : finish with bad token\n", 2);
		return (1);
	}
	return (0);
}
