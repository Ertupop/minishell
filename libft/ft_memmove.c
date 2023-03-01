/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:58:42 by jule-mer          #+#    #+#             */
/*   Updated: 2021/11/23 18:19:40 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*tdest;

	str = (unsigned char *)src;
	tdest = (unsigned char *)dest;
	if (str < tdest)
	{
		while (len--)
			tdest[len] = str[len];
	}
	else
	{
		i = -1;
		while (++i < len)
			tdest[i] = str[i];
	}
	return (dest);
}
