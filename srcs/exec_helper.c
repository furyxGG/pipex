/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:45:57 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/29 09:05:44 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execit(t_pipex *pipexlist, int a, char **envt, pid_t *childpids)
{
	char	**com_exec;

	com_exec = give_exec_comm(pipexlist->argums[a]);
	check_command_exist(pipexlist, a);
	if (pipexlist->currentpath == NULL)
	{
		free_list(com_exec);
		free(childpids);
		if (pipexlist->here_doc)
			get_next_line(-42);
		free_pipex(pipexlist);
		exit(127);
	}
	execve(pipexlist->currentpath, com_exec, envt);
	free_list(com_exec);
	free(childpids);
	perror("pipex (execve error)");
	if (pipexlist->here_doc)
		get_next_line(-42);
	free_pipex(pipexlist);
	exit(126);
}
