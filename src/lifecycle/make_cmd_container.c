/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_container.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:35:09 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 18:13:06 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_container *make_cmd_container(char * raw_cmd, t_shell *shell)
{
    scoped_list tokens = preprocess(tokenize(raw_cmd), shell);

	if (empty(tokens) || !shell) return NULL;

    t_cmd_container * cmds = __malloc(sizeof(t_cmd_container));

	cmds->current_cmd_index = 0;

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

        scoped_list partition = make_list_copy(first, pipe, NULL);

        cmds->arr[i] = make_command(partition, cmds, shell);

        first = pipe->next;
        i++;
    }
    return cmds;
}
