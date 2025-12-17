/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:14:18 by jiyawang          #+#    #+#             */
/*   Updated: 2025/12/17 13:14:48 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

int	is_builtin(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd_name, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_name, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_name, "env") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_name, "exit") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_name, "export") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_name, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd->cmd_name, "unset") == 0)
		return (1);
	return (0);
}
