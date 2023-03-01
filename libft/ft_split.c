/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:08:48 by jule-mer          #+#    #+#             */
/*   Updated: 2021/12/02 14:17:22 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_error(char **str)
{
	while (*str)
		free(*str++);
	free(str);
	return (NULL);
}

static void	ft_theword(char **s1, int *word, char c)
{
	int	i;

	*s1 += *word;
	*word = 0;
	while (**s1 && **s1 == c)
		(*s1)++;
	i = -1;
	while ((*s1)[++i])
	{
		if ((*s1)[i] == c)
			return ;
		(*word)++;
	}
}

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*s1;
	int		i;
	int		len;
	int		word;

	len = ft_len(s, c);
	s1 = (char *)s;
	word = 0;
	str = malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		ft_theword(&s1, &word, c);
		str[i] = malloc(sizeof(char) * (word + 1));
		if (!str)
			return (ft_error(str));
		ft_strlcpy(str[i], s1, word + 1);
	}
	str[i] = NULL;
	return (str);
}
