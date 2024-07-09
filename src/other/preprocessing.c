/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 20:39:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list * __attribute__((warn_unused_result)) preprocess(t_list *tokens, t_shell * shell)
{
	if (!tokens || !shell) __exit("bad preprocessor values");

	t_node *token = tokens->head;

	while (token)
	{
		if (token->val[0] == '$')
		{
			resolve(token, shell);
		}

		token = token->next;
	}
	return tokens;
}
