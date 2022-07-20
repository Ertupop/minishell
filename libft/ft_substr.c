/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:32:02 by jule-mer          #+#    #+#             */
/*   Updated: 2021/12/01 14:04:19 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (j < start)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		str[i] = s[start + i];
	}
	str[i] = '\0';
	return (str);
}
