/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/09 17:40:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;

void echo(t_command *cmd)
{
	eval_wrapper(cmd, _echo);
}

static bool last_nl(t_node * const node);
static void echo_arglist(t_list *arglist);


void __echo__(t_command *cmd)
{
	if (!cmd) return;


	bool newline = true;

	if (!empty(cmd->options) && string_equal(cmd->options->head->val, "-n"))
	{
		newline = false;

		erase(cmd->options, cmd->options->head, find_if(cmd->options->head, cmd->options->tail, last_nl));
	}

	if (!empty(cmd->options)) push_back(cmd->options, "");

	echo_arglist(cmd->options);
	echo_arglist(cmd->args);

	if (newline)
		printf("\n");

	g_exit_status = 0;
}

static void echo_arglist(t_list *arglist)
{

	if (!arglist) return;

	t_node *arg = arglist->head;
	while (arg)
	{
		printf("%s", arg->val);
		if (arg->next) printf(" ");
		arg = arg->next;
	}
}

static bool last_nl(t_node * const node)
{
	if (!node || !node->val) return false;

	return string_equal(node->val, "-n") && (node->next == NULL || !string_equal(node->next->val, "-n"));
}
