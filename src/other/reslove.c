/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reslove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:27:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 21:37:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void resolve(t_node *token, t_shell *shell)
{
	char *val = pick(shell->export, token->val + 1);

	free(token->val);
	
	token->val = val;
}
