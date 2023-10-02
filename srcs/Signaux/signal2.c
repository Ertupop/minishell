/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:24:37 by ertupop           #+#    #+#             */
/*   Updated: 2023/09/06 23:24:50 by ertupop          ###   ########.fr       */
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
