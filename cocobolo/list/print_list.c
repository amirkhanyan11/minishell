/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:49:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 22:30:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void __print_listnode__(t_node *const head)
{
	if (head == NULL) return;

	printf("%d", head->val);

	if (head->next != NULL)
		printf(" -> ");
	else
		printf("\n");
}

void print_list(t_list *list)
{
	preorder_traverse(list->head, __print_listnode__);
}
