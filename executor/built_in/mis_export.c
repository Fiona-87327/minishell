/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:53:02 by jiyawang          #+#    #+#             */
/*   Updated: 2026/01/26 18:57:32 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_sorted_env(char **env)
{
	int		i;
	char	*eq_pos;

	i = 0;
	while (env[i])
	{
		eq_pos = ft_strchr(env[i], '=');
		if (eq_pos && eq_pos[1])
		{
			printf("declare -x %.*s=\"%s\"\n", (int)(eq_pos - env[i]), env[i],
				eq_pos + 1);
		}
		else
		{
			printf("declare -x %s\n", env[i]);
		}
		i++;
	}
}

static int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	mis_export(t_command *cmd, t_minishell *shell)
{
	int	i;

	if (!cmd->args[1])
	{
		print_sorted_env(shell->env);
		return ;
	}
	i = 1;
	while (cmd->args[i])
	{
		if (is_valid_identifier(cmd->args[i]))
		{
			add_to_env(shell, cmd->args[i]);
			shell->exit_status = 0;
		}
		else
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(cmd->args[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
			shell->exit_status = 1;
		}
		i++;
	}
}
