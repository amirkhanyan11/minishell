/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:49:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/07 16:50:36 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void __print_listnode__(t_node *const head)
{
	if (NULL == head) return;

	printf("%s\n", head->val);

	// if (head->next != NULL)
	// 	printf(" -> ");
	// else
	// 	printf("\n");
}

static void __print_listnode_enumerate__(t_node *const head, size_t n)
{
	if (NULL == head) return;

	printf("%ld  %s\n", n, head->val);

	__print_listnode_enumerate__(head->next, n + 1);

}

void print_list(t_list *list)
{
	if (NULL == list) return;
	preorder_traverse(list->head, __print_listnode__);
}


void print_list_enumerate(t_list *list)
{
	if (NULL == list) return;
	__print_listnode_enumerate__(list->head, 1);
}