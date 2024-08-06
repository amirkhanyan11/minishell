/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:18:19 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:49:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static t_node *__find(t_node *first, t_node *last, t_list_value target, t_list_Bpredicate_val cmp)
{
    if (!first || first->prev == last) return NULL;

    if (cmp(first->val, target) == true) return first;

    return __find(first->next, last, target, cmp);
}

// find an element in range [first, last]
t_node *find(t_node *first, t_node *last, t_list_value target, t_list_Bpredicate_val cmp)
{
    if (!first || !last) return NULL;

	if (!cmp) cmp = list_value_same;

    return __find(first, last, target, cmp);
}

// find an element in list { same as find(head, tail, t, cmp) }
t_node *find_range(t_list *list, t_list_value target, t_list_Bpredicate_val cmp)
{
	if (!list) return NULL;

	return find(list->head, list->tail, target, cmp);
}

t_node *find_strict(t_node *first, t_node *last, t_list_value target, t_list_Bpredicate_val cmp)
{
    t_node *res = find(first, last, target, cmp);

	scoped_string err = __make_string("bad strict find ", "(", target, ")");

	if (NULL == res) __exit(err);

	return res;
}
