/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:08:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:45:50 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static void __quote_counter__(size_t *sum, char *s);
static void __dquote_counter__(size_t *sum, char *s);
static int quote_parse(t_list *tokens);
static bool not_space(t_node *node);
static bool is_redir(t_node * const node);



t_list * tokenize(char * raw_cmd)
{
	if (!raw_cmd) return NULL;

	t_list *tokens = make_list_from_string(raw_cmd, SPECIAL_SYMBOLS, all);

	if (quote_parse(tokens) == -1)
	{
		set_exit_status(2);
		list_clear(&tokens);
	}

	return tokens;
}

int redirection_parse(t_list *tokens)
{
	if (!tokens) return 0;

	t_node *rdr = NULL;

	rdr = find_if(front(tokens), back(tokens), is_redir);

	while (rdr)
	{
		rdr = rdr->next;

		while (rdr && string_equal(rdr->val, " ")) rdr = rdr->next;

		if (!rdr)
		{
			__perror("parse error near token `newline\'");
			return -1;
		}

		else if (is_redirection(rdr->val))
		{
			scoped_string err = __make_string("parse error near token ", rdr->val);
			__perror(err);
			return -1;
		}
		rdr = find_if(rdr->next, back(tokens), is_redir);
	}

	return 0;
}


int pipe_parse(t_list *tokens)
{
	if (!tokens) return 0;

	t_node *pipe = NULL;

	pipe = find(front(tokens), back(tokens), "|", string_equal);

	while (pipe)
	{
		t_node *pair = find(pipe->next, back(tokens), "|", string_equal);

		if (!pair) pair = back(tokens);

		else pair = pair->prev;

		if (NULL == find_if(pipe->next, pair, not_space))
		{
			__perror("parse error near token `|\'");
			return -1;
		}

		pipe = find(pair->next, back(tokens), "|", string_equal);
	}

	return 0;
}

static int quote_parse(t_list *tokens)
{
	if (!tokens) return 0;

	bool d = false;
	bool s = false;

	t_node *token = front(tokens);
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

static bool is_redir(t_node * node)
{
	return node && is_redirection(node->val);
}
