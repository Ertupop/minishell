/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:22:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/11/13 13:31:27 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	ft_del_files(t_arg **args, t_list **collector)
{
	t_arg	*tmp;
	t_arg	*del;
	t_arg	*add;
	int		fd;

	tmp = *args;
	while (tmp && tmp->next && tmp->next->next)
	{
		while (tmp->next && !tmp->next->is_file)
		{
			add = tmp;
			tmp = tmp->next;
		}
		if (tmp->next && tmp->next->is_file && tmp->next->next
			&& tmp->next->next->next && tmp->next->next->next->is_file)
		{
			del = tmp;
			tmp = tmp->next->next;
			add->next = tmp;
			fd = open(del->next->str, O_CREAT | O_RDWR, 00644);
			close(fd);
			del->next->next = NULL;
			gc_dell_one(*collector, &del->next);
			del->next = NULL;
			gc_dell_one(*collector, &del);
			del = NULL;
		}
		else
			tmp = tmp->next;
	}
}

void	ft_toto(t_use **use, t_arg **args, t_list **collector)
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
}

void	ft_use(t_use **use, t_arg **args, t_list **collector)
{
	t_arg	*tmp;
	t_use	*new;
	char	**strs;
	int		i;

	tmp = *args;
	while (tmp)
	{
		new = gc_create_use(collector);
		ft_use_add_back(use, new);
		i = 1;
		if (!tmp->next)
		{
			new->tokken = COMMAND;
			new->fd = 0;
			strs = gc_alloc_char_r(collector, 1);
			strs[0] = ft_strdup(tmp->str);
			new->tab = strs;
			new->next = NULL;
			break ;
		}
		else if (tmp->is_command)
		{
			if (!tmp->next)
				break ;
			tmp = tmp->next;
			while (!tmp->is_command)
			{
				i++;
				if (!tmp->next)
					break ;
				if (tmp->next->is_file)
				{
					if (tmp->next->next->next)
						tmp
				}
			}
		}
		printf("%d\n", ++i);
	}
	/*while ((*use))
	{
		i = -1;
		while ((*use)->tab[++i])
			printf("%s\n", (*use)->tab[i]);
		(*use) = (*use)->next;
	}*/
}

void	ft_fill_args(t_use **use, t_arg **args, t_list **collector)
{
	ft_args_type(args);
	ft_del_files(args, collector);
	ft_use(use, args, collector);
	(void)use;
}
