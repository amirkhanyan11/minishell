/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:27:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 18:21:47 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*make_shell(char **env)
{
	t_shell	*shell;

	shell = __malloc(sizeof(t_shell));
	shell->env = make_tree_from_matrix(env, string_less);
	shell->export = make_export(shell);
	shell->history = make_list();
	shell->quoted_tokens = make_set();
	shell->stddesc = make_stddesc();
	shell->container = NULL;
	make_shlvl(shell);
	export_update(shell, "SHELL", "minishell");
	export_update(shell, "OLDPWD", "");
	unset_var(shell, "_");
	export_update(shell, "__HOME_CACHE__", get_val(shell->export, "HOME"));
	return (shell);
}
