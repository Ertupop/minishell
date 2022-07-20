/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:03:09 by jule-mer          #+#    #+#             */
/*   Updated: 2022/05/21 14:53:49 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr_unsigned(unsigned int nbr)
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

char	*ft_itoa_unsigned(unsigned int n)
{
	char		*str;
	int			len;

	len = ft_lennbr_unsigned(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
