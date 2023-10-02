/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:54:00 by jule-mer          #+#    #+#             */
/*   Updated: 2023/09/29 19:32:53 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_execve_one2(t_pipex *pip, t_use *tmp, t_list *gc)
{
	if (pip->command == NULL)
	{
		ft_fprintf(2, "\033[0;36mminishell \033[0;31m: \033");
		ft_fprintf(2, "[0m %s: command not found\n", tmp->tab[0]);
		ft_free_envp(pip->env);
		ft_free_pip(pip);
		g_exit = 127;
		gc_dell(gc);
		exit(127);
	}
	else if (execve(pip->command, tmp->tab, pip->env) == -1)
	{
		ft_free_envp(pip->env);
		ft_free_pip(pip);
		ft_exit(NULL, gc);
	}
}
