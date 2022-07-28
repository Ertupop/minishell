/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:21:52 by firawar           #+#    #+#             */
/*   Updated: 2022/07/28 13:25:18 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_debug(t_arg **args)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = *args;
	while (tmp)
	{
		printf("\nSlot %d :\n", i);
		printf("\tis_action_tokken = %d\n\tis_argument = %d\n\tis_option = %d\n\tis_outfile = %d\n", tmp->is_action_tokken, tmp->is_argument, tmp->is_option, tmp->is_outfile);
		if (tmp->str)
			printf("\tstr = %s\n", tmp->str);
		else
			printf("\tstr = (nul)\n");
		if (tmp->option)
			printf("\toption = %s\n\n", tmp->option);
		else
			printf("\toption = (nul)\n");
		tmp = tmp->next;
		i++;
	}
}
