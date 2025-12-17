/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:13:47 by jiyawang          #+#    #+#             */
/*   Updated: 2025/12/17 20:54:02 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "minishell.h"

int		is_builtin(t_cmd *cmd);
int		exec_builtin(t_cmd *cmd, t_program *program);
int		builtin_cd(t_cmd *cmd, t_program *program);
int		builtin_echo(t_cmd *cmd);
int		builtin_env(t_cmd *cmd, t_program *program);
int		builtin_exit(t_cmd *cmd, t_program *program);
int		builtin_export(t_cmd *cmd, t_program *program);
int		builtin_pwd(t_cmd *cmd);
int		builtin_unset(t_cmd *cmd, t_program *program);
#endif
