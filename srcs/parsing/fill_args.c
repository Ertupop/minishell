/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:22:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/09/06 17:27:21 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_use(t_use **use, t_arg **args)
{
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
	ft_use(use, args);
	(void)collector;
}
