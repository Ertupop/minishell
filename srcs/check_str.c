/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:23:36 by firawar           #+#    #+#             */
/*   Updated: 2022/08/08 13:19:43 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_action(char *str, int *j)
{
	int		i;
	char	c;

	i = *j;
	if (str[i] == '|')
	{
		i++;
		while (str[i] == ' ')

	}
	else if (str[i] == '<' || str[i] == '>')
	{
		c = str[i++];
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && ((i - *j > 1 && ft_is_sep(str[i], "<>|"))
				|| (ft_is_sep(str[i], "<>|") && str[i] != c)))
			return (ft_error(1, str[i]));
		else if (!str[i])
			return (ft_error(1, c));
		else if (str[i] == c)
		{
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] && ft_is_sep(str[i], "<>|"))
				return (ft_error(1, str[i]));
			else if (!str[i])
				return (ft_error(1, c));
		}
	}
	*j = i;
	return (0);
}

int	ft_quote(char *str, int *j)
{
	char	c;
	int		i;

	i = *j;
	if (str[i] && (str[i] == '\'' || str[i] == '\"'))
	{
		c = str[i++];
		while (str[i] && str[i] != c)
			i++;
		if (!str[i])
			return (ft_error(0, c));
	}
	*j = i;
	return (0);
}

int	ft_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		//saute les espaces
		while (str[i] == ' ')
			i++;

		//verifie si quote manquant
		if (str[i] && ft_quote(str, &i))
			return (1);

		//gere les action tokken
		else if (str[i] && ft_action(str, &i))
			return (1);
		i++;
		//
	}
	return (0);
}
