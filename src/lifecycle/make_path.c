/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:30:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/16 18:31:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list * __result_use_check make_path(t_shell *shell)
{
	if (!shell) return NULL;

	t_list *path = NULL;

	t_list_value raw_path = find_range(shell->env, "PATH", list_value_contains)->val;

	t_matrix __dtor(__matrix_clear) arr = __split(raw_path, ':');

	char *ptr = arr[0];
	while (*ptr && *ptr != '=') ptr++;

	ptr = __strdup(ptr + 1);
	free(arr[0]);
	arr[0] = ptr;

	// __print_matrix(arr);

	path = make_list_from_matrix(arr);

	return path;
}
