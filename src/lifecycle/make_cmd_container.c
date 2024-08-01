/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_container.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:35:09 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 20:22:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_container * __result_use_check make_cmd_container(char * raw_cmd)
{
    a_list tokens = preprocess(tokenize(raw_cmd));

	if (empty(tokens)) return NULL;

    t_cmd_container * cmds = __malloc(sizeof(t_cmd_container));

    cmds->size = count_range(tokens, "|") + 1;
    
    cmds->arr = __malloc(sizeof(t_command) * cmds->size);

    size_t i = 0;

    t_node *first = tokens->head;
    while (i < cmds->size)
    {
        t_node *pipe = find(first, tokens->tail, "|", NULL);

        if (!pipe) pipe = tokens->tail;

        else
        {
            pipe = pipe->prev;
            pop(tokens, pipe->next);
        }

        a_list partition = make_list_copy(first, pipe, NULL);

        cmds->arr[i] = make_command(partition);

        first = pipe->next;
        i++;
    }
    return cmds;
}
