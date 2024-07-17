/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:41:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/17 19:12:54 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list * __attribute__((malloc)) __result_use_check make_list()
{
	t_list *list = __malloc(sizeof(t_list));

	list->head = NULL;
	list->tail = NULL;

	return list;
}

t_list *__attribute__((malloc)) __result_use_check make_list_from_matrix(char **arr)
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

t_list * __attribute__((malloc)) __result_use_check make_list_from_string(char *s, char *set, t_opcode opcode)
{
	char **arr = NULL;

	if (words_only == opcode)
		arr = __split(s, set);
	else if (all == opcode)
		arr = __split_include_delimiters(s, *set);

	t_list *list = make_list_from_matrix(arr);

	__matrix_clear(&arr);

	return list;
}

t_list * __attribute__((malloc)) __result_use_check make_list_copy(t_list *other, t_value_mutate f)
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

void	list_move_back(t_list *lhv, t_list *rhv)
{
	if (!lhv || !rhv || empty(lhv) || lhv == rhv) return ;


	if (empty(rhv))
	{
		*rhv = *lhv;
	}
	else
	{
		lhv->head->prev = rhv->tail;
		rhv->tail->next = lhv->head;
		rhv->tail = lhv->tail;
	}

	lhv->head = NULL;
	lhv->tail = NULL;
}

