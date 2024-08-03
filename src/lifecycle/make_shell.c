/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:27:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/03 16:01:11 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell *make_shell(char **env) __result_use_check
{
    t_shell *shell = __malloc(sizeof(t_shell));

    shell->env = make_tree_from_matrix(env, string_less);

	shell->export = make_export(shell);

	shell->path = make_path(shell);

    shell->history = make_list();

	shell->stddesc = make_stddesc();

	make_shlvl(shell);

	export_update(shell, "SHELL", "minishell");
	export_update(shell, "OLDPWD", "");
	shell->status = 0;

    return shell;
}
