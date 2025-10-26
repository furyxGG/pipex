/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:43:22 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/26 22:31:31 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			ft_printf("dogruuuuuu: %s\n", temp2);
			free_list(com_exec);
			free(temp2);
			return ;
		}
		a++;
	}
	free_list(com_exec);
	perror("Wrong command");
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
			free_list(com_exec);
			perror("Wrong command");
			return ;
		}
		else
		{
			ft_printf("dogruuuuuu: %s\n", com_exec[0]);
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

void	check_command_exist(t_pipex *pipexlist)
{
	int		a;

	a = 0;
	while (pipexlist->argums[a])
	{
		check_helper(pipexlist->argums[a], pipexlist);
		a++;
	}
	free_pipex(pipexlist);
}