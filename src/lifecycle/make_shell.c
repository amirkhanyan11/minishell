/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:27:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/25 17:49:52 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell * __result_use_check make_shell(char **env)
{
    t_shell *shell = __malloc(sizeof(t_shell));

    shell->env = make_list_from_matrix(env);

	shell->export = make_export(shell);

	shell->path = make_path(shell);

    shell->history = make_list();

	shell->descriptors = make_descriptors(1488, 1337, 1234);
	shell->sysdescriptors = make_descriptors(111, 222, 333);
	dup2(STDOUT_FILENO, shell->sysdescriptors->stdout);
	dup2(STDIN_FILENO, shell->sysdescriptors->stdin);
	dup2(STDERR_FILENO, shell->sysdescriptors->stderr);

	shell->status = 0;

    return shell;
}
