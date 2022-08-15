/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:57:23 by ertupop           #+#    #+#             */
/*   Updated: 2022/08/05 07:41:24 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/minishell.h"

char	*gc_strdup(t_list **collector, const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = gc_alloc_char(collector, i);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

t_env	*gc_alloc_env(t_list **collector)
{
	t_env	*env;
	t_list	*new;

	env = malloc(sizeof(t_env) * 1);
	if (!env)
	{
		gc_dell(*collector);
		exit(1);
	}
	new = ft_lstnew(env);
	ft_lstadd_back(collector, new);
	return (env);
}

t_env	*ft_env(t_list **collector, char **envp)
{
	t_env	*env;
	t_env	*tmpp;
	int		i;

	env = NULL;
	i = -1;
	while (envp[++i])
	{
		tmpp = gc_alloc_env(collector);
		tmpp->str = gc_strdup(collector, envp[i]);
		tmpp->next = NULL;
		ft_lstadd_back_env(&env, tmpp);
	}
	return (env);
}

void	ft_lstadd_back_env(t_env **alst, t_env *new)
{
	t_env	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast_env(*alst);
	tmp->next = new;
}

t_env	*ft_lstlast_env(t_env *lst)
{
	t_env	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}
