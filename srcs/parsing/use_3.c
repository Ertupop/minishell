/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:09:16 by jule-mer          #+#    #+#             */
/*   Updated: 2023/05/18 21:03:36 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_launch_heredoc(char *eof, t_list **collector, int fd)
{
	pid_t	child;
	char	*end;
	int		result;

	result = 0;
	child = fork();
	if (child == 0)
	{
		end = ft_strdup(eof);
		gc_dell(*collector);
		ft_heredoc(fd, end);
		free(end);
	}
	else
		waitpid(child, &result, 0);
	if (WIFSIGNALED(result))
	{
		result = WTERMSIG(result) + 128;
		if (WTERMSIG(result) == SIGQUIT)
			write(STDERR_FILENO, "Quit (core dumped)\n", 19);
		else if (WTERMSIG(result) == SIGSEGV)
			write(STDERR_FILENO, "Segmentation fault (core dumped)\n", 33);
	}
	return (result);
}

void	ft_add_heredoc(t_use **use, t_list **collector, int limiter,
			t_bridge *bridge)
{
	t_use	*new;

	while (limiter > 0)
	{
		new = gc_alloc_use(collector);
		new->tokken = LIMITER;
		new->tab = NULL;
		new->fd = ft_acces_heredoc();
		if (new->fd == -1)
			return ;
		while (bridge && bridge->tokken != PIPE)
		{
			if (bridge->tokken == LIMITER)
			{
				bridge = bridge->next;
				new->eof = bridge->str;
			}
			bridge = bridge->next;
		}
		ft_lstadd_back_use(use, new);
		limiter--;
	}
}

void	ft_add_infile(t_use **use, t_list **collector, int infile)
{
	t_use	*new;

	if (infile > 0)
	{
		new = gc_alloc_use(collector);
		new->tokken = INFILE;
		new->tab = NULL;
		new->fd = infile;
		new->eof = NULL;
		ft_lstadd_back_use(use, new);
	}
}
