/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:08:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/12 18:32:58 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static void __quote_counter__(size_t *sum, char *s);
static void __dquote_counter__(size_t *sum, char *s);
static int quote_parse(t_list *tokens);
static bool not_space(t_node *node);
static int pipe_parse(t_list *tokens);

t_list * tokenize(char * raw_cmd)
{
	if (!raw_cmd) return NULL;

	t_list *tokens = make_list_from_string(raw_cmd, special_symbols, all);

	if (quote_parse(tokens) == -1 || pipe_parse(tokens) == -1)
	{
		list_clear(&tokens);
	}

	return tokens;
}

static int pipe_parse(t_list *tokens)
{
	if (!tokens) return 0;

	t_node *pipe = NULL;

	size_t pipes_count = count_range(tokens, "|");

	if (pipes_count == 0) return 0;

	pipe = find(tokens->head, tokens->tail, "|", string_equal);
	pipes_count--;

	while (pipes_count)
	{
		pipe = find(pipe->next, tokens->tail, pipe->val, string_equal);
		pipes_count--;
	}

	if (NULL == find_if(pipe->next, tokens->tail, not_space))
	{
		__perror("parse error near token \'|\'");
		return -1;
	}

	return 0;
}

static int quote_parse(t_list *tokens)
{
	if (!tokens) return 0;

	bool d = false;
	bool s = false;

	t_node *token = tokens->head;
	while (token)
	{
		if (!d && string_equal(token->val, "\'")) s = !s;
		if (!s && string_equal(token->val, "\"")) d = !d;

		token = token->next;
	}

	if (d || s)
	{
		if (d)
			__perror("parse error near token \"");
		else
			__perror("parse error near token \'");

		return -1;
	}

	return 0;
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

static bool not_space(t_node *node)
{
	return node && !string_equal(node->val, " ");
}
