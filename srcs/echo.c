/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 06:27:10 by ertupop           #+#    #+#             */
/*   Updated: 2022/08/01 06:47:13 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

//faire echo avec option -n

void	ft_echo(t_arg *lst)
{
	int		i;
	int		flag;
	int		option;
	t_arg	*tmp;

	i = 0;
	flag = 0;
	option = 0;
	tmp = lst;
//	if (tmp->is_command != 1)
	//	return ;
	tmp = tmp->next;
	while (tmp->is_option == 1)
	{
		if (flag == 1)
		{
			tmp->is_option = 0;
			tmp->is_argument = 1;
		}
		else
		{
			if (tmp->str[i] == '-')
				i++;
			while (tmp->str[i])
			{
				if (tmp->str[i] != 'n')
				{
					flag = 1;
					tmp->is_option = 0;
					tmp->is_argument = 1;
					break ;
				}
				i++;
			}
		}
		option = 1;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp->is_argument != 1)
		tmp = tmp->next;
	while (tmp->is_argument == 1)
	{
		i = -1;
		while (tmp->str[++i])
			write(1, &tmp->str[i], 1);
		tmp = tmp->next;
	}
	if (option == 0)
	{
		write(1, "\n", 1);
	}
}
