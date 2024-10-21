/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/21 20:15:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles redirections and $variables
t_list	*preprocess(t_list *tokens, t_shell *shell)
{
	if (empty(tokens) || !shell)
		return (NULL);
	dollar_sign_resolver(tokens, shell);
	merge_tokens(shell, tokens);
	remove_spaces(shell, tokens);
	recover_variables(tokens, shell);
	if (!syntax_analysis(tokens, shell))
	{
		if (!empty(tokens))
			set_exit_status_no_of(258);
		else
			set_exit_status_no_of(0);
		list_clear(&tokens);
	}
	else if (count_range(tokens, "<<") > HEREDOC_MAX)
	{
		list_clear(&tokens);
		__t_shell__(shell);
		__perror("maximum here-document count exceeded");
		exit(2);
	}
	return (tokens);
}
