/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:45:57 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/27 20:14:28 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execit(t_pipex *pipexlist, int a, char **envt)
{
	char	**com_exec;

	com_exec = give_exec_comm(pipexlist->argums[a]);
	check_command_exist(pipexlist, a);
	execve(pipexlist->currentpath, com_exec, envt);
}