/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:44:58 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/05 13:11:16 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		add_history(str);
		i = ft_parse(&args, str, &collector);
		if (!i)
		{
		}
		if (DEBUG)
			ft_debug(&args);
		gc_dell(collector);
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
