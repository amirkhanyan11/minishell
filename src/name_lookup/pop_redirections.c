/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:37:08 by codespace         #+#    #+#             */
/*   Updated: 2024/09/01 18:41:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pop_redirections(t_command *cmd, t_list *tokens, t_cmd_container *container)
{
	t_node *token;
	t_node *next;

	token = tokens->head;
	while (token)
	{
		next = token->next;
		if (is_redirection(token->val)
			&& !is_quoted_token(container->shell->quoted_tokens, token))
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
				return (-1);
			erase(tokens, token, token->next);
		}
		token = next;
	}
	get_next_fd_idx(NULL);
	return (0);
}