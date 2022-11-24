/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:36:35 by ertupop           #+#    #+#             */
/*   Updated: 2022/11/23 10:44:01 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_export(char **tab, t_env *env, t_list *garbage)
{
	int		i;
	t_env	*tmp;

	i = 0;
	if (ft_size_tab(tab) == 1)
	{
		ft_print_env(env);
		return (0);
	}
	while (tab[++i])
	{
		if (ft_check_export(tab[i]) == 0)
		{
			tmp = ft_get_env_pos(env, tab[i]);
			if (tmp == NULL)
				ft_add_export(tab[i], env, garbage);
			else
			{
				//if ()
				//	ft_replace_export(tab[i], tmp, garbage);
				//else
					ft_join_export(tab[i], tmp, garbage);
			}
		}
		else
			return (1);
	}
	return (0);
}

void	ft_add_export(char *str, t_env *env, t_list *garbage)
{
	t_env	*tmp;

	tmp = gc_alloc_env(&garbage);
	tmp->str = gc_strdup(&garbage, str);
	ft_lstadd_back_env(&env, tmp);
}

void	ft_join_export(char *str, t_env *tmp, t_list *garbage)
{
	char	*tmpo;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		i++;
	tmpo = gc_strdup(&garbage, tmp->str);
	gc_dell_one(garbage, &tmp->str);
	tmp->str = gc_join_str(&garbage, tmpo, str + i);
}

int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_check_export(char *str)
{
	int	i2;

	if ((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A'
			|| str[0] > 'Z') && str[0] != '_')
	{
		write(2, "export: `", 9);
		ft_putstr_fd(str, 2);
		write(2, "': not a valid identifier\n", 26);
		return (1);
	}
	i2 = 1;
	while (str[i2] && str[i2] != '=')
	{
		if ((str[i2] < 'a' || str[i2] > 'z') && (str[i2] < 'A'
				|| str[i2] > 'Z') && str[i2] != '_' && (str[i2] < '0'
				|| str[i2] > '9') && (str[i2] != '+' && str[i2 + 1] != '='))
		{
			write(2, "export: `", 9);
			ft_putstr_fd(str, 2);
			write(2, "': not a valid identifier\n", 26);
			return (1);
		}
		i2++;
	}
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	t_env	*env;
// 	t_list	*garbage;

// 	(void) ac;
// 	env = NULL;
// 	garbage = NULL;
// 	env = ft_env(&garbage, envp);
// 	ft_export(av, env, garbage);
// 	ft_putstr_fd("\n\n", 1);
// 	ft_print_env(env);
// 	gc_dell(garbage);
// 	return (0);
// }
