/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 17:05:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell * shell;

// handles redirections and $variables
t_list * __result_use_check preprocess(t_list *tokens, t_command *cmd)
{
	if (empty(tokens) || !shell) return NULL;

	dollar_sign_resolver(tokens);

	merge_tokens(tokens);
	
	// print_list(tokens);
	// return NULL;

	list_remove(tokens, " ");
	list_remove(tokens, "\'");
	list_remove(tokens, "\"");

	if (redirection_resolver(tokens, cmd) == -1) list_clear(&tokens);

	return tokens;
}
