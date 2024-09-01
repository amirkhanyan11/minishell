/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/01 17:14:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*make_command(t_list *tokens, t_cmd_container *container,
		t_shell *shell)
{
	t_command	*cmd;

	if (empty(tokens) || !shell)
		return (NULL);
	cmd = __malloc(sizeof(t_command));
	cmd->descriptors = make_stddesc();
	cmd->shell = shell;
	cmd->pid = -1337;
	cmd->container = container;
	cmd->options = make_list();
	cmd->args = make_list();
	cmd->eval = NULL;
	cmd->redirection = 0;
	cmd->name = __strdup(tokens->head->val);

	if (pop_redirections(cmd, tokens, container) == -1 || empty(tokens) || sort_tokens(cmd, tokens) == -1 || cmd_lookup(cmd) == -1)
	{
		if (cmd->redirection & redirect_heredoc)
		{
			unlink(HEREDOC);
		}
		__t_command__(&cmd);
	}
	return (cmd);
}

int pop_redirections(t_command *cmd, t_list *tokens, t_cmd_container *container)
{
	t_node	*token;
	t_node	*next;

	token = tokens->head;
	while (token)
	{
		next = token->next;
		if (is_redirection(token->val))
		{
			next = token->next->next;
			t_fd fd = -1337;
			if (string_equal(token->val, "<") || string_equal(token->val, "<<"))
			{
				fd = get_next_fd(container);
				close(cmd->descriptors->stdin);
				cmd->descriptors->stdin = fd;
				cmd->redirection |= redirect_in;
				if (string_equal(token->val, "<<"))
					cmd->redirection |= redirect_heredoc;
			}
			if (string_equal(token->val, ">") || string_equal(token->val, ">>"))
			{
				fd = get_next_fd(container);
				close(cmd->descriptors->stdout);
				cmd->descriptors->stdout = fd;
				cmd->redirection |= redirect_out;
			}
			if (fd == -1)
				return -1;
			erase(tokens, token, token->next);
		}
		token = next;
	}
	get_next_fd_idx(NULL);
	return (0);
}
