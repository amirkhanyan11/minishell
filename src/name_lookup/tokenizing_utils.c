/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:29:11 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/21 21:18:14 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_parse(t_list *tokens)
{
	bool	d;
	bool	s;
	t_node	*token;

	d = false;
	s = false;
	token = tokens->head;
	while (token)
	{
		if (!d && string_equal(token->val, "\'"))
			s = !s;
		if (!s && string_equal(token->val, "\""))
			d = !d;
		token = token->next;
	}
	if (d || s)
	{
		if (d)
			__perror("parse error near token \"");
		else
			__perror("parse error near token \'");
		return (-1);
	}
	return (0);
}

int	parenthesis_parse(t_list *tokens, t_shell *shell)
{
	int count = 0;
	t_node *token = tokens->head;
 	while(token)
	{
		if(is_opening_parenthesis_token(token, shell))
			count++;
		else if(is_closing_parenthesis_token(token, shell))
			count--;
		if(count <= -1)
			return -1;
		token = token->next;
	}
	if(count != 0) return -1;
	return 0;
}

bool	not_space(t_node *node)
{
	return (node && !string_equal(node->val, " "));
}

bool	is_redir(t_node *node)
{
	return (node && is_redirection(node->val));
}

bool is_wildcard(t_node *node)
{
	// return(__strchr(node->val, '*'));
	return(__strchr(node->val, '*'));
}

bool is_not_wildcard(t_node *node)
{
	// return(__strchr(node->val, '*'));
	return(!string_equal(node->val, "*"));
}
