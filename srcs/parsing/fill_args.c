/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:22:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/09 12:32:13 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_fill_args(t_arg **args, char *str, t_list **collector)
{
	t_arg	*last_command;
	t_arg	*last_action;
	t_arg	*last;
	t_arg	*tmp;
	int		i;

	tmp = *args;
	last_command = NULL;
	last_action = NULL;
	last = NULL;
	while (tmp)
	{
		//regarde si il s agit d'un action tokken
		if (ft_is_sep(tmp->str[0], "<>|"))
		{
			tmp->is_action_tokken = 1;
			last_action = tmp;
		}
		else if (last->str[0] == '>')
		{
			tmp->is_file = 1;
		}

	}
}
