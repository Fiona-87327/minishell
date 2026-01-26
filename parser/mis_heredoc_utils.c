/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_heredoc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:46:17 by jiyawang          #+#    #+#             */
/*   Updated: 2026/01/26 20:47:13 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_is_quoted(const char *delim)
{
	while (*delim)
	{
		if (*delim == '\'' || *delim == '"')
			return (1);
		delim++;
	}
	return (0);
}

int	heredoc_cleanup(char *line, char *delim, int *fd, int return_val)
{
	if (line)
		free(line);
	if (delim)
		free(delim);
	if (fd)
	{
		close(fd[1]);
		if (return_val == -1)
			close(fd[0]);
	}
	return (return_val);
}
