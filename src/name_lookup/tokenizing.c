/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:08:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:24:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static void __quote_counter__(size_t *sum, char *s);
static void __dquote_counter__(size_t *sum, char *s);
static int quote_parse(t_list *tokens);

t_list * tokenize(char * raw_cmd)
{
	if (!raw_cmd) return NULL;

	t_list *tokens = make_list_from_string(raw_cmd, "<>| \'\"", all);

	if (quote_parse(tokens) == -1)
	{
		list_clear(&tokens);
		__exit("parse error near quote token");
	}

	return tokens;
}

static int quote_parse(t_list *tokens)
{
	if (!tokens) return 0;

	bool d = false;
	bool s = false;

	t_node *token = tokens->head;
	while (token)
	{
		if (!d && list_value_same(token->val, "\'")) s = !s;
		if (!s && list_value_same(token->val, "\"")) d = !d;

		token = token->next;
	}
	return (!d && !s) ? 0 : -1;
}

static void __quote_counter__(size_t *sum, char *s)
{
	if (!sum || !s) return ;

	while (*s)
	{
		if (*s == '\'') (*sum)++;
		++s;
	}
}

static void __dquote_counter__(size_t *sum, char *s)
{
	if (!sum || !s) return ;

	while (*s)
	{
		if (*s == '\"') (*sum)++;
		++s;
	}
}
