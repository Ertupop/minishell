/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:29:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/27 18:46:20 by firawar          ###   ########.fr       */
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
		pos++;
		arg->str = gc_alloc_char(collector, 1);
		arg->str = ft_the_god_sep(str[pos]);
	}
	else
	{
		len = pos;
		while (str[len] && !ft_is_sep(str[pos], " <>|\'\""))
			len++;
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
	(*new)->is_pipe = 0;
	(*new)->is_outfile = 0;
	(*new)->str = NULL;
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
	}
	ft_init_arg(&new);
	ft_lstadd_back(collector, col);
	return (new);
}

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
		if (str[i] && ft_is_sep(str[i], "<>|\'\""))
		{
			res++;
			i++;
		}
		if (str[i] && str[i] != ' ')
		{
			i++;
			res++;
		}
		while (str[i] && !ft_is_sep(str[i], " <>|\'\""))
			i++;
	}
	return (res);
}

t_arg	*ft_parse(t_arg **args, char *str, t_list **collector)
{
	int	i;
	int	slots;
	int	pos;

	slots = ft_number_of_slot(str);
	i = -1;
	while (++i < slots)
		ft_arg_add_back(args, gc_create_slot(collector));
	pos = 0;
	while (str[pos] && str[pos] == ' ')
		pos++;
	while ((*args))
	{
		ft_fill_arg(*args, str, &pos, collector);
		*args = (*args)->next;
	}
	ft_fill_arg(*args, str, &pos, collector);
	return (NULL);
}
