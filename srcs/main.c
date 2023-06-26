/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:44:58 by jule-mer          #+#    #+#             */
/*   Updated: 2023/06/12 18:05:07 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit;

int	ft_history(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] == ' ')
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
	t_sig	signal;

	use = NULL;
	parse.str = NULL;
	ft_set_sa(&signal, ft_sig_handler);
	while (1)
	{
		ft_init_parse(&parse);
		use = NULL;
		parse.str = readline("\033[0;36mminishell \033[0;31m➜ \033[0m ");
		if (parse.str == NULL)
			return ((void)printf("exit\n"));
		if (ft_history(parse.str))
		{
			add_history(parse.str);
			if (!ft_parse(&use, &parse, collector, env))
			{
				ft_exec(&use, *env, *collector);
			}
		}
	}
	gc_dell(*collector);
	rl_clear_history();
}

int	main(int ac, char **av, char **envp)
{
	t_list	*collector;
	t_env	*env;

	collector = NULL;
	env = ft_env(&collector, envp);
	ft_prompt(&collector, &env);
	(void)ac;
	(void)av;
	return (0);
}
