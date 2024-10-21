/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:27:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 16:04:11 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	make_prompt(t_shell *shell);

t_shell	*make_shell(char **env)
{
	t_shell	*shell;

	shell = __malloc(sizeof(t_shell));
	shell->env = make_tree_from_matrix(env, string_less);
	shell->export = make_export(shell);
	shell->quoted_tokens = make_set();
	shell->dollar_tokens = make_set();
	shell->orig_values = make_tree(string_less);
	shell->stddesc = make_stddesc();
	make_shlvl(shell);
	export_update(shell, "SHELL", "minishell");
	export_update(shell, "OLDPWD", "");
	unset_var(shell, "_");
	export_update(shell, "__HOME_CACHE__", get_val(shell->export, "HOME"));
	shell->ast = NULL;
	make_prompt(shell);
	return (shell);
}

static void	make_prompt(t_shell *shell)
{
	char	*username;

	username = __strdup(get_val(shell->export, "USER"));
	if (username)
		username = __strappend(username, "@", NULL);
	else
		username = __make_string_empty();
	shell->prompt = __make_string("\033[0;35m\e[3m", username,
			"minishell\033[0;32m\e[3m>$ \033[0m", NULL);
	__delete_string(&username);
}
