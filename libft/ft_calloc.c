/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:40 by jule-mer          #+#    #+#             */
/*   Updated: 2021/11/26 12:51:48 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < count * size)
		res[i] = 0;
	return (res);
}
