/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 06:27:10 by ertupop           #+#    #+#             */
/*   Updated: 2022/07/29 10:40:38 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

//faire echo avec option -n
void	ft_echo(t_arg *lst)
{
	int		i;
	char	*str;
	t_arg	*tmp;

	i = -1;
	tmp = lst;
	if (tmp)

	while (str[++i])
		write(1, &str[i], 1);
	return (0);
}

// faire cd

// faire pwd

// faire export

// faire unset

// faire env

// faire exit
