/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:02:23 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/28 12:20:08 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_the_good_tokken(char c)
{
	if (c == '<')
		return (ENTRY);
	else if (c == '>')
		return (EXIT);
	else if (c == '|')
		return (PIPE);
	else if (c == '\'')
		return (S_QUOTE);
	return (D_QUOTE);
}

int	ft_is_sep(char c, char *sep)
{
	int		i;

	i = -1;
	while (sep[++i])
	{
		if (sep[i] == c)
			return (1);
	}
	return (0);
}

t_arg	*ft_arg_last(t_arg *list)
{
	t_arg	*tmp;

	tmp = list;
	while (list)
	{
		tmp = list;
		list = list->next;
	}
	return (tmp);
}

void	ft_arg_add_back(t_arg **args, t_arg *new)
{
	t_arg	*tmp;

	if (!*args)
	{
		*args = new;
		return ;
	}
	tmp = ft_arg_last(*args);
	tmp->next = new;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s2[i])
	{
		if (s1[i] == '\0' || s1[i] == ' ')
			return (0);
	}
	return (1);
}
