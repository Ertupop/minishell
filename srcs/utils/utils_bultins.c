/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bultins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:28:09 by ertupop           #+#    #+#             */
/*   Updated: 2023/10/30 15:48:27 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_find_env(t_env *env, char *find)
{
	int		i2;
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		i2 = 0;
		while (tmp->str[i2] && tmp->str[i2] == find[i2] && find[i2])
			i2++;
		if (find[i2] == '\0' && tmp->str[i2 - 1] == '=')
			return (tmp->str);
		else
			tmp = tmp->next;
	}
	return (NULL);
}

void	ft_for_dollar(char **str, t_easy *start)
{
	int	i;

	i = 0;
	while (start && start->d_quote == 0 && ft_isalnum(start->c))
	{
		(*str)[i++] = start->c;
		start = start->next;
	}
}

void	ft_help_line(int *i, char *c, char d, int ca)
{
	if (ca == 1)
	{
		*i = 1;
		*c = d;
	}
	else if (ca == 0)
	{
		*i = 0;
		*c = ' ';
	}
	else
	{
		*i = 2;
		*c = ' ';
	}
}

int	ft_prompt_check_error(void)
{
	ft_putstr_fd("minishell : : no such file or directory\n", 2);
	return (1);
}

void	ft_first(t_easy **easy, t_list **collector, t_env **env)
{
	ft_good_place(easy, collector);
	ft_good_quote(easy);
	ft_expand(easy, collector, env);
}
