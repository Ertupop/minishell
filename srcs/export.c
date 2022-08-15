/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:36:35 by ertupop           #+#    #+#             */
/*   Updated: 2022/08/12 09:35:46 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_export(char **tab, t_env *env, t_list *garbage)
{
	t_env	*tmp;
	int i;

	i = 0;
	while(tab[++i])
	{
		tmp = gc_alloc_env(&garbage);
		tmp->str = ft_strdup(tab[i]);
	}
	return (0);
}
