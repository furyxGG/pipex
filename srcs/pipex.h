/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:51:38 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/26 22:23:03 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/types.h>

typedef struct	s_pipex
{
	char	**paths;
	char	**argums;
}				t_pipex;


void	pipex(int argc, char **argv, char **envt);

char	**parser(int argc, char **argv, char **envt, int funct);

char	**give_exec_comm(char *argum);

void	check_command_exist(t_pipex *pipexlist);

void	free_list(char **list);
void	free_pipex(t_pipex *pipexlist);

#endif