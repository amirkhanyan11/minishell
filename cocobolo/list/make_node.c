/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:01:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:53:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

t_node * make_node(const t_list_value x)
{
	t_node *node = __malloc(sizeof(t_node));

	node->val = __strdup(x);
	node->next = NULL;
	node->prev = NULL;

	return node;
}

#pragma GCC diagnostic pop
