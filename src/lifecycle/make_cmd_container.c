/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_container.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:35:09 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:11:32 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list *make_partition(t_shell *shell, t_node *first, t_node *last);
static void make_cmds(t_cmd_container *container, t_shell *shell, t_list *tokens);

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

	make_cmds(container, shell, tokens);

    return container;
}


static void make_cmds(t_cmd_container *container, t_shell *shell, t_list *tokens)
{
    size_t i = 0;

    t_node *first = front(tokens);
    while (i < container->size)
    {
        t_node *pipe = find(first, back(tokens), "|", NULL);

        if (!pipe) pipe = back(tokens);

        else
        {
            pipe = pipe->prev;
            pop(tokens, pipe->next);
        }

        scoped_list partition = make_partition(shell, first, pipe);

        container->arr[i] = make_command(partition, container, shell);

        first = pipe->next;
        i++;
    }
}

static t_list *make_partition(t_shell *shell, t_node *first, t_node *last)
{
	if (!shell || !first || !last) return NULL;

	t_list *list = make_list();
	t_node *curr = first;

	while (curr && curr->prev != last)
	{
		push_back(list, curr->val);
		if (is_quoted_token(shell->quoted_tokens, curr))
		{
			save_token(shell, back(list));
		}
		curr = curr->next;
	}
	return list;
}
