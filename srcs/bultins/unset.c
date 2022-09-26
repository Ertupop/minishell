/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:16 by ertupop           #+#    #+#             */
/*   Updated: 2022/08/31 12:03:12 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_unset(t_env env, char **str)
{
	int		i;
	char	*strr;

	i = 1;
	while (str[i])
	{
		strr = ft_find_env(env, str[i]);
		if (strr == NULL)
			return (0);
		else
		{

		}
		i++;
	}

}
