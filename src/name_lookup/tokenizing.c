/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:08:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/21 21:19:23 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*tokenize(char *raw_cmd)
{
	t_list	*tokens;

	if (!raw_cmd)
		return (NULL);
	tokens = make_list_from_string(raw_cmd, SPECIAL_SYMBOLS, all);
	if (!tokens || quote_parse(tokens) == -1)
	{
		set_exit_status(2);
		list_clear(&tokens);
	}
	return (tokens);
}

int	redirection_parse(t_list *tokens, t_shell *shell)
{
	t_node	*rdr;

	if (!tokens)
		return (0);
	rdr = NULL;
	rdr = find_if(front(tokens), back(tokens), is_redir);
	while (rdr && is_quoted_token(shell->quoted_tokens, rdr))
		rdr = find_if(rdr->next, back(tokens), is_redir);
	while (rdr)
	{
		rdr = rdr->next;
		while (rdr && string_equal(rdr->val, " "))
			rdr = rdr->next;
		if (!rdr)
		{
			__perror("parse error near token `newline\'");
			return (-1);
		}
		else if (is_redirection(rdr->val) && !is_quoted_token(shell->quoted_tokens, rdr))
		{
			__va_perror("parse error near token ", rdr->val, NULL);
			return (-1);
		}
		rdr = find_if(rdr->next, back(tokens), is_redir);
	}
	return (0);
}

int	pipe_parse(t_list *tokens, t_shell *shell)
{
	t_node	*pipe;
	t_node	*pair;

	if (!tokens)
		return (0);
	pipe = NULL;
	pipe = find_next_pipe(tokens->head, tokens, shell);
	if (pipe == tokens->head)
	{
		__perror("parse error near token `|\'");
		return (-1);
	}
	while (pipe)
	{
		pair = find_next_pipe(pipe->next, tokens, shell);
		if (!pair)
			pair = back(tokens);
		else
			pair = pair->prev;
		if (NULL == find_if(pipe->next, pair, not_space))
		{
			__perror("parse error near token `|\'");
			return (-1);
		}
		pipe = find_next_pipe(pair->next, tokens, shell);
	}
	return (0);
}
