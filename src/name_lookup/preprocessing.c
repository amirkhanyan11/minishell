/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 21:08:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles redirections and $variables
t_list * __result_use_check preprocess(t_list *tokens, t_shell *shell)
{
	if (empty(tokens) || !shell) return NULL;

	dollar_sign_resolver(tokens, shell);

	merge_tokens(tokens);

	list_remove(tokens, " ");
	list_remove(tokens, "\'");
	list_remove(tokens, "\"");

	return tokens;
}
