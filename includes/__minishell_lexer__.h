/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_lexer__.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:47:09 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/19 21:14:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_LEXER___H
# define __MINISHELL_LEXER___H

# include "minishell.h"

// parsing
t_list	*tokenize(char *raw_cmd) __attribute__((warn_unused_result));
t_list	*preprocess(t_list *tokens, t_shell *shell)
		__attribute__((warn_unused_result));
void	dollar_sign_resolver(t_list *tokens, t_shell *shell);
int		redirection_resolver(t_list *tokens, t_command *cmd);
int		sort_tokens(t_command *cmd, t_list *tokens);

void merge_tokens(t_shell *shell, t_list *tokens);
void	merge_redirections(t_list *tokens);

#endif // __MINISHELL_LEXER___H
