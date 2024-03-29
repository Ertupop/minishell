/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:44:58 by jule-mer          #+#    #+#             */
/*   Updated: 2023/11/01 18:01:51 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit;

void	ft_minishum(t_use **use)
{
	t_use	*tmp;
	t_use	*start;

	while (*use && (*use)->tokken == COMMAND && (*use)->tab == NULL)
		(*use) = (*use)->next;
	if (!(*use))
		return ;
	tmp = (*use)->next;
	start = *use;
	while (tmp)
	{
		if (tmp->tokken == COMMAND && !tmp->tab)
		{
			(*use)->next = tmp->next;
			if (!tmp->next)
				return ;
		}
		else
			*use = tmp;
		tmp = tmp->next;
	}
	*use = start;
}

int	ft_history(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (!str[i])
		return (0);
	return (1);
}

void	ft_init_parse(t_parse *parse)
{
	parse->i = 0;
	parse->j = 0;
	parse->quote = 0;
	parse->c = 0;
	if (parse->str)
		free(parse->str);
	parse->str = NULL;
}

void	ft_prompt(t_list **collector, t_env **env)
{
	t_use	*use;
	t_parse	parse;

	parse.str = NULL;
	while (1)
	{
		ft_init_parse(&parse);
		use = NULL;
		parse.str = readline("minishell ➜ ");
		if (parse.str == NULL)
		{
			gc_dell(*collector);
			return ((void)ft_printf("exit\n"));
		}
		if (ft_history(parse.str))
		{
			add_history(parse.str);
			if (!ft_parse(&use, &parse, collector, env))
			{
				ft_minishum(&use);
				ft_exec(&use, env, *collector);
			}
		}
	}
	ft_finish(collector);
}

int	main(int ac, char **av, char **envp)
{
	t_list	*collector;
	t_env	*env;
	t_sig	signal;
	t_env	*tmp;
	int		shlvl;

	collector = NULL;
	g_exit = 0;
	ft_set_sa(&signal, ft_sig_handler);
	env = ft_env(&collector, envp);
	tmp = ft_get_env_pos(env, "SHLVL");
	if (tmp)
	{
		shlvl = ft_atoi(tmp->str + 6);
		shlvl++;
		gc_dell_one(collector, tmp->str);
		tmp->str = NULL;
		tmp->str = gc_join_str(&collector, "SHLVL=", ft_itoa(shlvl));
	}
	ft_prompt(&collector, &env);
	(void)ac;
	(void)av;
	return (0);
}
