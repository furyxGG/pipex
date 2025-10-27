/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:19:02 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/27 19:42:28 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **argv, char **envt)
{
	t_pipex	*pipexlist;
	int		ifd;
	int		ofd;

	ifd = open(argv[1], O_RDONLY);
	if (ifd == -1)
		perror("pipex");
	ofd = open (argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ofd == -1)
	{
		perror("pipex");
		exit(1);
	}
	pipexlist = malloc(sizeof(t_pipex));
	pipexlist->argums = parser(argc, argv, envt, 1);
	pipexlist->paths = parser(argc, argv, envt, 2);
	forkit(pipexlist, argc, ifd, ofd, envt);
}
