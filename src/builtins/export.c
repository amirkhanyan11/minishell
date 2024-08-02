/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 19:48:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

static void __print_export__(tree_node *node);


void export(t_command *cmd)
{
	if (empty(cmd->args))
	{
		print_tree_inorder_custom(shell->export, __print_export__);
		return ;
	}

	// print_list(cmd->args);
	t_node *arg = cmd->args->head;

	while (arg)
	{
		__export_from_string__(arg->val);
		arg = arg->next;
	}

}

int __export_from_string__(char *expr)
{
	if (!expr) return -1;

	a_matrix arr = __split_include_delimiters(expr, '=');

	a_list tokens = make_list_from_matrix(arr);

	// a_list tokens = make_list_from_string(expr, "=", all);

	if (empty(tokens)) return -1;

	if (!is_name(tokens->head->val))
	{
		__perror("export: not a valid identifier");
		return -1;
	}

	if (size(tokens) >= 2)
	{
		char *val = (tokens->head->next->next) ? tokens->head->next->next->val : "\0";
		return export_update(shell, tokens->head->val, val);
	}

	else
	{
		__unset__(shell, tokens->head->val);
		tree_update(shell->export, tokens->head->val, "");
	}

	return 0;
}

int export_update(t_shell *shell, t_list_value key, t_list_value val)
{
	if (!shell || !key) return -1;

	if (!is_name(key))
	{
		__perror("export: not a valid identifier");
		return -1;
	}

	__unset__(shell, key);

	tree_update(shell->export, key, val);

	if (val)
	{
		tree_update(shell->env, key, val);

		if (list_value_same(key, "PATH")) shell->path = make_path(shell);
	}

	return 0;
}


static void __print_export__(tree_node *node)
{
	if (!node) return;

	printf("%s", declarex);

	printf("%s=\"%s\"\n", node->key, node->val);
}
