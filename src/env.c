/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:56:20 by jiyawang          #+#    #+#             */
/*   Updated: 2025/12/29 15:56:32 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
char	*get_env_value(t_program *program, const char *key)
{
    int		i;
    size_t	key_len;

    if (!program || !program->env || !key)
        return (NULL);
    key_len = ft_strlen(key);
    i = 0;
    while (program->env[i])
    {
        if (ft_strncmp(program->env[i], key, key_len) == 0
            && program->env[i][key_len] == '=')
            return (program->env[i] + key_len + 1);
        i++;
    }
    return (NULL);
}