/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:41:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/07 23:05:44 by aamirkha         ###   ########.fr       */
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