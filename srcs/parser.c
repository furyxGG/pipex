/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:21:46 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/29 07:49:52 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parser(int argc, char **argv, char **envt, t_pipex *pipexlist)
{
	int		ccount;
	int		findex;
	char	**argums;
	int		a;
	
	a = 0;
	argums = NULL;
	if (pipexlist->funct == 1) // command parser
	{
		(void)envt;
		if (pipexlist->here_doc == 1)
		{
			ccount = argc - 4;
			findex = 3;
		}
		else
		{
			ccount = argc - 3;
			findex = 2;
		}
		argums = (char **)malloc((ccount + 1) * sizeof(char *));
		while (ccount)
		{
			argums[a] = ft_strdup(argv[a + findex]);
			ccount--;
			a++;
		}
		argums[a] = NULL;
	}
	else if (pipexlist->funct == 2) // path parser
	{
		(void)argc;
		(void)argv;
		while (envt[a])
		{
			if (ft_strncmp(envt[a], "PATH=", 5) == 0)
				argums = ft_split(envt[a] + 5, ':');
			a++;
		}
	}
	return (argums);
}
