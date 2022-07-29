/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 06:27:10 by ertupop           #+#    #+#             */
/*   Updated: 2022/07/29 08:00:28 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//faire echo avec option -n
void	ft_echo(t_arg)
{
	int		i;
	char	*str;
	va_list	lst;

	va_start
	i = -1;

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
