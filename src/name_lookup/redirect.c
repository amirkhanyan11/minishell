/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 00:13:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

int redirect(t_node *token, t_command *cmd)
{
	if (!token || !token->next || list_value_same(token->next->val, ""))
	{
		__perror((token->next) ? "ambiguous redirect" : "syntax error");
		return -1;
	}

	t_file fd = -1;

	if (list_value_same(token->val, "<"))
	{
		fd = open_file(token->next->val, O_RDONLY);
		if (fd == -1)
		 	return -1;
		cmd->descriptors->stdin = fd;
		cmd->redirection |= redirect_in;
	}
	else if (list_value_same(token->val, ">"))
	{
		fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_TRUNC);
		if (fd == -1)
		 	return -1;
		cmd->descriptors->stdout = fd;
		cmd->redirection |= redirect_out;
	}
	else
	{
		fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_APPEND);
		if (fd == -1)
		 	return -1;
		cmd->descriptors->stdout = fd;
		cmd->redirection |= redirect_out;
	}
	return 0;
}
