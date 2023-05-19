/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:28:03 by ertupop           #+#    #+#             */
/*   Updated: 2023/05/19 08:45:42 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exec_heredoc(t_use **use, t_env *env)
{
	while(*use)
	{
		if ((*use)->tokken == LIMITER)
		{

		}
		(*use)->next;
	}
}
