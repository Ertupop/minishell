/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:13:24 by ertupop           #+#    #+#             */
/*   Updated: 2023/02/08 13:51:49 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_acces_heredoc(void)
{
	int		fd;
	char	*str;
	char	*number;
	char	heredoc;
	int		i;

	fd = -1;
	i = 0;
	str = ft_strdup(".tmp_heredoc");
	number = NULL;
	heredoc = NULL;
	if (str == NULL)
		return (-1);
	while (fd == -1 || i < 100)
	{
		fd = ft_heredoc_while(i, str, number, heredoc);
		i++;
	}
	ft_acces_free(str, number, heredoc);
	return (fd);
}

int	ft_heredoc_while(int i, char *str, char *number, char *heredoc)
{
	int	fd;

	number = ft_strdup(ft_itoa(i));
	if (number == NULL)
		return (-1);
	heredoc = ft_strjoin(str, number);
	if (heredoc == NULL)
		return (-1);
	free(number);
	number = NULL;
	fd = open(heredoc, O_CREAT | O_RDWR | O_TRUNC);
	free(heredoc);
	heredoc = NULL;
	if (fd > -1 || i == 99)
	{
		free(str);
		str = NULL;
	}
}

void	ft_acces_free(char *str, char *number, char *heredoc)
{
	if (number != NULL)
		free(number);
	if (heredoc != NULL)
		free(heredoc);
	if (str != NULL)
		free(str);
}

void	ft_heredoc(int fd, const char *end)
{
	char	*str;
	t_sig	signal;

	sigaction(&signal, ft_sig_handler_heredoc);
	while (1)
	{
		str = readline(">");
		if (str == NULL)
		{
			printf("minishell: warning: here-document at line ");
			printf("5 by end-of-file (wanted `%s')", end);
			exit(0);
		}
		if (strcmp(str, end) == 0)
		{
			free(str);
			close(fd);
		}
		ft_putendl_fd(str, fd);
		free(str);
	}
}
