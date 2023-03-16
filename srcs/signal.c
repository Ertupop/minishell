/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:13:30 by ertupop           #+#    #+#             */
/*   Updated: 2023/03/15 10:13:50 by ertupop          ###   ########.fr       */
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
}

void	ft_sig_handler_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		exit(130);
		g_exit = 130;
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
}

void	ft_set_sa_heredoc(t_sig *signale, void (*f)(int), void *end)
{
	static void	*endd;

	(void) endd;
	if (end != NULL)
		endd = end;
	sigemptyset(&signale->sa_mask);
	signale->sa_flags = SA_RESTART;
	signale->sa_handler = f;
	if (sigaction(SIGINT, signale, NULL) == -1)
		write(2, "sigaction error", 16);
	signal(SIGQUIT, SIG_IGN);
}
