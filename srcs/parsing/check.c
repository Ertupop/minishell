/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:31:41 by jule-mer          #+#    #+#             */
/*   Updated: 2023/02/08 16:36:41 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_in(char c, char *in)
{
	int	i;

	i = -1;
	while (in[++i])
	{
		if (in[i] == c)
			return (1);
	}
	return (0);
}

int	ft_action_2(char *str, int *j)
{
	char	c;
	int		i;

	i = *j;
	c = str[i++];
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && ((i - *j > 1 && ft_is_in(str[i], "<>|"))
			|| (ft_is_in(str[i], "<>|") && str[i] != c)))
		return (ft_error(1, str[i]));
	else if (!str[i])
		return (ft_error(1, c));
	else if (str[i] == c)
	{
		i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && ft_is_in(str[i], "<>|"))
			return (ft_error(1, str[i]));
		else if (!str[i])
			return (ft_error(1, c));
	}
	*j = i;
	return (0);
}

int	ft_action(char *str, int *j)
{
	int	i;

	i = *j;
	if (str[i] == '|')
	{
		i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i] || (str[i] && str[i] == '|'))
			return (ft_error(1, '|'));
	}
	else
		if (ft_action_2(str, &i))
			return (1);
	*j = i - 1;
	return (0);
}

int	ft_checking_quote(char *str, int *j)
{
	int		i;
	char	c;

	i = *j;
	c = str[i++];
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (ft_error(0, c));
	*j = i;
	return (0);
}

int	ft_check_parse(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '|')
		return (ft_error(1, '|'));
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && !ft_is_in(str[i], " <>\'\""))
			i++;
		if (str[i] && ft_is_in(str[i], "\'\"") && ft_checking_quote(str, &i))
			return (1);
		else if (str[i] && ft_is_in(str[i], "<>") && ft_action(str, &i))
			return (1);
		else if (str[i])
			i++;
	}
	if (str[ft_strlen(str) - 1] == '|')
		return (ft_error(1, '|'));
	return (0);
}
