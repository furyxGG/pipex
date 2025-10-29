/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:19:02 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/29 07:57:03 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **argv, char **envt, int heredoc)
{
	t_pipex	*pipexlist;
	int		ifd;
	int		ofd;
	int		cc;

	if (heredoc == 0)
	{
		ifd = open(argv[1], O_RDONLY);
		if (ifd == -1)
			perror("pipex");
		ofd = open (argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (ofd == -1)
		{
			perror("pipex");
			if (ifd != -1)
				close(ifd);
			exit(1);
		}
		cc = argc - 3;
	}
	else if (heredoc == 1)
	{
		ifd = here_take(argv[2]);
		ofd = open (argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (ofd == -1)
		{
			perror("pipex");
			if (ifd != -1)
				close(ifd);
			exit(1);
		}
		cc = argc - 4;
	}
	pipexlist = malloc(sizeof(t_pipex));
	if (!pipexlist)
	{
		close(ifd);
		close(ofd);
		exit(1);
	}
	pipexlist->currentpath = NULL;
	pipexlist->here_doc = heredoc;
	pipexlist->funct = 1;
	pipexlist->argums = parser(argc, argv, envt, pipexlist);
	pipexlist->funct = 2;
	pipexlist->paths = parser(argc, argv, envt, pipexlist);
	pipexlist->commandcnt = cc;
	forkit(pipexlist, ifd, ofd, envt);
	free_pipex(pipexlist);
}
