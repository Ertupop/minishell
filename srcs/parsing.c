/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:29:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/27 12:34:17 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
void	ft_add_args(t_list **collector, t_arg **args, char *str, int *i)
{
	t_arg	*new;

	new = ft_gc_
}*/

int	ft_number_of_slot(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '|')
		{
			res++;
			i++;
		}
		if (str[i] && str[i] != ' ')
		{
			i++;
			res++;
		}
		while (str[i] && str[i] != ' ' && str[i] != '|')
			i++;
	}
	printf("%d\n", res);
	return (res);
}

t_arg	*ft_parse(t_list **collector, t_arg **args, char *str)
{
	int		i;
	int		pos;
	int		slots;

	i = -1;
	pos = 0;
	slots = ft_number_of_slot(str);
	while (++i < slots)
	{
		//ft_add_arg(collector, args, str, &i);
	}
	(void)collector;
	(void)args;
	return (NULL);
}
