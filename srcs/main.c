/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:44:58 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/28 13:26:17 by firawar          ###   ########.fr       */
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

	args = NULL;
	collector = NULL;
	while (1)
	{
		str = readline("minishell> ");
		if (!ft_strcmp(str, "exit"))
			break ;
		if (!ft_history(str))
		{
			add_history(str);
			ft_parse(&args, str, &collector);
		}
		if (DEBUG)
			ft_debug(&args);
	}
	gc_dell(collector);
	rl_clear_history();
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	ft_prompt();
	return (0);
}