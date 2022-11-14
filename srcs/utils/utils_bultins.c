/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bultins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:28:09 by ertupop           #+#    #+#             */
/*   Updated: 2022/11/09 13:08:21 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_find_env(t_env *env, char *find)
{
	int		i2;
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
	{
		i2 = 0;
		while (tmp->str[i2] && tmp->str[i2] == find[i2] && find[i2])
			i2++;
		if (find[i2] == '\0')
			return (tmp->str);
		else
			tmp = tmp->next;
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = -1;
	while (s1[++i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	return (0);
}
