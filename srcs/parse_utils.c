/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:19:20 by firawar           #+#    #+#             */
/*   Updated: 2022/07/28 19:31:55 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_fill_arg(t_arg *arg, char *str, int *receive, t_list **collector)
{
	int	pos;
	int	len;
	int	i;

	pos = *receive;
	if (ft_is_sep(str[pos], "<>|\'\""))
	{
		arg->is_action_tokken = ft_the_good_tokken(str[pos]);
		pos++;
	}
	else
	{
		len = pos;
		while (str[len] && !ft_is_sep(str[len], " |<>\'\""))
			len++;
		arg->str = gc_alloc_char(collector, len - pos);
		i = 0;
		while (pos < len)
			arg->str[i++] = str[pos++];
		arg->str[i] = '\0';
	}
	*receive = pos;
	(void)arg;
}

void	ft_init_arg(t_arg **new)
{
	(*new)->is_action_tokken = 0;
	(*new)->is_argument = 0;
	(*new)->is_option = 0;
	(*new)->is_outfile = 0;
	(*new)->str = NULL;
	(*new)->option = NULL;
	(*new)->next = NULL;
}

t_arg	*gc_create_slot(t_list **collector)
{
	t_arg	*new;
	t_list	*col;

	new = malloc(sizeof(t_arg));
	col = ft_lstnew(new);
	if (!new || !col)
	{
		ft_putstr_fd("Error in slot creation", 2);
		gc_dell(*collector);
		return (NULL);
	}
	ft_init_arg(&new);
	ft_lstadd_back(collector, col);
	return (new);
}

int	ft_number_of_slot(char *str, int i, int res)
{
	i = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
		{
			res++;
			i++;
			if (str[i] && ft_is_sep(str[i], "<>|\'\""))
			{
				i++;
				res++;
				if (str[i] && !ft_is_sep(str[i], " <>|\"\""))
				{
					i++;
					res++;
				}
			}
		}
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (res);
}
