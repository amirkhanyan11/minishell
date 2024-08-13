/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/13 17:50:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void __print_export__(tree_node *node);
static int __export_from_string__(char *expr, t_shell *shell);
static bool not_equal_sign(t_node *const node);

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

static int __export_from_string__(char *expr, t_shell *shell) // export ==========
{
	if (!expr || !shell) return -1;

	scoped_list tokens = make_list_from_string(expr, "=", all);

	if (empty(tokens)) return -1;

	t_node *lhv = tokens->head;

	if (lhv->val[__strlen(lhv->val) - 1] == '+')
	{
		lhv->val[__strlen(lhv->val) - 1] = '\0';

		char *old_val = get_val(shell->export, lhv->val);

		if (old_val == NULL) old_val = "";

		list_insert(tokens, lhv->next, old_val);
	}

	if (!is_name(lhv->val) || NULL == find_if(lhv, tokens->tail, not_equal_sign))
	{
		scoped_string str = __make_string("export: `", expr, "\': not a valid identifier");
		__perror(str);
		return -1;
	}

	if (size(tokens) >= 2)
	{
		// scoped_string val = (tokens->head->next->next) ? tokens->head->next->next->val : "\0";
		scoped_string val = __make_string_from_list(lhv->next->next, tokens->tail);
		if (val == NULL) val = __make_string_empty();
		return export_update(shell, lhv->val, val);
	}

	else
	{
		unset_var(shell, lhv->val);
		tree_update(shell->export, lhv->val, NULL);
	}

	return 0;
}

int export_update(t_shell *shell, t_list_value key, t_list_value val)
{
	if (!shell || !key) return -1;

	if (!is_name(key))
	{
		scoped_string str = __make_string("export: `", key, "\': not a valid identifier");
		__perror(str);
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

	printf("%s", node->key);

	if (node->val)
		printf("=\"%s\"", node->val);

	printf("\n");
}

static bool not_equal_sign(t_node *const node)
{
	return node && !string_equal(node->val, "=");
}
