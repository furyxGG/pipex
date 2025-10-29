/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:51:38 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/29 07:55:33 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct	s_pipex
{
	char	**paths;
	char	**argums;
	char	*currentpath;
	int		here_doc;
	int		funct;
	int		commandcnt;
}				t_pipex;


void	pipex(int argc, char **argv, char **envt, int heredoc);

char	**parser(int argc, char **argv, char **envt, t_pipex *pipexlist);

char	**give_exec_comm(char *argum);

void	check_command_exist(t_pipex *pipexlist, int a);

void	forkit(t_pipex *pipexlist, int ifd, int ofd, char **envt);
void	execit(t_pipex *pipexlist, int a, char **envt);

int		here_take(char	*limiter);

void	free_list(char **list);
void	free_pipex(t_pipex *pipexlist);

#endif