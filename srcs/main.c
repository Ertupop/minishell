/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:44:58 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/05 09:41:13 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_history(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == '|')
	{
		ft_putstr_fd("Starting by a pipe\n", 2);
		return (1);
	}
	if (str[i])
		return (0);
	return (1);
}

void	ft_prompt(void)
{
	t_list	*collector;
	t_arg	*args;
	char	*str;
	int		i;

	while (1)
	{
		i = 0;
		args = NULL;
		collector = NULL;
		str = readline("minishell> ");
		if (!ft_strcmp(str, "exit"))
			break ;
		if (!ft_history(str))
		{
			add_history(str);
			i = ft_parse(&args, str, &collector);
		}
		if (!i)
		{
		}
		if (DEBUG)
			ft_debug(&args);
		gc_dell(collector);
	}
	ft_echo(args);
	gc_dell(collector);
	rl_clear_history();
}

int	main(int ac, char **av, char **envp)
{
	t_env	*env;
	t_list	*garbage;
	t_env	*tmp;

	(void)ac;
	(void)av;
	garbage = NULL;
	env = ft_env(&garbage, envp);
	tmp = env;
	while (tmp->next)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
	tmp = env;
	printf("\nft_find env : %s\n", ft_find_env(tmp, "PWD"));
	ft_pwd(env);
	gc_dell(garbage);
	return (0);
}

