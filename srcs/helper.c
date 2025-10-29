/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:40:39 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/27 21:31:00 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_list(char **list)
{
	int	a;

	a = 0;
	while (list[a])
	{
		free(list[a]);
		a++;
	}
	free(list);
}

char	**give_exec_comm(char *argum)
{
	char	**com_exec;

	com_exec = ft_split(argum, ' ');
	return (com_exec);
}

void	free_pipex(t_pipex *pipexlist)
{
	free_list(pipexlist->argums);
	free_list(pipexlist->paths);
	if (pipexlist->currentpath)
		free(pipexlist->currentpath);
	free(pipexlist);
}
