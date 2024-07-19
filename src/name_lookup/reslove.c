/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reslove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:27:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/19 18:10:01 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void resolve(t_node *t, t_list *tokens)
{
	char *val = NULL;

	if (0 == __strcmp(t->val, "$?"))
	{
		val = __itoa(shell->status);
	}

	else
	{
		val = get_value(shell->export, t->val + 1);

		if (val == NULL)
		{
			pop(tokens, t);
			return;
		}
	}

	free(t->val);
	t->val = val;
}
