/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:30:33 by firawar           #+#    #+#             */
/*   Updated: 2023/10/30 14:01:52 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_gc_strdup(const char *s1, t_list **collector)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = gc_alloc_char(collector, i);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

void	ft_free_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

char	*ft_strcat(char *s1, char *s2, t_list **collector)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	i = 0;
	while (s2[i])
		i++;
	str = gc_alloc_char(collector, len + i);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	len = -1;
	while (s2[++len])
		str[i + len] = s2[len];
	str[i + len] = '\0';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_the_result(int len, int min)
{
	len = len - min;
	if (len == 0)
		len ++;
	return (len);
}
