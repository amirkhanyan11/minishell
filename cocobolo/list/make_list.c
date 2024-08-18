/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:41:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:53:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

t_list *make_list()
{
	t_list *list = __malloc(sizeof(t_list));

	list->head = NULL;
	list->tail = NULL;

	return list;
}

t_list * make_list_from_matrix(char **arr)
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

t_list *make_list_from_string(char *s, char *set, t_opcode opcode)
{
	scoped_matrix arr = NULL;

	if (words_only == opcode)
	{
		arr = __split(s, set);
		return make_list_from_matrix(arr);
	}

	t_list   *list = make_list();

	while (*s)
	{
		if (__strchr(set, *s) == true)
		{
			scoped_string val = __make_string_from_char(*s);
			push_back(list, val);
			++s;
		}

		else
		{
			char *tmp = s + 1;
			while (*tmp && __strchr(set, *tmp) == false) tmp++;
			scoped_string val = __strdup_until(s, *tmp);
			push_back(list, val);
			s = tmp;
		}

	}

	return list;

}

t_list *make_list_copy_range(t_list *other, t_value_mutate f)
{
	if (!other) return NULL;

	return (make_list_copy(other->head, other->tail, f));
}

t_list *  make_list_copy(t_node *first, t_node *last, t_value_mutate f)
{
	t_list *list = make_list();

	while (first && first->prev != last)
	{
		if (f == NULL)
		{
			push_back(list, first->val);
		}
		else
		{
			t_list_value val = f(first->val);
			push_back(list, val);
			free(val);
		}
		first = first->next;
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

#pragma GCC diagnostic pop
