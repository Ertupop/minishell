/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:29:45 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/16 22:03:03 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parse_str(t_list **collector, t_arg **new, char *str, t_parse *parse)
{
	*new = gc_create_slot(collector);
	(*new)->str = malloc(sizeof(char) * parse->j
			- parse->i - parse->quote + 1);
	parse->quote = -1;
	while (parse->i < parse->j)
	{
		if (str[parse->i] == '\'' || str[parse->i] == '\"')
		{
			if (parse->c == '\0')
				parse->c = str[parse->i];
			else
				parse->c = '\0';
			parse->i++;
		}
		else
			(*new)->str[++parse->quote] = str[parse->i++];
	}
	(*new)->str[++parse->quote] = '\0';
	ft_end_init(new);
}

void	ft_skip_char(char *str, t_parse *parse)
{
	while (str[parse->j] && ((ft_is_sep(str[parse->j], " <>|")
				&& parse->c != '\0')
			|| (!ft_is_sep(str[parse->j], " <>|"))))
	{
		if (str[parse->j] == '\'' || str[parse->j] == '\"')
		{
			if (str[parse->j] == parse->c || parse->c == '\0')
			{
				if (str[parse->j] == parse->c)
					parse->c = '\0';
				else
					parse->c = str[parse->j];
				parse->quote++;
			}
			parse->j++;
		}
		else
			parse->j++;
	}
}

void	ft_parse_sep(t_list **collector, t_arg **new, char *str, t_parse *parse)
{
	*new = gc_create_slot(collector);
	ft_init_sep(collector, new, str, parse->i);
	if (str[parse->i + 1] == str[parse->i])
		parse->i++;
	parse->i++;
}

int	ft_parse_2(char *str, t_parse *parse)
{
	if (ft_check(str))
		return (1);
	parse->i = 0;
	parse->c = '\0';
	return (0);
}

int	ft_parse(t_arg **args, char *str, t_list **collector, t_parse parse)
{
	t_arg	*new;

	if (ft_parse_2(str, &parse))
		return (1);
	new = NULL;
	while (str[parse.i])
	{
		while (str[parse.i] && str[parse.i] == ' ')
			parse.i++;
		if (ft_is_sep(str[parse.i], "<>|"))
		{
			ft_parse_sep(collector, &new, str, &parse);
			ft_arg_add_back(args, new);
		}
		parse.j = parse.i;
		parse.quote = 0;
		ft_skip_char(str, &parse);
		if (parse.j - parse.quote > parse.i)
		{
			ft_parse_str(collector, &new, str, &parse);
			ft_arg_add_back(args, new);
		}
		parse.i = parse.j;
	}
	return (0);
}
