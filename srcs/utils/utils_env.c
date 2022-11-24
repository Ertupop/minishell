/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:09:27 by ertupop           #+#    #+#             */
/*   Updated: 2022/11/21 08:50:04 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*gc_join_str(t_list **coll, const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		i2;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = gc_alloc_char(coll, i);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i2 = -1;
	while (s2[++i2])
		str[i + i2] = s2[i2];
	str[i + i2] = '\0';
	return (str);
}

