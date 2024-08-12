/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/12 20:01:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void __print_export__(tree_node *node);
static int __export_from_string__(char *expr, t_shell *shell);

void export(t_command *cmd)
{
	eval_wrapper(cmd, _export);
}

void __export__(t_command *cmd)
{
	if (!cmd) return;

	int status = 0;

	if (empty(cmd->args) && empty(cmd->options))
	{
		print_tree_inorder_custom(cmd->shell->export, __print_export__);
	}

	else if(invalid_option(cmd) == -1)
		status = 2;

	else
	{
		t_node *arg = cmd->args->head;
		while (arg)
		{
			if (-1 == __export_from_string__(arg->val, cmd->shell))
				status = 1;
			arg = arg->next;
		}
	}
	set_exit_status(status);
}

static int __export_from_string__(char *expr, t_shell *shell)
{
	if (!expr || !shell) return -1;

	scoped_matrix arr = __split_include_delimiters(expr, '=');

	scoped_list tokens = make_list_from_matrix(arr);

	// scoped_list tokens = make_list_from_string(expr, "=", all);

	if (empty(tokens)) return -1;

	if (!is_name(tokens->head->val))
	{
		scoped_string str = __make_string("export: `", tokens->head->val, "\': not a valid identifier");
		__perror(str);
		return -1;
	}

	if (size(tokens) >= 2)
	{
		char *val = (tokens->head->next->next) ? tokens->head->next->next->val : "\0";
		return export_update(shell, tokens->head->val, val);
	}

	else
	{
		unset_var(shell, tokens->head->val);
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

	unset_var(shell, key);

	tree_update(shell->export, key, val);

	if (val)
	{
		tree_update(shell->env, key, val);
	}

	return 0;
}


static void __print_export__(tree_node *node)
{
	if (!node) return;

	printf("%s", declarex);

	printf("%s=\"%s\"\n", node->key, node->val);
}
