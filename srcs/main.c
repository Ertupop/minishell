/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:44:58 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/25 21:13:35 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;
	char	**tab;
	int		i;

	(void)ac;
	(void)av;
	(void)envp;
	tab = NULL;
	while (1)
	{
		str = readline("\nMinishell> ");
		if (ft_strcmp(str, ""))
		{
			tab = ft_split(str, ' ');
			if (!tab)
				return (1);
			printf("\nyou say \"%s\"\n", str);
			i = 0;
			while (tab[i])
				i++;
			printf("\nI cut in %d part :\n", i);
			i = -1;
			while (tab[++i])
				printf("\t%d > \"%s\"\n", i + 1, tab[i]);
			add_history(str);
		}
	}
	rl_clear_history();
	return (0);
}
