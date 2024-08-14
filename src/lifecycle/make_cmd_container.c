/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_container.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:35:09 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/14 21:19:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_container *make_cmd_container(char * raw_cmd, t_shell *shell)
{
    scoped_list tokens = preprocess(tokenize(raw_cmd), shell);

	if (empty(tokens) || !shell) return NULL;

    t_cmd_container * container = __malloc(sizeof(t_cmd_container));

	container->current_cmd_index = 0;

	container->shell = shell;

	container->size = count_range(tokens, "|") + 1;

    container->arr = __malloc(sizeof(t_command) * container->size);

	container->shell->container = container;

    size_t i = 0;

    t_node *first = tokens->head;
    while (i < container->size)
    {
        t_node *pipe = find(first, tokens->tail, "|", NULL);

        if (!pipe) pipe = tokens->tail;

        else
        {
            pipe = pipe->prev;
            pop(tokens, pipe->next);
        }

        scoped_list partition = make_list_copy(first, pipe, NULL);

        container->arr[i] = make_command(partition, container, shell);

        first = pipe->next;
        i++;
    }
    return container;
}
