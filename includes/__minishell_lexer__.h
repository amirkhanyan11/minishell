/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_lexer__.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:47:09 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/06 19:47:53 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_LEXER___H
#define __MINISHELL_LEXER___H

#include "minishell.h"

// parsing
t_list 		 *tokenize(char * raw_cmd) __result_use_check;
t_list 		 *preprocess(t_list *tokens, t_shell *shell) __result_use_check ;
void 		 dollar_sign_resolver(t_list *tokens, t_shell *shell);
int 		 redirection_resolver(t_list *tokens, t_command *cmd);
int 		 sort_tokens(t_command *cmd, t_list *tokens);

void 		 merge_tokens(t_list *tokens);
void 		 merge_redirections(t_list *tokens);

#endif // __MINISHELL_LEXER___H
