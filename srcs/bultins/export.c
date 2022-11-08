/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:36:35 by ertupop           #+#    #+#             */
/*   Updated: 2022/11/08 07:18:17 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*int	ft_export(char **tab, t_env *env, t_list *garbage)
{
	int	i;
	t_env	*tmp;

	i = 1;
	if (ft_size_tab(tab) == 1)
	{
		ft_print_export(env);
		return (0);
	}
	else
	{
		while (tab[i])
		{
			if (ft_check_export(tab[i]) = 0)
			{
				if (ft_find_env(env, tab[i]) != NULL)
				{
					tmp = ft_get_env_pos(env, tab[i]);
					if (ft_strnstr(tab[i], "+=") != NULL)
					{

					}
					else
					{
						gc_
						tmp->str = ft_strdup(tab[i]);
					}
				}
			}
			i++;
		}
	}
	return (0);
}

int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_print_export(t_env *env)
{
	int		i;
	char	**envi;

	envi = ft_make_tab(env);
	ft_sort_env(envi);
	i = 0;
	while (envi[i])
	{
		ft_putstr_fd(envi[i], 1);
		write(1, "\n", 1);
		i++;
	}
	ft_free_make_tab(envi);
	return (0);
}*/

char	**ft_make_tab(t_env *env)
{
	int		size;
	char	**tab;
	t_env	*tmp;

	tmp = env;
	size = ft_env_size(env);
	tab = malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)

		return (NULL);
	tab[size] = NULL;
	size = 0;
	while (tmp->next)
	{
		tab[size] = ft_strdup(tmp->str);
		if (tab[size] == NULL)
		{
			ft_free_make_tab(tab);
			return (NULL);
		}
		tmp = tmp->next;
		size++;
	}
	return (tab);
}

void	ft_free_make_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
/*
void	ft_sort_env(char **envi)
{
	char	*tmp;
	int		i;
	int		i2;

	i2 = 0;
	while (envi[i2])
	{
		tmp = strdup(envi[i2]);
		i = i2;
		while (envi[i])
		{
			if (strcmp(tmp, envi[i]) > 0)
			{
				free(envi[i2]);
				envi[i2] = ft_strdup(envi[i]);
				free(envi[i]);
				envi[i] = strdup(tmp);
				free(tmp);
				tmp = strdup(envi[i2]);
			}
			i++;
		}
		i2++;
	}
	free(tmp);
}

int	ft_check_export(char *str)
{
	int	i2;

	if ((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A'
			|| str[0] > 'Z') && str[0] != '_')
	{
		write(2, "export: `", 9);
		ft_putstr_fd(str, 2);
		write(2, "': not a valid identifier\n", 26);
		return (1);
	}
	i2 = 1;
	while (str[i2] && str[i2] != '=')
	{
		if ((str[i2] < 'a' || str[i2] > 'z') && (str[i2] < 'A'
				|| str[i2] > 'Z') && str[i2] != '_' && (str[i2] < '0'
				|| str[i2] > '9'))
		{
			write(2, "export: `", 9);
			ft_putstr_fd(str, 2);
			write(2, "': not a valid identifier\n", 26);
			return (1);
		}
		i2++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	(void) ac;
	while (av[i])
	{
		printf("%s\n", av[i]);
		printf("%d\n", ft_check_export(av[i]));
		i++;
	}
	return (0);
}
*/
