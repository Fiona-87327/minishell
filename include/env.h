/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:52:49 by jiyawang          #+#    #+#             */
/*   Updated: 2025/12/29 15:53:52 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "minishell.h"
char	*get_env_value(t_program *program, const char *key);
int		set_env_value(t_program *program, const char *key, const char *value);
int		unset_env_value(t_program *program, const char *key);
char	**copy_env(char **env);
void	free_env(char **env);
#endif
