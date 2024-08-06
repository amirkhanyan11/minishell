/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:27:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:42:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell * make_shell(char **env)
{
    t_shell *shell = __malloc(sizeof(t_shell));

    shell->env = make_tree_from_matrix(env, string_less);

	shell->export = make_export(shell);

    shell->history = make_list();

	shell->stddesc = make_stddesc();

	make_shlvl(shell);

	export_update(shell, "SHELL", "minishell");
	export_update(shell, "OLDPWD", "");
	shell->status = 0;

    return shell;
}
