/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:05:39 by jule-mer          #+#    #+#             */
/*   Updated: 2023/06/12 18:33:59 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_heredoc2(const char *end, char *str, t_list *gc)
{
	if (str == NULL)
	{
		ft_fprintf(2, "minishell: warning heredoc \
		delimited by end of file (wanted `%s')", end);
		return ;
	}
	if (strcmp(str, end) == 0)
	{
		free(str);
		if (gc)
			gc_dell(gc);
		return ;
	}
}

void	ft_heredoc3(t_easy *work, t_list *gc, int fd)
{
	t_easy	*dell;

	while (work)
	{
		ft_putchar_fd(work->c, fd);
		work = work->next;
	}
	ft_putchar_fd('\n', fd);
	while (work)
	{
		dell = work;
		work = work->next;
		gc_dell_one(gc, &dell);
	}
}
