/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firawar <firawar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:44:58 by jule-mer          #+#    #+#             */
/*   Updated: 2022/09/13 18:25:07 by firawar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	ft_prompt(void)
{
	t_list	*collector;
	t_arg	*args;
	t_use	*use;
	t_parse	parse;
	char	*str;

	while (1)
	{
		use = NULL;
		args = NULL;
		collector = NULL;
		str = readline("\033[0;36mminishell \033[0;31m➜\033[0m ");
		if (!ft_strcmp(str, "exit"))
			break ;

		//verifie si il peut ajouter a l'historique, si oui lance la suite
		if (ft_history(str))
		{
			add_history(str);
			if (!ft_parse(&args, str, &collector, parse))
				ft_fill_args(&use, &args, &collector);
		}

		//DEBUG
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
