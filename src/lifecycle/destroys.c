/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:30:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/12 21:18:58 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	__t_shell__(t_shell *shell)
{
	if (NULL == shell)
		return ;
	list_clear(&shell->history);
	tree_clear(&shell->env);
	tree_clear(&shell->export);
	set_clear(&shell->quoted_tokens);
	free(shell->stddesc);
	free(shell);
	shell = NULL;
}

void	__t_command__(t_command **cmdptr)
{
	t_command	*cmd;

	if (NULL == cmdptr)
		return ;
	cmd = *cmdptr;
	if (NULL == cmd)
		return ;
	list_clear(&cmd->args);
	list_clear(&cmd->options);
	reset_descriptors(cmd);
	free(cmd->descriptors);
	free(cmd->name);
	free(cmd);
	*cmdptr = NULL;
}

void	__t_cmd_container__(t_cmd_container **cmdsptr)
{
	t_cmd_container	*cmds;
	size_t			i;

	if (NULL == cmdsptr)
		return ;
	cmds = *cmdsptr;
	if (NULL == cmds)
		return ;
	i = 0;
	while (i < cmds->size)
	{
		__t_command__(&(cmds->arr[i]));
		i++;
	}
	set_clear(&cmds->shell->quoted_tokens);
	cmds->shell->quoted_tokens = make_set();
	cmds->shell->container = NULL;
	get_next_fd(NULL);
	cmds->shell = NULL;
	free(cmds->arr);
	free(cmds->fds);
	free(cmds);
	*cmdsptr = NULL;
}

#pragma GCC diagnostic pop
