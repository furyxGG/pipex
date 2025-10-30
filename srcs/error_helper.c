/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:56:53 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/30 14:15:51 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_error(pid_t *childpids, t_pipex *pipexlist, int ifd, int ofd)
{
	perror("pipex: pipe(fd) error");
	free(childpids);
	free_pipex(pipexlist);
	close(ifd);
	close(ofd);
	exit(1);
}

void	fork_error(pid_t *childpids, t_pipex *pipexlist, int ifd, int ofd)
{
	perror("pipex: fork error");
	free(childpids);
	free_pipex(pipexlist);
	close(ifd);
	close(ofd);
	exit(1);
}

void	child_helper_one(int a, t_pipex *pipexlist, int fd[2], int ofd)
{
	if (a != pipexlist->commandcnt - 1)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
	else
	{
		dup2(ofd, STDOUT_FILENO);
		close(ofd);
	}
}

void	child_helper_two(int ifd)
{
	if (ifd == -1)
		null_helper();
	else
		dup2(ifd, STDIN_FILENO);
	if (ifd != -1)
		close(ifd);
}
