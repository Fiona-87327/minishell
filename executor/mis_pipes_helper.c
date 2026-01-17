/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_pipes_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:55:25 by jiyawang          #+#    #+#             */
/*   Updated: 2026/01/17 20:55:55 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_child_command(t_command *cmd, t_minishell *shell)
{
	if (ft_strncmp(cmd->args[0], "pwd", 4) == 0 || ft_strncmp(cmd->args[0],
			"echo", 5) == 0 || ft_strncmp(cmd->args[0], "cd", 3) == 0
		|| ft_strncmp(cmd->args[0], "env", 4) == 0 || ft_strncmp(cmd->args[0],
			"exit", 5) == 0 || ft_strncmp(cmd->args[0], "export", 7) == 0
		|| ft_strncmp(cmd->args[0], "unset", 6) == 0)
	{
		if (mis_redirections(cmd->redirs) == -1)
			exit(1);
		if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
			mis_pwd(cmd, shell);
		else if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
			mis_echo(cmd, shell);
		else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
			mis_cd(cmd, shell);
		else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
			mis_env(cmd, shell);
		else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
			mis_exit(cmd, shell);
		else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
			mis_export(cmd, shell);
		else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
			mis_unset(cmd, shell);
		exit(shell->exit_status);
	}
	else
		mis_exec_cmd(cmd, shell);
}
