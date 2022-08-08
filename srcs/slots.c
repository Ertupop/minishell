/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:14:02 by firawar           #+#    #+#             */
/*   Updated: 2022/08/08 10:27:25 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_action_slot(char *str)
{
	int	slot;
	int	i;

	i = 1;
	slot = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], "<>|"))
		{
			if (str[i + 1] && str[i + 1] == str[i])
				i++;
			slot++;
			i++;
		}
		else
			i++;
	}
	return (slot);
}

int	ft_change_quote(char c, int *s_quote, int *d_quote, int type)
{
	if ((c != '\'' && c != '\"')
		|| ((c == '\'' && *d_quote == 1) || (c == '\"' && *s_quote == 1)))
		return (0);
	if (type == 0)
		{}
	return (0);
}

int	ft_str_slot(char *str)
{
	int		i;
	int		slot;
	int		s_quote;
	int		d_quote;
	char	c;

	i = 0;
	slot = 0;
	s_quote = -1;
	d_quote = -1;
	c = 1;
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], "<>| 0"))
			i++;
		if (str[i] && (str[i] == '\'' || str[i] == '\"')
			&& ft_change_quote(str[i], &s_quote, &d_quote, 0))
		{
			if (ft_change_quote(str[i], &s_quote, &d_quote, 1))
			{
				slot++;
			}
			i++;
		}
		i++;
	}
	(void)c;
	return (slot);
}

int	ft_number_of_slot(char *str, int i, int slot)
{
	slot += ft_str_slot(str);
	slot += ft_action_slot(str);
	/*while (str[i])
	{
	}*/
	(void)i;
	return (slot);
}
