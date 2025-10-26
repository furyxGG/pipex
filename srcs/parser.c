/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:21:46 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/26 20:36:11 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parser(int argc, char **argv, char **envt, int funct)
{
	int		ccount;
	char	**argums;
	int		a;
	
	a = 0;
	if (funct == 1) // command parser
	{
		(void)envt;
		ccount = argc - 3;
		argums = (char **)malloc((ccount + 1) * sizeof(char *));
		while (ccount)
		{
			argums[a] = (char *)malloc((ft_strlen(argv[a + 2]) + 1) * sizeof(char));
			ft_strlcpy(argums[a], argv[a + 2], ft_strlen(argv[2]) + 1);
			ccount--;
			a++;
		}
		argums[a] = NULL;
	}
	else if (funct == 2) // path parser
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
