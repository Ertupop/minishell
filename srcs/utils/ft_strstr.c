/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:49:37 by rstrub            #+#    #+#             */
/*   Updated: 2021/08/09 17:46:59 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char	*str, char	*to_find)
{
	int	index1;
	int	index2;

	index1 = 0;
	index2 = 0;
	if (to_find[index2] == '\0')
		return (str);
	while (str[index1] && to_find[index2])
	{
		if (str[index1] == to_find[index2])
		{
			while ((str[index1 + index2] && to_find[index2])
				&& (str[index1 + index2] == to_find[index2]))
				index2++;
		}
		if (to_find[index2] == '\0')
			return (&str[index1]);
		else
		{
			index1++;
			index2 = 0;
		}
	}
	return (0);
}
