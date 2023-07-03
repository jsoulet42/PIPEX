/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:04:57 by jsoulet           #+#    #+#             */
/*   Updated: 2023/07/03 09:55:01 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "./INCLUDES/libft/libft.h"

void	doc_read(char *av, int *fd);
void	doc(char *av, int ac);
char	*path_check(char *cmd, char **ev);
void	init_path(char *av, char **env);
void	child(char *av, char **env);
int		open3(int ac, char **av, int fd);
int		open2(int ac, char **av, int fd);

#endif
