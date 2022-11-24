/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:06:11 by ertupop           #+#    #+#             */
/*   Updated: 2022/11/22 09:27:41 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		ft_putstr_fd(tmp->str, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}
