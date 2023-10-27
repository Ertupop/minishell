/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:57:17 by jule-mer          #+#    #+#             */
/*   Updated: 2022/05/21 14:54:18 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", ft_strlen("(null)"));
		return (ft_strlen("(null)"));
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_types(va_list args, char type)
{
	int	len;

	len = 0;
	if (type == '%')
		len += ft_print_char('%');
	else if (type == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		len += ft_print_int(va_arg(args, int));
	else if (type == 'u')
		len += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (type == 'x')
		len += ft_print_hexa_min(va_arg(args, unsigned int));
	else if (type == 'X')
		len += ft_print_hexa_maj(va_arg(args, unsigned int));
	else if (type == 'p')
		len += ft_print_void(va_arg(args, unsigned long long));
	return (len);
}

int	ft_printf(const char *print, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, print);
	i = 0;
	len = 0;
	while (print[i])
	{
		if (print[i] == '%')
		{
			len += ft_types(ap, print[i + 1]);
			i++;
		}
		else
			len += ft_print_char(print[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
