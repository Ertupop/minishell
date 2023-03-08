/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:09:16 by jule-mer          #+#    #+#             */
/*   Updated: 2023/03/08 10:39:40 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_infile(t_use **use, t_list **collector, int infile)
{
	t_use	*new;

	new = gc_alloc_use(collector);
	new->tokken = INFILE;
	new->tab = NULL;
	new->fd = infile;
	ft_lstadd_back_use(use, new);
}

