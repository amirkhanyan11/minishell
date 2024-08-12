/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:30:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/12 23:05:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void merge_redirections(t_list *tokens)
{
    if (!tokens) return;

    t_node *token = tokens->head;

    while (token && token->next)
    {
        t_node *next = token->next;

        if (is_single_redirection(token->val) && string_equal(token->val, token->next->val))
        {
            token->val = __strappend(token->val, token->next->val);
            next = token->next->next;
            pop(tokens, token->next);
        }
        token = next;
    }
}
