/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:21:52 by firawar           #+#    #+#             */
/*   Updated: 2022/09/06 16:08:41 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_debug_2(t_arg **args)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = *args;
	while (tmp && ++i)
	{
		printf("\nSlot %d :\n\t", i);
		printf("str : %s", tmp->str);
		if (tmp->is_command)
			printf(" || is command");
		else if (tmp->is_action_tokken)
			printf(" || is action tokken");
		else if (tmp->is_argument)
			printf(" || is argument");
		else if (tmp->is_file)
			printf(" || is file");
		else if (tmp->is_str)
			printf(" || is string");
		tmp = tmp->next;
	}
}

void	ft_debug(t_arg **args)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = *args;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	printf("There is %d slots :\n", i);
	tmp = *args;
	printf("\t");
	while (tmp)
	{
		printf("\"%s\" ", tmp->str);
		tmp = tmp->next;
	}
	printf("\n\n");
	if (DEBUG == DETAILS)
		ft_debug_2(args);
	else
		printf("Use debug details for motre informations");
	printf("\n\n");
}
