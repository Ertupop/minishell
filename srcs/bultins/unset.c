/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:16 by ertupop           #+#    #+#             */
/*   Updated: 2022/11/21 06:20:24 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_list *collect, t_env *env, char **tab)
{
	int		i;
	t_env	*tmp;

	i = 1;
	while (tab[i])
	{
		tmp = env;
		while (tmp->next && ft_unset_cmp(tmp->str, tab[i]) != 0)
			tmp = tmp->next;
		if (ft_unset_cmp(tmp->str, tab[i]) == 0 && tmp != NULL)
			ft_unset_remove(collect, tmp, env);
		i++;
	}
	return (0);
}

int	ft_unset_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] != '=')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s2[i] != '\0' || (s1[i] != '\0' && s1[i] != '='))
		return (1);
	return (0);
}

void	ft_unset_remove(t_list *collect, t_env	*tmp, t_env *env)
{
	t_env	*last;
	t_env	*next;

	next = tmp->next;
	last = env;
	while (last->next && tmp->str && ft_strcmp(tmp->str, last->next->str))
		last = last->next;
	gc_dell_one(collect, &tmp->str);
	gc_dell_one(collect, &tmp);
	last->next = next;
}

int	main(int ac, char **av, char **env)
{
	t_env	*envp;
	t_list	*garbage;

	(void) ac;
	(void) av;
	envp = NULL;
	garbage = NULL;
	envp = ft_env(&garbage, env);
	ft_unset(garbage, envp, av);
	ft_print_env(envp);
	gc_dell(garbage);
	(void) envp;
	return (0);
}
