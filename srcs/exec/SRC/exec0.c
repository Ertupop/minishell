/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:20:12 by jule-mer          #+#    #+#             */
/*   Updated: 2023/06/14 11:45:17 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_exec_all(t_use *use, t_env *env, t_list *gc, t_pipex *pip)
{
	t_use	*tmp;
	t_use	*outfile;

	tmp = use;
	outfile = use;
	pip->count_command = 0;
	pip->prev_pipes = -1;
	while (pip->count_command < pip->nbr_command)
	{
		ft_exec_all2(pip, &outfile);
		while (tmp && tmp->tokken != COMMAND)
			tmp = tmp->next;
		if (tmp->tokken == COMMAND && tmp->tab != NULL)
			pip->childs = fork();
		if (pip->childs == 0)
			ft_exec_pipe(tmp, env, gc, pip);
		ft_exec_all0(&outfile, &pip);
		tmp = tmp->next;
	}
	close(pip->prev_pipes);
	return (ft_wait_lstchild(pip));
}

void	ft_exec_all0(t_use **outfile, t_pipex **pip)
{
	if ((*pip)->prev_pipes != -1)
		close((*pip)->prev_pipes);
	(*pip)->prev_pipes = (*pip)->pipe[0];
	close((*pip)->pipe[1]);
	(*pip)->count_command ++;
	if ((*outfile) != NULL)
		(*outfile) = (*outfile)->next;
}
