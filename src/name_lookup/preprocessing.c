/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/20 00:52:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell * shell;

// handles redirections and $variables
t_list * __result_use_check preprocess(t_list *tokens)
{
	if (empty(tokens) || !shell) return NULL;

	dollar_sign_resolver(tokens);
	
	merge_tokens(tokens); // comes after preprocessing in bash

	list_remove(tokens, " ");
	list_remove(tokens, "\'");
	list_remove(tokens, "\"");


	// print_list(tokens);
	// return NULL;

	if (redirection_resolver(tokens) == -1) list_clear(&tokens);
	
	return tokens;
}
