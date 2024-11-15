/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/26 15:44:34 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_token(t_shell *shell, t_node *address)
{
	char	*val;

	val = __ptoa((size_t)address);
	set_insert(shell->quoted_tokens, val);
	free(val);
}

bool	is_quote_node(t_node *const node)
{
	return (is_quote(node->val));
}

void	mark_quoted_tokens(t_shell *shell, t_list *tokens)
{
	t_node	*left_quote;
	t_node	*right_quote;
	t_node	*token;

	if (empty(tokens))
		return ;
	left_quote = find_if(front(tokens), back(tokens), is_quote_node);
	if (!left_quote)
		return ;
	while (left_quote)
	{
		right_quote = find(left_quote->next, back(tokens), left_quote->val,
				string_equal);
		token = left_quote->next;
		while (token && token != right_quote)
		{
			save_token(shell, token);
			token = token->next;
		}
		pop(tokens, left_quote);
		left_quote = find_if(right_quote->next, back(tokens), is_quote_node);
		pop(tokens, right_quote);
	}
}

void	erase_quotes(t_list *tokens)
{
	t_node	*token;
	t_node	*pair;

	if (empty(tokens))
		return ;
	token = find_if(front(tokens), back(tokens), is_quote_node);
	while (token)
	{
		pair = find(token->next, back(tokens), token->val, string_equal);
		if (!pair)
			break ;
		pop(tokens, token);
		token = find_if(pair->next, back(tokens), is_quote_node);
		pop(tokens, pair);
	}
}
