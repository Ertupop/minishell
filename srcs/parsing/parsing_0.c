/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:10:17 by jule-mer          #+#    #+#             */
/*   Updated: 2023/06/12 17:11:19 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_start_easy(t_easy **easy, t_list **collector, t_parse *parse)
{
	t_easy	*new;

	new = gc_create_easy(collector);
	ft_init_easy(new);
	new->c = parse->str[parse->i++];
	if (new->c == ' ')
		new->space = 1;
	ft_check_quote(&new);
	ft_lstadd_back_easy(easy, new);
}

int	ft_parse(t_use **use, t_parse *parse, t_list **collector, t_env **env)
{
	t_easy	*easy;
	t_easy	*dell;

	easy = NULL;
	if (ft_check_parse(parse->str))
		return (1);
	while (parse->str[parse->i])
		ft_start_easy(&easy, collector, parse);
	ft_good_place(&easy, collector);
	ft_good_quote(&easy);
	ft_expand(&easy, collector, env);
	ft_skip_space(&easy, collector);
	gc_dell_one(*collector, &parse->str);
	ft_create_bridge(easy, use, collector);
	while (easy)
	{
		dell = easy;
		easy = easy->next;
		gc_dell_one(*collector, &dell);
	}
	return (0);
}
