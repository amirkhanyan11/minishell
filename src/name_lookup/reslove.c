/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reslove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:27:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 17:12:40 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void resolve(t_node *t, t_list *tokens)
{
	char *val = get_value(shell->export, t->val + 1);

	if (val == NULL)
	{
		list_remove(tokens, t);
		return;
	}

	free(t->val);

	t->val = val;
}
