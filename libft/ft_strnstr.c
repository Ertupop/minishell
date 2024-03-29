/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:04:38 by jule-mer          #+#    #+#             */
/*   Updated: 2023/11/02 15:02:18 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystak, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystak);
	i = -1;
	while (haystak[++i] && i < len)
	{
		j = 0;
		while (j + i < len && haystak[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)&haystak[i]);
	}
	return (NULL);
}

int	ft_strstr(const char *haystak, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return (1);
	i = -1;
	while (haystak[++i])
	{
		j = 0;
		while (needle[j] && haystak[i + j] && haystak[i + j] == needle[j])
			j++;
		if (!needle[j])
			return (0);
	}
	return (1);
}
