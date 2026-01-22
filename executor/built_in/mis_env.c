/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:54:14 by jiyawang          #+#    #+#             */
/*   Updated: 2026/01/21 14:10:13 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mis_env(t_command *cmd, t_minishell *shell)
{
	char		**env;

	(void)cmd;
	env = shell->env;
	while (*env)
	{
		if (ft_strchr(*env, '='))
		{
			ft_putstr_fd(*env, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		env++;
	}
}
