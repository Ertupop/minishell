/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:22:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/09/26 14:46:41 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*void	ft_use(t_use **use, t_arg **args, t_list **collector)
{
	t_arg	*tmp;
	t_arg	*last;
	t_use	*new;
	int		i;
	int		size;

	last = *args;
	while (last)
	{
		tmp = last;
		new = gc_create_use(collector);
		ft_use_add_back(use, new);
		if (last->is_command)
		{
			new->tokken = COMMAND;
			size++;
			while (tmp->next && tmp->next->is_argument)
			{
				tmp = tmp->next;
				size++;
			}
			new->tab = gc_alloc_char_r(collector, size);
			new->tab[size] = NULL;
			i = -1;
			while (size--)
			{
				new->tab[++i] = ft_strdup(last->str);

			}
		}
	}
}*/

int	ft_next_is_file(t_arg	*tmp)
{
	if (tmp->next)
		if (tmp->next->next)
			if (tmp->next->next->if_file)
				if (tmp->next->next->next)
					if (tmp->)
				return (1);
	return (0);
}

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
		if (tmp->next == NULL)
			break ;
		last = tmp;
		if (ft_next_is_file(tmp)
		{
		}
	}
	/*while (tmp)
	{
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
		while (tmp->is_action_tokken && tmp->next->next && tmp->next->is_file
			&& tmp->next->next->is_argument)
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
	}*/
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

void	ft_fill_args(t_use **use, t_arg **args, t_list **collector)
{
	ft_args_type(args);
	ft_sort(args, collector);
	//ft_use(use, args, collector);
	(void)use;
}
