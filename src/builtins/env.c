/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:15:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/13 17:51:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void __print_env__(tree_node *node);

void env(t_command *cmd)
{
	eval_wrapper(cmd, _env);
}

void __env__(t_command *cmd)
{
	if (!cmd || !cmd->shell) return;

	int status = 0;

	if (invalid_option(cmd) == -1)
	{
		status = 1;
	}

	else if (!empty(cmd->args))
	{
		scoped_string str = __make_string("env", ": ", cmd->args->head->val, ": No such file or directory");
		__perror(str);
		status = 127;
	}

	else
		print_tree_inorder_custom(cmd->shell->env, __print_env__);

	set_exit_status(status);
}

void __print_env__(tree_node *node)
{
	if (!node) return;

	printf("%s=", node->key);

	if (node->val)
		printf("%s", node->val);

	printf("\n");
}
