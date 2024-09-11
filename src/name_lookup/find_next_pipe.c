/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:12:41 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/01 18:54:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *find_next_pipe(t_node *first, t_list *tokens, t_shell *shell)
{
	t_node *pipe = NULL;
	pipe = find(first, back(tokens), "|", string_equal);
	while (pipe && is_quoted_token(shell->quoted_tokens, pipe))
		pipe = find(pipe->next, back(tokens), "|", string_equal);

	return pipe;
}
