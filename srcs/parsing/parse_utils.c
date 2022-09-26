/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:02:23 by jule-mer          #+#    #+#             */
/*   Updated: 2022/09/13 18:23:37 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

char	**gc_alloc_char_r(t_list **collector, int size)
{
	char	**str;
	t_list	*new;

	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
	{
		gc_dell(*collector);
		exit(1);
	}
	str[size] = NULL;
	new = ft_lstnew(str);
	ft_lstadd_back(collector, new);
	return (str);
}

t_use	*ft_use_last(t_use *list)
{
	t_use	*tmp;

	tmp = list;
	while (list)
	{
		tmp = list;
		list = list->next;
	}
	return (tmp);
}

void	ft_use_add_back(t_use **use, t_use *new)
{
	t_use	*tmp;

	if (!*use)
	{
		*use = new;
		return ;
	}
	tmp = ft_use_last(*use);
	tmp->next = new;
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
