/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:29:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/08 12:50:56 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_parse(t_arg **args, char *str, t_list **collector)
{
	int		i;
	int		j;
	char	c;
	t_arg	*tmp;

	if (ft_check(str))
		return (1);
	i = 0;
	while (str[i])
	{
		//passe les espaces
		while (str[i] && str[i] == ' ')
			i++;
		j = i;

		//gere les pipes
		if (str[j] && ft_is_sep(str[j], "\'\""))
		{
			c = str[j++];
			while (str[j] && str[j] != c)
				j++;
			tmp = gc_create_slot(collector);
			ft_init_quote(collector, &tmp, str, i);
			ft_arg_add_back(args, tmp);
		}

		//gere si sep
		else if (str[j] && ft_is_sep(str[j], "<>|"))
		{
			if (str[j + 1] && str[j + 1] == str[j])
				j++;
			j++;
			tmp = gc_create_slot(collector);
			ft_init_sep(collector, &tmp, str, i);
			ft_arg_add_back(args, tmp);
		}

		//gere si str
		else
		{
			while (str[j] && !ft_is_sep(str[j], " <>|"))
				j++;
			if (j != i)
			{
				tmp = gc_create_slot(collector);
				ft_init_str(collector, &tmp, str, i);
				ft_arg_add_back(args, tmp);
			}
		}
		i = j;
	}
	(void)args;
	(void)collector;
	return (0);
}
