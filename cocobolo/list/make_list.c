/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:41:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 21:44:57 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *make_list()
{
	t_list *list = __malloc(sizeof(t_list));

	list->head = NULL;
	list->tail = NULL;

	return list;
}
