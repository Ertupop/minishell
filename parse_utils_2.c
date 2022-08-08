/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:02:23 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/08 10:28:20 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_the_good_tokken(char c)
{
	if (c == '<')
		return (ENTRY);
	else if (c == '>')
		return (EXIT);
	return (PIPE);
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
