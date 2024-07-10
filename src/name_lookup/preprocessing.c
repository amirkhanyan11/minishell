/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 22:05:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list * __result_use_check preprocess(t_list *tokens, t_shell * shell)
{
	if (!tokens || !shell) __exit("bad preprocessor values");

	t_node *token = tokens->head;

	while (token)
	{
		if (token->val[0] == '$')
		{
			resolve(token, shell);
		}
		// if (0 == __strcmp(token->val, "<"))
		// {

		// }
		token = token->next;
	}
	return tokens;
}
