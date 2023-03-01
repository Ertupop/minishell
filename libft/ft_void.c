/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:34:20 by jule-mer          #+#    #+#             */
/*   Updated: 2022/05/21 14:54:35 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_void_len(uintptr_t n)
{
	int					len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_void_hexa(uintptr_t n)
{
	if (n >= 16)
	{
		ft_void_hexa(n / 16);
		ft_void_hexa(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_print_void(unsigned long long n)
{
	int	len;

	len = 0;
	len += ft_print_str("0x");
	if (n == 0)
		len += ft_print_char('0');
	else
	{
		ft_void_hexa(n);
		len += ft_void_len(n);
	}
	return (len);
}
