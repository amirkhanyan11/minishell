/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:30:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:22:54 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list * make_path(t_shell *shell)
{
	if (!shell) return NULL;

	t_list *path = NULL;

	t_treeval path_val = get_val(shell->env, "PATH");

	if (!path_val) return NULL;

	path = make_list_from_string(path_val, ":", words_only);

	return path;
}
