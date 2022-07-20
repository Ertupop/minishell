/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:32:37 by jule-mer          #+#    #+#             */
/*   Updated: 2021/12/02 14:17:53 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(long int nbr)
{
	int			i;

	i = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nbr;

	nbr = n;
	len = ft_lennbr(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
