/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:16 by ertupop           #+#    #+#             */
/*   Updated: 2022/11/14 07:22:40 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_env *env, char **tab)
{
	int		i;
	t_env	*tmp;

	i = 1;
	while (tab[i])
	{
		tmp = env;
		while (tmp && ft_strcmp(tmp->str, tab[i]))
			tmp = tmp->next;
		if (ft_strcmp(tmp->str, tab[i]) == 0)
			ft_unset_remove(tmp, env);
		else if (ft_strcmp(tmp->str, tab[i]) != 0)
			return (1);
	}
	return (0);
}

void	ft_unset_remove(t_env	*tmp, t_env *env)
{
	t_env	*last;
	t_env	*next;

	next = tmp->next;
	last = env;
	while (!ft_strcmp(tmp->str, last->next->str))
		last = last->next;
	free(tmp->str);
	free(tmp);
	last->next = next;
}

int	main(int ac, char **av, char **env)
{
	t_env	*envp;
	t_list	*garbage;

	(void) ac;
	garbage = NULL;
	envp = ft_env(&garbage, env);
	ft_unset(envp, av);
	gc_dell(garbage);
	return (0);
}
*/
