/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:19:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 17:53:06 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void __quote_counter__(size_t *sum, char *s);
static void __dquote_counter__(size_t *sum, char *s);

t_list * __result_use_check tokenize(char * raw_cmd)
{
	if (!raw_cmd) __exit("empty command");

	t_list *tokens = make_list_from_string(raw_cmd, " \'\"", all);

	if (count_range(tokens, "\'") % 2 != 0 || count_range(tokens, "\"") % 2 != 0)
	{
		list_clear(&tokens);
		return NULL;
	}

	return tokens;
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
