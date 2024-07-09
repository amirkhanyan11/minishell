/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:41:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 20:02:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list * __attribute__((malloc)) make_list()
{
	t_list *list = __malloc(sizeof(t_list));

	list->head = NULL;
	list->tail = NULL;

	return list;
}

t_list *__attribute__((malloc)) make_list_from_matrix(char **arr)
{
	if (NULL == arr) __exit("nullptr passed to make_list_from_matrix");

	t_list * list = make_list();
	size_t i = 0;

	while (arr[i])
	{
		push_back(list, arr[i]);
		i++;
	}
	return list;
}

t_list * __attribute__((malloc)) make_list_from_string(char *s, const char c)
{
	char **arr = __split(s, c);

	t_list *list = make_list_from_matrix(arr);

	__matrix_clear(&arr);

	return list;
}

t_list * __attribute__((malloc)) make_list_copy(t_list *other, t_value_mutate f)
{
	if (!other) return NULL;

	t_node *node = other->head;
	t_list *list = make_list();

	while (node)
	{
		if (f == NULL)
		{
			push_back(list, node->val);
		}
		else
		{
			t_list_value val = f(node->val);
			push_back(list, val);
			free(val);
		}
		node = node->next;
	}

	return list;
}
