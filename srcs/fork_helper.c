/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:33:31 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/27 20:09:06 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forkit(t_pipex *pipexlist, int argc, int ifd, int ofd, char **envt)
{
	int	a;
	int	fd[2];
	pid_t *childpids = malloc((argc - 3) * sizeof(pid_t));

	a = 0;
	while (a < argc - 3)
	{
		if (pipe(fd) == -1)
			perror("pipex");
		childpids[a] = fork();
		if (childpids[a] == -1)
			perror("pipex");
		else if (childpids[a] == 0) //child
		{
			dup2(ifd, STDIN_FILENO);
            close(ifd);			
			if (a != argc - 4)
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
			perror("execve");
			exit(1);
		}
		else //parent
		{
			close(ifd);
			if (a != argc - 4)
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
    while (a < argc - 3)
    {
        waitpid(childpids[a], NULL, 0);
        a++;
    }
}