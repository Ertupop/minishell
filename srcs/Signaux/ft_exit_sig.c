/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_sig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:48:53 by ertupop           #+#    #+#             */
/*   Updated: 2023/09/11 13:53:20 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit_sig_heredoc(int mode, char *end, t_list *gc, int fd)
{
	static char		*mot;
	static t_list	*garbage;
	static t_list	*collect;
	static int		filedesc;

	if (mode == 1)
	{
		mot = end;
		garbage = gc;
		filedesc = fd;
	}
	else if (mode == 2)
		collect = gc;
	else
	{
		(void) mot;
		close(filedesc);
		gc_dell(garbage);
		gc_dell(collect);
	}
}

void	ft_exit_sig(int mode, t_list *gc)
{
	static t_list	*garbage;

	if (mode == 1)
	{
		garbage = gc;
	}
	else
	{
		ft_lstclear(&garbage, free);
	}
}
