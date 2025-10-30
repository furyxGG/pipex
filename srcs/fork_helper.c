/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:33:31 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/30 14:16:02 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	helper_childpids_malloc(t_pipex *pipexlist, int ifd, int ofd)
{
	perror("pipex: childpids malloc");
	close(ifd);
	close(ofd);
	free_pipex(pipexlist);
	exit(1);
}

void	null_helper(void)
{
	int	nullfd;

	nullfd = open("/dev/null", O_RDONLY);
	if (nullfd == -1)
	{
		perror("pipex");
		exit(1);
	}
	dup2(nullfd, STDIN_FILENO);
	close(nullfd);
}

static void	waitpid_helper(t_pipex *pipexlist, pid_t *childpids)
{
	int	a;

	a = 0;
	while (a < pipexlist->commandcnt)
	{
		waitpid(childpids[a], NULL, 0);
		a++;
	}
	free(childpids);
}

static void	parent_helper(int *ifd, int fd[2], int a, t_pipex *pipexlist)
{
	if (*ifd != -1)
		close(*ifd);
	if (a != pipexlist->commandcnt - 1)
	{
		close(fd[1]);
		*ifd = fd[0];
	}
	else
		close(fd[0]);
}

void	forkit(t_pipex *pipexlist, int ifd, int ofd, char **envt)
{
	int		a;
	int		fd[2];
	pid_t	*childpids;

	childpids = malloc((pipexlist->commandcnt) * sizeof(pid_t));
	if (!childpids)
		helper_childpids_malloc(pipexlist, ifd, ofd);
	a = -1;
	while (++a < pipexlist->commandcnt)
	{
		if (pipe(fd) == -1)
			pipe_error(childpids, pipexlist, ifd, ofd);
		childpids[a] = fork();
		if (childpids[a] == -1)
			fork_error(childpids, pipexlist, ifd, ofd);
		else if (childpids[a] == 0)
		{
			child_helper_two(ifd);
			child_helper_one(a, pipexlist, fd, ofd);
			execit(pipexlist, a, envt, childpids);
		}
		else
			parent_helper(&ifd, fd, a, pipexlist);
	}
	waitpid_helper(pipexlist, childpids);
}
