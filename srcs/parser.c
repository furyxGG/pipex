/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:21:46 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/29 12:38:50 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* command parser = 1
 	path parser = 2 */
static void	set_variables(int argc, int *ccount,
	int *findex, t_pipex *pipexlist)
{
	if (pipexlist->here_doc == 1)
	{
		*ccount = argc - 4;
		*findex = 3;
	}
	else
	{
		*ccount = argc - 3;
		*findex = 2;
	}
}

static char	**command_parser(int argc, char **argv,
	t_pipex *pipexlist)
{
	int		ccount;
	int		findex;
	int		a;
	char	**argums;

	a = 0;
	argums = NULL;
	set_variables(argc, &ccount, &findex, pipexlist);
	argums = (char **)malloc((ccount + 1) * sizeof(char *));
	while (ccount)
	{
		argums[a] = ft_strdup(argv[a + findex]);
		ccount--;
		a++;
	}
	argums[a] = NULL;
	return (argums);
}

char	**parser(int argc, char **argv, char **envt, t_pipex *pipexlist)
{
	char	**argums;
	int		a;

	a = 0;
	argums = NULL;
	if (pipexlist->funct == 1)
	{
		(void)envt;
		argums = command_parser(argc, argv, pipexlist);
	}
	else if (pipexlist->funct == 2)
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
