/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:46:12 by jsoulet           #+#    #+#             */
/*   Updated: 2023/07/03 09:47:15 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_check(char *cmd, char **ev)
{
	char	**paths;
	char	*path;
	char	*str_temp;
	int		i;

	i = -1;
	if (!*ev)
		exit(2);
	while (ev[++i])
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
			break ;
	}
	paths = ft_split(ev[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		str_temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(str_temp, cmd);
		free(str_temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

void	doc(char *av, int ac)
{
	pid_t	pid;
	int		fd[2];

	if (ac != 6)
		printerror("Error please use herdoc and six argument legit", 1);
	if (pipe(fd) == -1)
		printerror("Error", 1);
	pid = fork();
	if (pid == 0)
	{
		doc_read(av, fd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	doc_read(char *av, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av, ft_strlen(line)) == 0)
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
}
