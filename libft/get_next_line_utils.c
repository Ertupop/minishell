/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:16:35 by jule-mer          #+#    #+#             */
/*   Updated: 2022/05/16 10:45:04 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

char	*join(char *str, char *buf)
{
	int		i;
	int		j;
	char	*join;

	if (!buf)
		return (NULL);
	i = strlen_n(str) + strlen_n(buf);
	join = malloc(sizeof(char) * i + 2);
	if (!join)
		return (NULL);
	i = -1;
	while (str[++i])
		join[i] = str[i];
	j = -1;
	while (buf[++j] && buf[j - 1] != '\n')
		join[i + j] = buf[j];
	join[i + j] = '\0';
	free(str);
	return (join);
}

int	there_is_n(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
			return (1);
	}
	return (0);
}

int	strlen_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
