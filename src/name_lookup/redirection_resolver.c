/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:32:15 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 13:56:16 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// delete the file????

// int redirection_resolver(t_list *tokens, t_command *cmd)
// {
//     t_node *token = front(tokens);

// 	while (token)
// 	{
// 		t_node *next = token->next;

// 		if (string_equal(token->val, "<") || string_equal(token->val, ">") || string_equal(token->val, ">>"))
// 		{
// 			if (-1 == redirect(token, cmd)) return -1;

// 			t_node *next = token->next->next;
// 			pop(tokens, token->next);
// 			pop(tokens, token); // erase
// 			token = next;
// 			continue;
// 		}
// 		token = next;
// 	}
//     return 0;
// }
