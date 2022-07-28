/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:29:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/28 19:29:46 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_mv_list(t_arg **args, t_list **collector)
{
	(void)args;
	(void)collector;
}

void	ft_fill(t_arg **args, char *str, t_list **collector)
{
	int		pos;
	t_arg	*tmp;

	pos = 0;
	tmp = *args;
	while (tmp)
	{
		while (str[pos] && str[pos] == ' ')
			pos++;
		ft_fill_arg(tmp, str, &pos, collector);
		while (str[pos] && str[pos] == ' ')
			pos++;
		tmp = tmp->next;
	}
}

int	ft_create_parse(t_arg **args, char *str, t_list **collector)
{
	int		i;
	int		slots;
	t_arg	*new;

	i = -1;
	slots = 0;
	slots = ft_number_of_slot(str, i, slots);
	while (++i < slots)
	{
		new = gc_create_slot(collector);
		if (!new)
		{
			ft_putstr_fd("Error in slot creation", 2);
			return (1);
		}
		ft_arg_add_back(args, new);
	}
	return (0);
}

int	ft_parse(t_arg **args, char *str, t_list **collector)
{
	if (ft_check_str(str))
		return (1);
	ft_create_parse(args, str, collector);
	ft_fill(args, str, collector);
	//ft_mv_list(args, collector);
	return (0);
}
