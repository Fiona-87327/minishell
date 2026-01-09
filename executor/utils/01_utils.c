/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:36:10 by jiyawang          #+#    #+#             */
/*   Updated: 2026/01/09 15:04:34 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_existing_env(char **env, char *name, char *va_arg)
{
	int	i;
	int	len;

	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && (env[i][len] == '='
			|| env[i][len] == '\0'))
		{
			if (ft_strchr(va_arg, '='))
			{
				free(env[i]);
				env[i] = ft_strdup(va_arg);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

static char	**append_env_row(char **old_env, char *va_arg)
{
	int		i;
	char	**new_env;

	i = 0;
	while (old_env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (NULL);
	i = 0;
	while (old_env[i])
	{
		new_env[i] = old_env[i];
		i++;
	}
	new_env[i] = ft_strdup(va_arg);
	new_env[i + 1] = NULL;
	free(old_env);
	return (new_env);
}

void	add_to_env(t_minishell *shell, char *arg)
{
	char	*name;

	name = get_var_name(arg);
	if (!name)
		return ;
	if (!update_existing_env(shell->env, name, arg))
	{
		shell->env = append_env_row(shell->env, arg);
	}
	free(name);
}

char	*get_env_value(char **env, char *key)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}
