/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:16:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 19:12:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	syntax_analysis(t_list *tokens, t_shell *shell)
{
	return (
		!empty(tokens) && parenthesis_parse(tokens, shell)
		&& keyword_parse(tokens,
			shell) && redirection_parse(tokens, shell)
	);
}
