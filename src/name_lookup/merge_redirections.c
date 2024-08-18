/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:30:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:58:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void merge_redirections(t_list *tokens)
{
    if (!tokens) return;

    t_node *token = front(tokens);

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
