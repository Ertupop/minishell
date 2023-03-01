/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:24:44 by jule-mer          #+#    #+#             */
/*   Updated: 2021/11/26 15:26:09 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	src_size = 0;
	while (src[src_size])
		src_size++;
	if (size == 0)
		return (src_size);
	i = 0;
	while (dst[i] && i < size)
		i++;
	dst_size = i;
	while (src[i - dst_size] && i < size - 1)
	{
		dst[i] = src[i - dst_size];
		i++;
	}
	if (dst_size < size)
		dst[i] = '\0';
	return (dst_size + src_size);
}
