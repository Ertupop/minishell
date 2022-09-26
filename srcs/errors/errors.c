/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:06:30 by jule-mer          #+#    #+#             */
/*   Updated: 2022/08/16 21:50:48 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_error(int i, char c)
{
	if (i == 0 && c == '\'')
		ft_putstr_fd("minishell: syntax error missing a simple quote\n", 2);
	else if (i == 0 && c == '\"')
		ft_putstr_fd("minishell: syntax error missing a double quote\n", 2);
	else if (i == 1 && c == '<')
		ft_putstr_fd("minishell: syntax error near unexpected token `<'\n", 2);
	else if (i == 1 && c == '>')
		ft_putstr_fd("minishell: syntax errornear unexpected token `>'\n", 2);
	else if (i == 1 && c == '|')
		ft_putstr_fd("minishell: syntax errornear unexpected token `|'\n", 2);
	return (1);
}
