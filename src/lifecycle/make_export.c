/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:40:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 20:04:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *add_declarex(char *s);

t_list * __result_use_check make_export(t_shell *shell)
{
	if (!shell) return NULL;

    return make_list_copy(shell->env, add_declarex);
}

static char *add_declarex(char *s)
{
	if (!s) return NULL;

	return __strappend(__make_string_empty(), "declare -x ", s);
}
