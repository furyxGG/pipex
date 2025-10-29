/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:33:31 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/29 07:58:07 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forkit(t_pipex *pipexlist, int ifd, int ofd, char **envt)
{
	int	a;
	int	fd[2];
	pid_t *childpids = malloc((pipexlist->commandcnt) * sizeof(pid_t));
	if (!childpids)
	{
		perror("pipex: childpids malloc");
		close(ifd);
		close(ofd);
		free_pipex(pipexlist);
		exit(1);
	}

	a = 0;
	while (a < pipexlist->commandcnt)
	{
		if (pipe(fd) == -1)
		{
			perror("pipex: pipe(fd) error");
			free(childpids);
			free_pipex(pipexlist);
			close(ifd);
			close(ofd);
			exit(1);
		}
		childpids[a] = fork();
		if (childpids[a] == -1)
		{
			perror("pipex: fork error");
			free(childpids);
			free_pipex(pipexlist);
			close(ifd);
			close(ofd);
			exit(1);
		}
		else if (childpids[a] == 0) //child
		{
			if (ifd == -1)
			{
				int nullfd = open("/dev/null", O_RDONLY);
				if (nullfd == -1)
				{
					perror("pipex");
					exit(1);
				}
    			dup2(nullfd, STDIN_FILENO);
    			close(nullfd);
			}
			else
				dup2(ifd, STDIN_FILENO);
            close(ifd);
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
			execit(pipexlist, a, envt);
		}
		else //parent
		{
			close(ifd);
			if (a != pipexlist->commandcnt - 1)
            {
                close(fd[1]);
                ifd = fd[0];
            }
			else
				close(fd[0]);
		}
		a++;
	}
	a = 0;
    while (a < pipexlist->commandcnt)
    {
        waitpid(childpids[a], NULL, 0);
        a++;
    }
	free(childpids);
}
