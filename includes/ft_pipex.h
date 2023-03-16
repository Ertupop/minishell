/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 08:43:37 by ertupop           #+#    #+#             */
/*   Updated: 2023/03/16 09:07:53 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

typedef struct s_pipex
{
	char	**path;
	char	*command1;
	char	*command2;
	char	**args1;
	char	**args2;
	pid_t	child1;
	pid_t	child2;
	int		infile;
	int		outfile;
	int		pipe[2];
}	t_pipex;

//pipex
int		main(int ac, char **av, char **envp);
int		ft_pipex_error(int error, char *av);
void	ft_main2(t_pipex *pip, char **envp, char **av);

//parsing
void	ft_path(char **env, t_pipex *pip);
int		ft_find_path(char **env);
char	*ft_command(t_pipex *pip, char *command);
int		ft_is_a_slash(char	*command);
void	ft_path2(t_pipex *pip);

//utils
char	*ft_join(char *first, char *second);
void	ft_child1(t_pipex	*pip);
void	ft_child2(t_pipex	*pip, char **envp);
//finish
void	ft_finish(t_pipex *pip);
void	ft_finish_child1(t_pipex *pip);
void	ft_finish_child2(t_pipex *pip);
#endif
