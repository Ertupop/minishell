/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:55:16 by firawar           #+#    #+#             */
/*   Updated: 2022/08/09 12:32:20 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_end_init(t_arg **new)
{
	(*new)->is_command = 0;
	(*new)->is_action_tokken = 0;
	(*new)->is_argument = 0;
	(*new)->is_file = 0;
	(*new)->next = NULL;
}

void	ft_init_quote(t_list **collector, t_arg **new, char *str, int j)
{
	int	i;
	int	start;

	i = j;
	i++;
	while (str[i] && str[i] != str[j])
		i++;
	(*new)->str = gc_alloc_char(collector, i - j);
	start = -1;
	while (++j < i)
		(*new)->str[++start] = str[j];
	(*new)->str[++start] = '\0';
	ft_end_init(new);
}

void	ft_init_sep(t_list **collector, t_arg **new, char *str, int i)
{
	int	j;
	int	start;

	j = i;
	while (str[j] && ft_is_sep(str[j], "<>|"))
	{
		j++;
		if (j > 1 && str[j] != str[j - 1])
			break ;
	}
	(*new)->str = gc_alloc_char(collector, j - i);
	i--;
	start = -1;
	while (++i < j)
		(*new)->str[++start] = str[i];
	(*new)->str[++start] = '\0';
	ft_end_init(new);
}

void	ft_init_str(t_list **collector, t_arg **new, char *str, int i)
{
	int	j;
	int	start;

	j = i;
	while (str[j] && !ft_is_sep(str[j], " <>|"))
		j++;
	(*new)->str = gc_alloc_char(collector, j - i);
	i--;
	start = -1;
	while (++i < j)
		(*new)->str[++start] = str[i];
	(*new)->str[++start] = '\0';
	ft_end_init(new);
}
