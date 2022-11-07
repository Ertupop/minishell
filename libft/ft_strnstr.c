/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:04:38 by jule-mer          #+#    #+#             */
/*   Updated: 2022/09/26 15:44:01 by ertupop          ###   ########.fr       */
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
