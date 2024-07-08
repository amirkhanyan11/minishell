/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:27:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 23:32:34 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell *make_shell(char **env)
{
    t_shell *shell = __malloc(sizeof(t_shell));

    shell->env = make_list_from_matrix(env);

	shell->path = make_path(shell);

    shell->history = make_list();

	shell->sysdescriptors = make_descriptors();
	shell->descriptors =    make_descriptors();

    return shell;
}
