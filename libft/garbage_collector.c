/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:53:11 by jule-mer          #+#    #+#             */
/*   Updated: 2022/07/25 03:16:10 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_dell(t_list *collector)
{
	ft_lstclear(&collector, free);
}

int	gc_dell_one(t_list *collector, void *addr)
{
	t_list	*prev;
	t_list	*next;
	t_list	*tmp;

	prev = NULL;
	tmp = collector;
	while (tmp && tmp->content != addr)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	ft_lstdelone(tmp, free);
	next = tmp->next;
	if (prev)
		prev->next = next;
	return (0);
}

int	*gc_alloc_int(t_list **collector, int size)
{
	int		*str;
	t_list	*new;

	str = malloc(sizeof(int) * size + 1);
	if (!str)
	{
		gc_dell(*collector);
		exit(1);
	}
	new = ft_lstnew(str);
	ft_lstadd_back(collector, new);
	return (str);
}

char	*gc_alloc_char(t_list **collector, int size)
{
	char	*str;
	t_list	*new;

	str = malloc(sizeof(char) * size + 1);
	if (!str)
	{
		gc_dell(*collector);
		exit(1);
	}
	str[size] = '\0';
	new = ft_lstnew(str);
	ft_lstadd_back(collector, new);
	return (str);
}
