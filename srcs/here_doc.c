/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:43:16 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/10/29 08:00:50 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_take(char	*limiter)
{
	char	*content;
	int		fd[2];
	char	*templimiter;
	
	if (pipe(fd) == -1)
		exit(1);
	templimiter = ft_strjoin(limiter, "\n");
	ft_printf("pipex heredoc> ");
	content = get_next_line(STDIN_FILENO);
	while (content)
	{
		if (ft_strncmp(content, templimiter, ft_strlen(content)) == 0)
		{
			free(content);
			break;
		}
		ft_putstr_fd(content, fd[1]);
		free(content);
		ft_printf("pipex heredoc> ");
		content = get_next_line(STDIN_FILENO);
	}
	free(templimiter);
	close(fd[1]);
	return (fd[0]);
}
