/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:22:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/09/13 14:31:45 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_nbr_tab(t_arg **args)
{
	int		i;
	t_arg	*tmp;

	tmp = *args;
	if (tmp->is_action_tokken || tmp->is_file)
		return (1);
	i = 0;
	while (tmp)
	{
		if (i != 0 && tmp->is_command)
			break ;
		else if (tmp->is_command || tmp->is_argument)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_nbr_use(t_arg **args)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = *args;
	while (tmp)
	{
		if (tmp->is_command || tmp->is_action_tokken || tmp->is_file)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

/*void	ft_use(t_use **use, t_arg **args, t_list **collector)
{
	t_use	*new;
	t_use	*list;
	int		nbr;
	int		i;
	int		j;
	int		k;

	i = -1;
	list = NULL;
	nbr = ft_nbr_use(args);
	while (++i < nbr)
	{
		new = gc_create_use(collector);
		j = ft_nbr_tab(args);
		new->tab = gc_alloc_char_r(collector, j);
		k = -1;
		while (++k < j)
		{
			new->tab[k] = gc_alloc_char(collector, ft_stlre)
		}
	}
	(void)list;
	(void)new;
	(void)use;
	(void)args;
}*/

void	ft_sort(t_arg **args, t_list **collector)
{
	t_arg	*last;
	t_arg	*tmp;
	t_arg	*del;
	int		fd;

	last = NULL;
	tmp = *args;
	while (tmp)
	{
		if (last)
			printf("%s\n", last->str);
		if ((tmp->is_command || tmp->is_argument) && tmp->next
			&& tmp->next->is_action_tokken && tmp->next->next->is_file)
			last = tmp;
		else if (tmp->is_action_tokken && tmp->next->next && tmp->next->is_file
			&& tmp->next->next->next && tmp->next->next->is_action_tokken
			&& tmp->next->next->next->is_file)
		{
			fd = open(tmp->next->str, O_CREAT | O_RDWR, 00644);
			close(fd);
			del = tmp;
			last->next = tmp->next->next;
			del->next->next = NULL;
			gc_dell_one(*collector, &del->next);
			del->next = NULL;
			gc_dell_one(*collector, &del);
			tmp = last;
			last = tmp->next;
		}
		while (tmp->is_action_tokken && tmp->next->next && tmp->next->is_file && tmp->next->next->is_argument)
		{
			if (tmp->next->next->is_action_tokken)
				break ;
			last->next = tmp->next->next;
			tmp->next->next = last->next->next;
			last->next->next = tmp;
			last = last->next;
			printf("tmp = %s et last = %s\n", tmp->str, last->str);
		}
		last = tmp;
		tmp = tmp->next;
	}
}

void	ft_args_type(t_arg **args)
{
	t_arg	*tmp;

	tmp = (*args);
	tmp->is_command = 1;
	if (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->is_str)
			tmp->is_argument = 1;
	}
	while (tmp->next)
	{
		if (tmp->is_file && tmp->next->is_str)
			tmp->next->is_argument = 1;
		else if (tmp->is_action_tokken)
		{
			if (ft_strcmp(tmp->str, "|"))
				tmp->next->is_file = 1;
			else
				tmp->next->is_command = 1;
		}
		else if (tmp->is_str)
			tmp->next->is_argument = 1;
		tmp = tmp->next;
	}
}

//Remplir use
void	ft_fill_args(t_use **use, t_arg **args, t_list **collector)
{
	ft_args_type(args);
	ft_sort(args, collector);
	//ft_use(use, args, collector);
	(void)use;
	(void)collector;
}
