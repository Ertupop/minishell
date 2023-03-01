/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:16:30 by jule-mer          #+#    #+#             */
/*   Updated: 2022/05/16 10:45:13 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_str(char *str)
{
	if (!str)
		return (NULL);
	free(str);
	str = NULL;
	return (str);
}

char	*clear_buf(char *str, char *buf)
{
	int	i;
	int	j;

	i = strlen_n(buf);
	if (buf[i] == '\n')
		i++;
	j = -1;
	while (buf[++j] && buf[i])
		buf[j] = buf[i++];
	while (buf[j])
		buf[j++] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*str;
	static char	buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, buf, 0) == -1)
		return (NULL);
	str = fdup("");
	str = join(str, buf);
	i = 1;
	while (i > 0 && !there_is_n(buf))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (free_str(str));
		else if (i)
		{
			buf[i] = '\0';
			str = join(str, buf);
		}
		else if (i == 0 && buf[0] != '\0')
			return (clear_buf(str, buf));
		else
			return (free_str(str));
	}
	return (clear_buf(str, buf));
}
