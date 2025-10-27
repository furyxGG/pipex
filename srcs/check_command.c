/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:43:22 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/27 21:28:21 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_help(char **com_exec)
{
	char	*temp;
	char	*temp2;

	temp = ft_strjoin("pipex: command not found: ", com_exec[0]);
	temp2 = ft_strjoin(temp, "\n");
	free(temp);
	free_list(com_exec);
	ft_putstr_fd(temp2, 2);
	free(temp2);
}

static void	path_comm_check(char *command, t_pipex *pipexlist)
{
	char	*temp;
	char	*temp2;
	int		a;
	char	**com_exec;

	com_exec = give_exec_comm(command);
	a = 0;
	while (pipexlist->paths[a])
	{
		temp = ft_strjoin(pipexlist->paths[a], "/");
		temp2 = ft_strjoin(temp, com_exec[0]);
		free(temp);
		if (access(temp2, X_OK) != 0)
		{
			free(temp2);
		}
		else
		{
			if (pipexlist->currentpath != NULL)
				free(pipexlist->currentpath);
			pipexlist->currentpath = ft_strdup(temp2);
			free_list(com_exec);
			free(temp2);
			return ;
		}
		a++;
	}
	exit_help(com_exec);
	return ;
}

static void	check_helper(char *command, t_pipex *pipexlist)
{
	char	**com_exec;

	com_exec = give_exec_comm(command);
	if (ft_strchr(command, '/') != 0)
	{
		if (access(com_exec[0], X_OK) != 0)
		{
			exit_help(com_exec);
			return ;
		}
		else
		{
			if (pipexlist->currentpath != NULL)
				free(pipexlist->currentpath);
			pipexlist->currentpath = ft_strdup(com_exec[0]);
			free_list(com_exec);
			return ;
		}
	}
	else
	{
		free_list(com_exec);
		path_comm_check(command, pipexlist);
	}
}

void	check_command_exist(t_pipex *pipexlist, int a)
{
	check_helper(pipexlist->argums[a], pipexlist);
}