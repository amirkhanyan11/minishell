/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:40:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 17:04:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree * __result_use_check make_export(t_shell *shell)
{
	if (!shell) return NULL;

    return make_tree_copy(shell->env);
}
