/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:49:22 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/28 13:40:09 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envt)
{
	int	heredoc;
	
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 6)
		{
			ft_putstr_fd("Error: insufficient number of arguments\nUsage: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
			return (1);
		}
		heredoc = 1;
	}
	else
	{
		if (argc < 5)
		{
			ft_putstr_fd("Error: insufficient number of arguments\nUsage: ./pipex infile cmd1 cmd2 ... cmdx outfile\nOr you can use 'HERE_DOC'\n", 2);
			return (1);
		}
		heredoc = 0;
	}
	pipex(argc, argv, envt, heredoc);
	return (1);
}
