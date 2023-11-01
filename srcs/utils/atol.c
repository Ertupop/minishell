/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:31:00 by ertupop           #+#    #+#             */
/*   Updated: 2023/10/31 14:52:27 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}

void	ft_p2(t_easy **easy, t_list **collector, t_parse *parse)
{
	ft_dell_dollar(easy, collector);
	ft_skip_space(easy, collector);
	gc_dell_one(*collector, &parse->str);
}

void	ft_p(t_easy **easy, t_list **collector, t_env **env)
{
	ft_good_place(easy, collector);
	ft_good_quote(easy);
	ft_expand(easy, collector, env);
}

void	ft_zos(t_easy *tmp, int *i, char *c, int *min)
{
	if ((tmp->c == '\'' || tmp->c == '\"') && *i == 0)
	{
		ft_help_line(i, c, tmp->c, 1);
		(*min)++;
	}
	else if (tmp->c == *c && *i == 1)
	{
		ft_help_line(i, c, tmp->c, 0);
		(*min)++;
	}
}
