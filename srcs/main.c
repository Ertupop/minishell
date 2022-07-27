/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:44:58 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/27 12:02:50 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_double_pipe(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i + 1] && str[i] == '|' && str[i + 1] == '|')
			return (1);
	}
	return (0);
}

int	ft_history(char *str)
{
	int	i;

	if (str[0] == '|')
	{
		ft_putstr_fd("Starting by a pipe\n", 2);
		return (1);
	}
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		return (0);
	return (1);
}

void	ft_prompt(t_list **collector)
{
	t_arg	*args;
	char	*str;

	args = NULL;
	while (1)
	{
		str = readline("minishell> ");
		if (!ft_strcmp(str, "exit"))
			break ;
		if (!ft_history(str))
		{
			add_history(str);
			if (!ft_double_pipe(str))
				args = ft_parse(collector, &args, str);
		}
	}
	rl_clear_history();
}

int	main(int ac, char **av, char **envp)
{
	t_list	*collector;

	(void)ac;
	(void)av;
	(void)envp;
	collector = NULL;
	ft_prompt(&collector);
	return (0);
}
