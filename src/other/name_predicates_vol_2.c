/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates_vol_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:26:29 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/21 21:11:07 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redirection(const char *val)
{
	return (string_equal(val, "<") || string_equal(val, ">")
		|| string_equal(val, "<<") || string_equal(val, ">>"));
}
bool	is_quote(char *s)
{
	return (string_equal(s, "\'") || string_equal(s, "\""));
}

bool	is_name(char *s)
{
	if (!s || (*s != '_' && !is_alpha(*s)))
		return (false);
	++s;
	while (*s)
	{
		if (!is_name_part(*s))
			return (false);
		++s;
	}
	return (true);
}
bool	not_name_part(char c)
{
	return (!is_name_part(c));
}

bool	is_opening_parenthesis_token(t_node * token, t_shell * shell)
{
	return (!is_quoted_token(shell->quoted_tokens, token) && is_opening_parenthesis(token->val));
}
bool	is_closing_parenthesis_token(t_node * token, t_shell * shell)
{
	return (!is_quoted_token(shell->quoted_tokens, token) && is_closing_parenthesis(token->val));
}

bool	is_opening_parenthesis(char *text)
{
	return(string_equal(text, "("));
}
bool	is_closing_parenthesis(char *text)
{
	return(string_equal(text, ")"));
}
