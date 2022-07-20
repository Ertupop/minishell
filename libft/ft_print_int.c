/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:40:06 by jule-mer          #+#    #+#             */
/*   Updated: 2022/05/21 14:54:27 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int nb)
{
	int			len;
	char		*str;

	str = ft_itoa(nb);
	len = ft_print_str(str);
	free(str);
	return (len);
}

int	ft_print_unsigned_int(unsigned int nb)
{
	int			len;
	char		*str;

	str = ft_itoa_unsigned(nb);
	len = ft_print_str(str);
	free(str);
	return (len);
}

int	ft_print_hexa_maj(unsigned int nb)
{
	int	len;

	if (nb == 0)
		return (ft_print_char('0'));
	if (nb >= 16)
	{
		ft_print_hexa_maj(nb / 16);
		ft_print_hexa_maj(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_print_char(nb + '0');
		else
			ft_print_char(nb - 10 + 'A');
	}
	len = 0;
	while (nb > 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

int	ft_print_hexa_min(unsigned int nb)
{
	int	len;

	if (nb == 0)
		return (ft_print_char('0'));
	if (nb >= 16)
	{
		ft_print_hexa_min(nb / 16);
		ft_print_hexa_min(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_print_char(nb + '0');
		else
			ft_print_char(nb - 10 + 'a');
	}
	len = 0;
	while (nb > 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}
