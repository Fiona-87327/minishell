/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:29:00 by jiyawang          #+#    #+#             */
/*   Updated: 2026/01/14 16:26:42 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mis_redirections(t_command *cmd)
{
	t_redir	*current_redir;
	int		fd;

	current_redir = cmd->redirs;
	while (current_redir)
	{
		if (current_redir->type == REDIRECT_INPUT)
			fd = open(current_redir->filename, O_RDONLY);
		else if (current_redir->type == REDIRECT_OUTPUT)
			fd = open(current_redir->filename, O_WRONLY | O_CREAT | O_TRUNC,
					0644);
		else if (current_redir->type == REDIRECT_APPEND)
			fd = open(current_redir->filename, O_WRONLY | O_CREAT | O_APPEND,
					0644);
		else if (current_redir->type == REDIRECT_HEREDOC)
			fd = current_redir->heredoc_fd;
		if (fd < 0)
			return (perror("open error"), -1);
		if (current_redir->type == REDIRECT_INPUT
			|| current_redir->type == REDIRECT_HEREDOC)
		{
			if (dup2(fd, STDIN_FILENO) < 0)
				return (perror("dup2 error"), close(fd), -1);
		}
		else if (dup2(fd, STDOUT_FILENO) < 0)
			return (perror("dup2 error"), close(fd), -1);
		current_redir = current_redir->next;
	}
	return (0);
}
