/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:01:55 by jsoulet           #+#    #+#             */
/*   Updated: 2023/07/03 09:53:00 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd[2];

	fd[0] = 0;
	fd[1] = 0;
	if (ac < 5)
		printerror("veuillez entrer les argument de facons legit", 1);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 3;
		fd[1] = open2(ac, av, fd[1]);
		doc(ft_strjoin(av[2], "\n"), ac);
	}
	else
	{
		i = 2;
		fd[0] = open3(ac, av, fd[0]);
		fd[1] = open2(ac, av, fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
	while (i < ac - 2)
		child(av[i++], env);
	dup2(fd[1], STDOUT_FILENO);
	init_path(av[i], env);
	return (0);
}

int	open3(int ac, char **av, int fd)
{
	(void)ac;
	fd = open(av[1], O_RDONLY, 664);
	if (fd == -1)
		printerror("error", 1);
	return (fd);
}

int	open2(int ac, char **av, int fd)
{
	(void)ac;
	fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		printerror("error", 1);
	return (fd);
}

void	child(char *av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		printerror("error", 1);
	pid = fork();
	if (pid == -1)
		printerror("error", 1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		printf("av = %s\n", av);
		init_path(av, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	init_path(char *av, char **env)
{
	char	**cmd;
	char	*path;
	char	*err;

	cmd = ft_split(av, ' ');
	path = path_check(cmd[0], env);
	if (!path)
	{
		err = ft_strjoin(cmd[0], " : commande introuvable");
		ft_printf("%s\n", err);
		free(err);
		free_t2t(cmd);
		exit(2);
	}
	execve(path, cmd, env);
}
