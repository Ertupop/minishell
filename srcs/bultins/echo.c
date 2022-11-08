/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 06:27:10 by ertupop           #+#    #+#             */
/*   Updated: 2022/11/08 06:39:52 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

void	ft_echo(char **tab)
{
	int		n;
	int		i;
	int		i2;

	i = 1;
	n = 0;
	while (tab[i])
	{
		if (tab[i][0] == '-')
		{
			i2 = 1;
			while (tab[i][i2] == 'n')
			{
				i2++;
			}
			if (tab[i][i2] == '\0')
				n = 1;
			else
				break ;
		}
		else
			break ;
		i++;
	}
	ft_echo2(tab, i, n);
}

void	ft_echo2(char **tab, int i, int n)
{
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		if (tab[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
	if (n != 1)
		write(1, "\n", 1);
}
