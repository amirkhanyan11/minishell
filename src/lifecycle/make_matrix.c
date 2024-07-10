/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 20:04:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// move to separate dir
t_matrix __result_use_check  make_matrix_from_string(char *s, char c)
{
	return __split(s, c);
}

t_matrix  __result_use_check make_matrix_copy(t_matrix other)
{
	if (!other) return NULL;

	size_t i = 0;
	while (other[i]) i++;

	t_matrix res = malloc(i + 1);
	res[i] = NULL;

	i = 0;
	while(other[i])
	{
		res[i] = __strdup(other[i]);
		i++;
	}
	return res;
}

t_matrix  __result_use_check make_matrix_from_list(t_list *list)
{
	if (!list) return NULL;

	size_t lstsize = size(list);

	t_matrix arr = __malloc(sizeof(char *) * (lstsize + 1));

	arr[lstsize] = NULL;

	t_node *node = list->head;
	size_t i = 0;
	while (node)
	{
		arr[i] = __strdup(node->val);
		node = node->next;
		i++;
	}

	return arr;
}
