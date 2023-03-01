/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:09:16 by jule-mer          #+#    #+#             */
/*   Updated: 2023/02/18 16:06:08 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_infile(t_use **use, t_list **collector, int infile)
{
	t_use	*new;

	new = gc_alloc_use(collector);
	new->tokken = infile;
	new->tab = NULL;
	new->fd = infile;
	ft_lstadd_back_use(use, new);
}

