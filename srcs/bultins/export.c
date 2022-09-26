/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:36:35 by ertupop           #+#    #+#             */
/*   Updated: 2022/08/17 12:14:05 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_export(char **tab, t_env *env, t_list *garbage)
{
	int	i;
	int	arg;

	arg = ft_size_tab(tab);
	i = 0;
	(void) garbage;
	if (arg == 1)
		return (ft_print_export(env));
	else
	{
		while (tab[++i])
		{
			if (tab[i][0] == '=')
			{
				ft_printf("export: `%s' : not a valid identifier\n", tab[i]);
			}
		}
	}
	return (0);
}


int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_print_export(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
	{
		ft_printf("declare -x ");
		ft_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
	return (0);
}
