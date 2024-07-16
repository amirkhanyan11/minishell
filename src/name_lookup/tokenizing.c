/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:19:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/16 22:42:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void __quote_counter__(size_t *sum, char *s);
static void __dquote_counter__(size_t *sum, char *s);
static int  quote_validator(const char c, size_t *count, size_t n, t_list *stack);
static int  quote_parser(t_list *tokens);

t_list * __result_use_check tokenize(char * raw_cmd)
{
	if (!raw_cmd) __exit("empty command");

	// return make_list_from_string(raw_cmd, ' ', all);
	t_list *tokens =  make_list_from_string(raw_cmd, ' ', words_only);

	if (-1 == quote_parser(tokens)) list_clear(&tokens);

	return tokens;

}

static int quote_validator(const char c, size_t *count, size_t n, t_list *stack)
{
	if ((*count) < n / 2)
	{
		string s = __make_string_from_char(c);
		push_front(stack, s);
		(*count)++;
	}

	else
	{
		if (empty(stack) || *(stack->head->val) != c) return -1;
		pop_front(stack);
	}

	return 0;
}

// wrong 
int quote_parser(t_list *tokens)
{
	if (!tokens) return -1;

	size_t squotes = accumulate(tokens, 0, __quote_counter__);

	size_t dquotes = accumulate(tokens, 0, __dquote_counter__);

	if (squotes % 2 != 0 || dquotes % 2 != 0) return -1;

	a_list stack = make_list();

	size_t scount = 0;
	size_t dcount = 0;

	t_node *head = tokens->head;

	while (head)
	{
		char *t = head->val;

		while (*t)
		{
			if (*t == '\'' || *t == '\"')
			{

				size_t *count = &scount;
				size_t n = squotes;

				if (*t == '\"')
				{
					count = &dcount;
					n = dquotes;
				}

				if (quote_validator(*t, count, n, stack) == -1) return -1;

			}
			++t;
		}

		head = head->next;
	}

	// printf("good quotes\n");

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
