/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:21:52 by firawar           #+#    #+#             */
/*   Updated: 2022/08/05 12:06:42 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_debug(t_arg **args)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = *args;
	while (tmp && ++i)
	{
		printf("\nSlot %d :\n\t", i);
		printf("is command : %d ", tmp->is_command);
		printf("is action : %d ", tmp->is_action_tokken);
		printf("is argument : %d ", tmp->is_argument);
		printf("is file : %d ", tmp->is_file);
		printf("str : \"%s\"", tmp->str);
		tmp = tmp->next;
	}
	tmp = *args;
	printf("\n");
	while (tmp)
	{
		printf("%s ", tmp->str);
		tmp = tmp->next;
	}
	printf("\n\n");
}
