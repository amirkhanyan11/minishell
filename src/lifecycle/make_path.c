/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:30:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 20:04:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list * __result_use_check make_path(t_shell *shell)
{
	if (!shell) return NULL;

	t_list *path = NULL;

	t_list_value raw_path = find_strict(shell->env, "PATH", list_value_contains)->val;

	t_matrix arr = __split(raw_path, ':');

	char *ptr = arr[0];
	while (*ptr && *ptr != '=') ptr++;

	ptr = __strdup(ptr + 1);
	free(arr[0]);
	arr[0] = ptr;

	path = make_list_from_matrix(arr);

	__matrix_clear(&arr);

	return path;
}
