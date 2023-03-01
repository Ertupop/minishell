/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:13:30 by ertupop           #+#    #+#             */
/*   Updated: 2023/02/03 09:19:03 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit = 130;
	}
	else if (signum == SIGQUIT)
		printf("\b\b  \b\b");
}

void	ft_sig_handler_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		exit(130);
		g_exit = 130;
	}
	else if (signum == SIGQUIT)
	{
		rl_redisplay();
		printf("\b\b");
	}
}

void	ft_set_sa(t_sig *signale, void (*f)(int))
{
	sigemptyset(&signale->sa_mask);
	signale->sa_flags = SA_RESTART;
	signale->sa_handler = f;
	if (sigaction(SIGINT, signale, NULL) == -1)
		write(2, "sigaction error", 16);
	signal(SIGQUIT, SIG_IGN);
		// write(2, "sigaction error", 16);
}
