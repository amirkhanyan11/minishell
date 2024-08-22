/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:15:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/21 19:06:39 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	__print_env__(t_tree_node *node);

void	env(t_command *cmd)
{
	eval_wrapper(cmd, _env);
}

void	__env__(t_command *cmd)
{
	int		status;
	char	*str;

	if (!cmd || !cmd->shell)
		return ;
	status = 0;
	if (invalid_option(cmd) == -1)
		status = 1;
	else if (!empty(cmd->args))
	{
		str = __make_string("env", ": ", front(cmd->args)->val,
				": No such file or directory");
		__perror(str);
		__delete_string(&str);
		status = 127;
	}
	else
		print_tree_inorder_custom(cmd->shell->env, __print_env__);
	set_exit_status(status);
}

void	__print_env__(t_tree_node *node)
{
	if (!node)
		return ;
	printf("%s=", node->key);
	if (node->val)
		printf("%s", node->val);
	printf("\n");
}

#pragma GCC diagnostic pop
