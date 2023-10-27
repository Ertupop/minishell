/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:24:37 by ertupop           #+#    #+#             */
/*   Updated: 2023/10/27 09:41:39 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_set_sa_heredoc(t_sig *signale, void (*f)(int))
{
	sigemptyset(&signale->sa_mask);
	signale->sa_flags = SA_RESTART;
	signale->sa_handler = f;
	if (sigaction(SIGINT, signale, NULL) == -1)
		write(2, "sigaction error", 16);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_set_sa_exec(t_sig *signale, void (*f)(int))
{
	sigemptyset(&signale->sa_mask);
	signale->sa_flags = SA_RESTART;
	signale->sa_handler = f;
	if (sigaction(SIGINT, signale, NULL) == -1)
		write(2, "sigaction error", 16);
	if (sigaction(SIGQUIT, signale, NULL) == -1)
		write(2, "sigaction error", 16);
}
