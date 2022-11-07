/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 06:50:00 by ertupop           #+#    #+#             */
/*   Updated: 2022/09/28 10:28:51 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*void	ft_cd(t_arg	*args, t_env *env)
{
	int		argn;
	t_arg	*tmp;
	char	*path;

	tmp = args;
	argn = 0;
	if (tmp->is_command != 1)
		return ;
	tmp = tmp->next;
	while (tmp->is_argument != 1)
	{
		tmp = tmp->next;
		argn++;
	}
	if (argn > 1)
	{
		ft_putstr_fd("cd : too many arguments\n", 2);
		return ;
	}
	tmp = args->next;
	if (argn == 0)
	{
		path = ft_find_env(env, "HOME=");

	}

}*/

char	*ft_find_env(t_env *env, char *find)
{
	int		i2;
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
	{
		i2 = 0;
		while (tmp->str[i2] && tmp->str[i2] == find[i2] && find[i2])
			i2++;
		if (find[i2] == '\0')
			return (tmp->str);
		else
			tmp = tmp->next;
	}
	return (NULL);
}
