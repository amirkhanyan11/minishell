/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:45:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

extern int g_exit_status;

void echo(t_command *cmd)
{
	eval_wrapper(cmd, _echo);
}

static bool last_nl(t_node * const node);
static void echo_arglist(t_list *arglist);

static bool not_n_predicate(char c);
static bool is_n(char * opt);


void __echo__(t_command *cmd)
{
	if (!cmd) return;


	bool newline = true;

	if (!empty(cmd->options) && is_n(cmd->options->head->val))
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

	return is_n(node->val) && (node->next == NULL || !is_n(node->next->val));
}

static bool not_n_predicate(char c)
{
	return (c != 'n');
}

static bool is_n(char * opt)
{
	if (__strlen(opt) < 2) return false;

	opt++;

	return (*__strchr_p(opt, not_n_predicate) == '\0');
}


#pragma GCC diagnostic pop
