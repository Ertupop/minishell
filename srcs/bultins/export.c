/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:36:35 by ertupop           #+#    #+#             */
/*   Updated: 2023/01/23 09:39:25 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_export(char **tab, t_env *env, t_list *garbage)
{
	int		i;
	t_env	*tmp;

	tmp = NULL;
	i = 0;
	if (ft_size_tab(tab) == 1)
	{
		ft_print_env(env);
		return (0);
	}
	while (tab[++i])
	{
		if (ft_check_export(tab[i]) == 0)
			ft_export2(tab[i], tmp, garbage, env);
		else
			return (1);
	}
	return (0);
}

void	ft_export2(char *tab, t_env *tmp, t_list *garbage, t_env *env)
{
	if (ft_find_equal(tab) != 0)
		return ;
	tmp = ft_get_env_pos_export(env, tab);
	if (tmp == NULL)
	{
		tmp = ft_add_export(tab, env, garbage);
	}
	else
	{
		if (ft_find_plus(tab) == 1)
			ft_join_export(tab, tmp, garbage);
		else
			tmp->str = gc_strdup(&garbage, tab);
	}
}

int	ft_find_plus(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '+' && str[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

t_env	*ft_add_export(char *str, t_env *env, t_list *garbage)
{
	t_env	*tmp;

	tmp = gc_alloc_env(&garbage);
	tmp->str = gc_strdup(&garbage, str);
	ft_lstadd_back_env(&env, tmp);
	return (tmp);
}
